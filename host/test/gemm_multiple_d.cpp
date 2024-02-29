#include "ck/host/device_gemm_multiple_d/problem.hpp"
#include "ck/host/device_gemm_multiple_d/operation.hpp"
#include "ck/host/conv/conv_op.hpp"
#include "ck/host/conv/dev_conv.hpp"
#include "ck/host/headers.hpp"
#include "ck/host/stringutils.hpp"
#include "ck/host/types.hpp"
#include "ck/host/utils.hpp"
#include "ck/utility/common_header.hpp"
#include "ck/utility/math_v2.hpp"
#include "ck/tensor_operation/gpu/device/impl/device_grouped_conv_fwd_multiple_abd_xdl_cshuffle.hpp"
#include "ck/tensor_description/tensor_descriptor.hpp"
#include "ck/tensor_description/tensor_descriptor_helper.hpp"
#include "ck/tensor_operation/gpu/device/tensor_layout.hpp"
#include "ck/tensor_operation/gpu/device/convolution_forward_specialization.hpp"
#include "ck/tensor_operation/operator_transform/transform_conv_fwd_to_gemm.hpp"
#include "ck/tensor_operation/gpu/device/device_grouped_conv_fwd_multiple_abd.hpp"
#include "ck/tensor_operation/gpu/device/gemm_specialization.hpp"
#include "ck/tensor_operation/gpu/device/matrix_padder.hpp"
#include "ck/tensor_operation/gpu/grid/gridwise_gemm_multiple_d_xdl_cshuffle.hpp"
#include "ck/tensor_operation/gpu/grid/gridwise_gemm_multiple_abd_xdl_cshuffle.hpp"
#include "ck/tensor_operation/gpu/device/impl/device_grouped_conv_utils.hpp"
#include "ck/host_utility/device_prop.hpp"
#include "ck/host_utility/kernel_launch.hpp"
#include "ck/host_utility/io.hpp"
//#include "ck/host/tuples.hpp"
//#include "ck/host/seq.hpp"
//#include "ck/host/tensor_desc.hpp"
//#include "ck/host/transform.hpp"
#include <algorithm>
#include <cmath>
#include <iterator>
#include <numeric>
#include <random>
#include <test.hpp>
#include <rtc/compile_kernel.hpp>
#include <rtc/hip.hpp>
#include <fstream>

// using half = _Float16;
// using half = __fp16;

std::vector<rtc::src_file> get_headers_for_test()
{
    std::vector<rtc::src_file> result;
    auto hs = ck::host::GetHeaders();
    std::transform(
        hs.begin(), hs.end(), std::back_inserter(result), [&](const auto& p) -> rtc::src_file {
            auto s = p.second;
            std::string content{s.first, s.second};
            return {p.first, content};
        });
    return result;
}

template <class T>
rtc::buffer<T> generate_buffer(std::size_t n, std::size_t seed = 0)
{
    rtc::buffer<T> result(n);
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(-1.0);
    std::generate(result.begin(), result.end(), [&] { return dis(gen); });
    return result;
}

template <class T, class U>
bool allclose(const T& a, const U& b, double atol = 0.01, double rtol = 0.01)
{
    return std::equal(a.begin(), a.end(), b.begin(), b.end(), [&](double x, double y) {
        return fabs(x - y) < atol + rtol * fabs(y);
    });
}

std::string classify(double x)
{
    switch(std::fpclassify(x))
    {
    case FP_INFINITE: return "inf";
    case FP_NAN: return "nan";
    case FP_NORMAL: return "normal";
    case FP_SUBNORMAL: return "subnormal";
    case FP_ZERO: return "zero";
    default: return "unknown";
    }
}

template <class Buffer>
void print_classification(const Buffer& x)
{
    std::unordered_set<std::string> result;
    for(const auto& i : x)
        result.insert(classify(i));
    for(const auto& c : result)
        std::cout << c << ", ";
    std::cout << std::endl;
}

template <class Buffer>
void print_statistics(const Buffer& x)
{
    std::cout << "Min value: " << *std::min_element(x.begin(), x.end()) << ", ";
    std::cout << "Max value: " << *std::max_element(x.begin(), x.end()) << ", ";
    double num_elements = x.size();
    auto mean =
        std::accumulate(x.begin(), x.end(), double{0.0}, std::plus<double>{}) / num_elements;
    auto stddev = std::sqrt(
        std::accumulate(x.begin(),
                        x.end(),
                        double{0.0},
                        [&](double r, double v) { return r + std::pow((v - mean), 2.0); }) /
        num_elements);
    std::cout << "Mean: " << mean << ", ";
    std::cout << "StdDev: " << stddev << "\n";
}

