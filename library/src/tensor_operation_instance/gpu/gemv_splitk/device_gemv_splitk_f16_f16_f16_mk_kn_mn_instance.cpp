// SPDX-License-Identifier: MIT
// Copyright (c) 2023, Advanced Micro Devices, Inc. All rights reserved.

#include <cstdlib>

#include "ck/ck.hpp"
#include "ck/tensor_operation/gpu/device/tensor_layout.hpp"
#include "ck/tensor_operation/gpu/device/impl/device_tall_and_skinny_gemm_splitk.hpp"

#include "ck/library/tensor_operation_instance/add_device_operation_instance.hpp"

namespace ck {
namespace tensor_operation {
namespace device {
namespace instance {

using F16 = ck::half_t;
using F32 = float;

using Row = ck::tensor_layout::gemm::RowMajor;
using Col = ck::tensor_layout::gemm::ColumnMajor;

template <ck::index_t... Is>
using S = ck::Sequence<Is...>;

using PassThrough                   = ck::tensor_operation::element_wise::PassThrough;
static constexpr auto GemmMNPadding = ck::tensor_operation::device::GemmSpecialization::MNPadding;

// Compilation parameters for a[m, k] * b[k, n] = c[m, n]
using device_gemv_splitk_f16_f16_f16_mk_kn_mn_instances = std::tuple<
    // clang-format off
// ######|     AData|     BData|     CData|     AccData| ALayout| BLayout| CLayout|           A|           B|           C|           GEMM| Block|  MPer|  NPer| K0Per| K1|      M1Per|      N1Per|   KPer|     ABlockTransfer|       ABlockTransfer| ABlockTransfer| ABlockTransfer|      ABlockTransfer  |     ABlockTransfer|      ABlockTransfer  | BBlockTransfer|  BThreadTransfer|    BThreadTransfer|     CThreadTransfer| CThreadTransfer|    CThreadTransfer|
// ######|      Type|      Type|      Type|        Type|        |        |        | Elementwise| Elementwise| Elementwise| Spacialization|  Size| Block| Block| Block|   | ThreadM111| ThreadN111| Thread| ThreadSliceLengths| ThreadClusterLengths|  ThreadCluster|      SrcAccess|SrcVectorTensorLengths|    SrcVectorTensor|DstVectorTensorLengths|      SrcAccess|     SrcVectorDim| SrcScalarPerVector|        SrcDstAccess| SrcDstVectorDim| DstScalarPerVector|
// ######|          |          |          |            |        |        |        |   Operation|   Operation|   Operation|               |      |      |      |      |   |           |           |       | KBatch_K0_M0_M1_K1|   KBatch_K0_M0_M1_K1|   ArrangeOrder|          Order| KBatch_K0_M0_M1_K1   | ContiguousDimOrder| KBatch_K0_M0_M1_K1   |          Order|                 |                   |               Order|                |                   |
// ######|          |          |          |            |        |        |        |            |            |            |               |      |      |      |      |   |           |           |       |                   |                     |               |               |                      |                   |                      |               |                 |                   |                    |                |                   |
       ///< ADataType, BDataType, CDataType, AccDataType, ALayout, BLayout, CLayout,  AElementOp,  BElementOp,  CElementOp,  GemmMNPadding,    B,     M1,   B*N1,   K0,  K1,         1,          N1,      1,    S<1,1, 1, 1, K1>,   S<1,K0, 1,M1, 1>,S<0,1,2,3,4>,  S<0,1,2,3,4>,      S<1,1, 1, 1, K1>,     S<0,1,2,3,4>,     S<1,1, 1, 1, K1>,    S<0,1,2,3,4>,                3,               N1,        S<0, 1, 2, 3, 4, 5>,             5,                  N1>;
        //N1=2
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   1,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,1, 1,  1, 1>,  S<0,1,2,3,4>,       S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   1,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   1,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   2,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   2,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   2,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   3,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   3,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   3,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   4,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   4,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   4,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   5,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   5,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   5,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   6,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   6,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   6,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   7,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   7,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   7,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   8,   2,         1,          2,      1,    S<1,1, 1, 1, 2>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   8,   4,         1,          2,      1,    S<1,1, 1, 1, 4>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   128,   8,   8,         1,          2,      1,    S<1,1, 1, 1, 8>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               2,        S<0, 1, 2, 3, 4, 5>,             5,                  2>,
        //N1=4
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   1,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   1,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   1,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   2,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   2,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   2,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   3,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   3,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   3,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   4,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   4,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   4,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   5,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   5,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   5,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   6,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   6,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   6,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   7,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   7,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   7,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   8,   2,         1,          4,      1,    S<1,1, 1, 1, 2>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   8,   4,         1,          4,      1,    S<1,1, 1, 1, 4>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   256,   8,   8,         1,          4,      1,    S<1,1, 1, 1, 8>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               4,        S<0, 1, 2, 3, 4, 5>,             5,                  4>,
        //N1=8
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   1,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   1,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   1,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,1, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   2,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   2,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   2,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,2, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   3,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   3,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   3,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,3, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   4,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   4,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   4,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,4, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   5,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   5,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   5,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,5, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   6,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   6,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   6,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,6, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   7,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   7,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   7,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,7, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   8,   2,         1,          8,      1,    S<1,1, 1, 1, 2>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 2>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 2>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   8,   4,         1,          8,      1,    S<1,1, 1, 1, 4>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 4>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 4>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>,
        ck::tensor_operation::device::deviceTsmmDl
        <        F16,        F16,     F16,         F32,  Row,      Row,    Row,    PassThrough, PassThrough,  PassThrough,  GemmMNPadding,    64,    1,   512,   8,   8,         1,          8,      1,    S<1,1, 1, 1, 8>,   S<1,8, 1,1, 1>,     S<0,1,2,3,4>,      S<0,1,2,3,4>,      S<1,1, 1, 1, 8>,     S<0,1,2,3,4>,     S<1,1, 1, 1, 8>,       S<0,1,2,3,4>,            3,               8,        S<0, 1, 2, 3, 4, 5>,             5,                  8>
    // clang-format on
    >;

void add_device_gemv_splitk_f16_f16_f16_mk_kn_mn_instances(
    std::vector<std::unique_ptr<
        DeviceTsmm<Row, Row, Row, F16, F16, F16, PassThrough, PassThrough, PassThrough>>>&
        instances)
{
    add_device_operation_instances(instances, device_gemv_splitk_f16_f16_f16_mk_kn_mn_instances{});
}

} // namespace instance
} // namespace device
} // namespace tensor_operation
} // namespace ck