template <class Buffer>
void print_preview(const Buffer& x)
{
    if(x.size() <= 10)
    {
        std::for_each(x.begin(), x.end(), [&](double i) { std::cout << i << ", "; });
    }
    else
    {
        std::for_each(x.begin(), x.begin() + 5, [&](double i) { std::cout << i << ", "; });
        std::cout << "..., ";
        std::for_each(x.end() - 5, x.end(), [&](double i) { std::cout << i << ", "; });
    }
    std::cout << std::endl;
}

template <class T>
struct check_all
{
    rtc::buffer<T> data{};
    bool operator()(const rtc::buffer<T>& x)
    {
        if(data.empty())
        {
            data = x;
            return true;
        }
        return allclose(data, x);
    }
};

template <class Solution>
auto report(const Solution& solution, bool pass)
{
    return test::make_predicate(solution.ToTemplateString(), [=] { return pass; });
}

/**#define ToLayout(lay_out,x){ \
        if(lay_out == "ck::tensor_layout::gemm::RowMajor"){\
                ck::tensor_layout::gemm::RowMajor layout ;\
                x = layout;\
        }else{\
                ck::tensor_layout::gemm::ColumnMajor layout ;\
                x = layout;\
        }\
}**/
/**auto to_layout(std::string layout){
        if(layout == "ck::tensor_layout::gemm::RowMajor"){
                return ck::tensor_layout::gemm::RowMajor{};
        }else{
                return ck::tensor_layout::gemm::ColumnMajor{};
        }
        return -1;
}**/

struct Prologue
{
    Prologue(float alpha, float beta) : alpha_(alpha), beta_(beta){};

    template <typename E, typename C, typename D>
    __host__ __device__ constexpr void operator()(E& e, const C& c, const D& d) const;

    template <>
    __host__ __device__ constexpr void operator()<ck::half_t, float, ck::half_t>(
        ck::half_t& e, const float& c, const ck::half_t& d) const
    {
        e = ck::type_convert<ck::half_t>(alpha_ * c + beta_ * ck::type_convert<float>(d));
    };

    float alpha_;
    float beta_;
};

const std::string conv_compile_check = R"__ck__(
#include <${include}>

${template};

)__ck__";

TEST_CASE(test_problem_kernel)
{
    ck::host::conv::Problem_Conv prob;
    prob.G  = 4;
    prob.N  = 64;
    prob.C  = 32;
    prob.K  = 32;
    prob.Y  = 3;
    prob.X  = 3;
    prob.Hi = 32;
    prob.Wi = 32;
    prob.Ho = 32;
    prob.Wo = 32;
    check_all<half> check;
    auto a               = to_gpu(generate_buffer<half>(64 * 64, 0));
    auto b               = to_gpu(generate_buffer<half>(64 * 64, 1));
    auto c               = to_gpu(generate_buffer<half>(64 * 64, 2));
    std::string prologue = R"(struct Prologue
{
    Prologue(float alpha, float beta) : alpha_(alpha), beta_(beta){};

    template <typename E, typename C, typename D>
    __host__ __device__ constexpr void operator()(E& e, const C& c, const D& d) const;

    template <>
    __host__ __device__ constexpr void operator()<ck::half_t, float, ck::half_t>(
        ck::half_t& e, const float& c, const ck::half_t& d) const
    {
        e = ck::type_convert<ck::half_t>(alpha_ * c + beta_ * ck::type_convert<float>(d));
    };

    float alpha_;
    float beta_;
};
)";
    std::string epilogue = "";

    static constexpr auto I0 = ck::Number<0>{};
    static constexpr auto I1 = ck::Number<1>{};
    static constexpr auto I2 = ck::Number<2>{};
    static constexpr auto I3 = ck::Number<3>{};

    using CDEElementOp = Prologue;

    using DeviceConv = ck::tensor_operation::device::DeviceGroupedConvFwdMultipleABD_Xdl_CShuffle<
        5,
        ck::tensor_layout::gemm::RowMajor,
        ck::tensor_layout::gemm::RowMajor,
        ck::Tuple<>,
        ck::tensor_layout::gemm::RowMajor,
        ck::half_t,
        ck::half_t,
        float,
        ck::half_t,
        ck::Tuple<>,
        ck::half_t,
        ck::tensor_operation::element_wise::PassThrough,
        ck::tensor_operation::element_wise::PassThrough,
        ck::tensor_operation::element_wise::PassThrough, // FIXME: replace with prologue
        ck::tensor_operation::device::ConvolutionForwardSpecialization::Default,
        ck::tensor_operation::device::GemmSpecialization::Default,
        1,
        256,
        256,
        128,
        32,
        8,
        8,
        32,
        32,
        4,
        2,
        ck::Sequence<4, 64, 1>,
        ck::Sequence<0, 2, 1>,
        ck::Sequence<0, 2, 1>,
        1,
        2,
        8,
        1,
        ck::Sequence<4, 64, 1>,
        ck::Sequence<1, 0, 2>,
        ck::Sequence<1, 0, 2>,
        2,
        8,
        8,
        1,
        1,
        1,
        ck::Sequence<1, 32, 1, 8>,
        8>;

    // length+stride arrays
    std::array<ck::index_t, 5> in_lengths{static_cast<int>(prob.G),
                                          static_cast<int>(prob.N),
                                          static_cast<int>(prob.C),
                                          static_cast<int>(prob.Hi),
                                          static_cast<int>(prob.Wi)};
    std::array<ck::index_t, 5> out_lengths{static_cast<int>(prob.G),
                                           static_cast<int>(prob.N),
                                           static_cast<int>(prob.K),
                                           static_cast<int>(prob.Ho),
                                           static_cast<int>(prob.Wo)};
    std::array<ck::index_t, 5> wei_lengths{static_cast<int>(prob.G),
                                           static_cast<int>(prob.K),
                                           static_cast<int>(prob.C),
                                           static_cast<int>(prob.Y),
                                           static_cast<int>(prob.X)};
    std::array<ck::index_t, 5> d_lengths = {};

    std::array<ck::index_t, 5> in_strides{static_cast<int>(prob.C),
                                          static_cast<int>(prob.Hi * prob.Wi * prob.G * prob.C),
                                          1,
                                          static_cast<int>(prob.Wi * prob.G * prob.C),
                                          static_cast<int>(prob.G * prob.C)};
    std::array<ck::index_t, 5> out_strides{static_cast<int>(prob.K),
                                           static_cast<int>(prob.Ho * prob.Wo * prob.G * prob.K),
                                           1,
                                           static_cast<int>(prob.Wo * prob.G * prob.K),
                                           static_cast<int>(prob.G * prob.K)};
    std::array<ck::index_t, 5> wei_strides{static_cast<int>(prob.K * prob.Y * prob.X * prob.C),
                                           static_cast<int>(prob.Y * prob.X * prob.C),
                                           1,
                                           static_cast<int>(prob.X * prob.C),
                                           static_cast<int>(prob.C)};
    std::array<ck::index_t, 5> d_strides = {};

    std::array<ck::index_t, 2> conv_filter_strides   = {2, 2};
    std::array<ck::index_t, 2> conv_filter_dilations = {1, 1};
    std::array<ck::index_t, 2> input_left_pads       = {1, 1};
    std::array<ck::index_t, 2> input_right_pads      = {1, 1};

    // FIXME: populate arg call properly
    auto arg =
        DeviceConv::Argument(in_device_buf.GetDeviceBuffer(),
                              wei_device_buf.GetDeviceBuffer(),
                              std::array<const void*, 0>{},
                              out_device_buf.GetDeviceBuffer(), // TODO: add in dev buf calls
                              in_lengths,
                              in_strides,
                              wei_lengths,
                              wei_strides,
                              std::array<std::array<ck::index_t, 5>, 0>{},
                              std::array<std::array<ck::index_t, 5>, 0>{},
                              out_lengths,
                              out_strides,
                              conv_filter_strides,
                              conv_filter_dilations,
                              input_left_pads,
                              input_right_pads,
                              InElementOp{},
                              WeiElementOp{},
                              CDEElementOp{});

    for(auto solution : prob.GetSolutions("gfx908", prologue, epilogue))
    {
        auto src = ck::host::InterpolateString(
            conv_compile_check,
            {{"include", prob.GetIncludeHeader()},
             {"template", solution.ToTemplateString()},
             {"m", std::to_string(prob.G)},
             {"n", std::to_string(prob.N)},
             {"k", std::to_string(prob.C)}}); // FIXME: pass in the right dims

        std::ofstream ofh("kernel.txt");
        ofh << "##########################################################\n";
        ofh << solution.ToTemplateString();
        ofh << "##########################################################\n";
        ofh.close();

        auto srcs = get_headers_for_test();
        srcs.push_back({"main.cpp", src});
        rtc::compile_options options;
        options.kernel_name = "f";
        auto k              = rtc::compile_kernel(srcs, options);
        auto block_size     = solution.GetTemplateParameter<std::size_t>("BlockSize");
        auto m_per_block    = solution.GetTemplateParameter<ck::index_t>("MPerBlock");
        auto n_per_block    = solution.GetTemplateParameter<ck::index_t>("NPerBlock");
        auto k_per_block    = solution.GetTemplateParameter<ck::index_t>("KPerBlock");
        // auto a_layout       =
        // solution.GetTemplateParameter<ck::tensor_layout::convolution::NHWGC>("ALayout");
        auto grid_size = ck::host::integer_divide_ceil(prob.G, m_per_block) *
                         ck::host::integer_divide_ceil(prob.N, n_per_block); // FIXME

        // auto A_Layout = ToLayout(a_layout);
        auto conv_to_gemm_transformer = ck::tensor_operation::TransformConvFwdToGemm<2, ConvSpec>{};

        auto matrix_padder = ck::tensor_operation::device::
            MatrixPadder<GemmSpec, ck::index_t, ck::index_t, ck::index_t>{
                m_per_block, n_per_block, k_per_block};

        // FIXME: how to pass layout?? remove hardcoding
        using ALayout = ck::tensor_layout::convolution::NHWGC;
        using BLayout = ck::tensor_layout::convolution::GKYXC;
        using CLayout = ck::tensor_layout::convolution::NHWGK;


        k.launch(nullptr, grid_size * block_size, block_size)(
                        arg.p_as_grid_.At(I0), // Pass just A descriptor instead of tuple
                        arg.p_bs_grid_.At(I0), // Pass just B descriptor instead of tuple
                        arg.p_ds_grid_,
                        arg.p_e_grid_,
                        arg.a_element_op_,
                        arg.b_element_op_,
                        arg.cde_element_op_,
                        arg.a_g_n_c_wis_lengths_[0], // Group count
                        arg.a_grid_desc_ak0_m_ak1_,
                        arg.b_grid_desc_bk0_n_bk1_,
                        arg.ds_grid_desc_mblock_mperblock_nblock_nperblock_,
                        arg.e_grid_desc_mblock_mperblock_nblock_nperblock_,
                        arg.block_2_etile_map_,
                        arg.compute_ptr_offset_of_batch_
            ); // FIXME: my launch will bw different: will need
                                   // to pass in grid ptrs for run fcns
        CHECK(report(solution, check(rtc::from_gpu(c))));
    }
}
/**const std::string gemm_compile_check = R"__ck__(
#include <${include}>

extern "C" __global__ void f(const ck::half_t* a, const ck::half_t* b, ck::half_t* c) {
    using G = ${template};
    constexpr auto desc =
${template}::make_descriptor(ck::make_naive_tensor_descriptor_packed(ck::make_tuple(${m},
${k})), ck::make_naive_tensor_descriptor(ck::make_tuple(${n},
${k}), ck::make_tuple(1, ${n})), ck::make_tuple(),
                                             ck::make_naive_tensor_descriptor_packed(ck::make_tuple(${m},
${n})));

    static_assert(desc.IsValid(), "Invalid ck gemm.");

    if constexpr(desc.IsValid())
    {
        ${template}::Run(desc,
               a,
               b,
               ck::make_tuple(),
               c);
    }
}

)__ck__";

TEST_CASE(test_problem_kernel)
{
    ck::host::device_gemm_multiple_d::Problem prob;
    prob.M = 1024;
    prob.N = 1024;
    prob.K = 1024;
    check_all<half> check;
    auto a = to_gpu(generate_buffer<half>(1024 * 1024, 0));
    auto b = to_gpu(generate_buffer<half>(1024 * 1024, 1));
    auto c = to_gpu(generate_buffer<half>(1024 * 1024, 2));
    std::string prologue = "";
    std::string epilogue = "";

    for(auto solution : prob.GetSolutions("gfx908", prologue, epilogue))
    {
        auto src  = ck::host::InterpolateString(gemm_compile_check,
                                               {{"include", prob.GetIncludeHeader()},
                                                {"template", solution.ToTemplateString()},
                                                {"m", std::to_string(prob.M)},
                                                {"n", std::to_string(prob.N)},
                                                {"k", std::to_string(prob.K)}});
        auto srcs = get_headers_for_test();
        srcs.push_back({"main.cpp", src});
        rtc::compile_options options;
        options.kernel_name = "f";
        auto k              = rtc::compile_kernel(srcs, options);
        auto block_size     = solution.GetTemplateParameter<std::size_t>("BlockSize");
        auto m_per_block    = solution.GetTemplateParameter<std::size_t>("MPerBlock");
        auto n_per_block    = solution.GetTemplateParameter<std::size_t>("NPerBlock");
        auto grid_size      = ck::host::integer_divide_ceil(prob.M, m_per_block) *
                         ck::host::integer_divide_ceil(prob.N, n_per_block);
        k.launch(nullptr, grid_size * block_size, block_size)(a.data(), b.data(), c.data());
        CHECK(report(solution, check(rtc::from_gpu(c))));
    }
}**/

int main(int argc, const char* argv[]) { test::run(argc, argv); }
