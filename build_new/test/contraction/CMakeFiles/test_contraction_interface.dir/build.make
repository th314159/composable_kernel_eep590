# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/ohpc/pub/utils/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/ohpc/pub/utils/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work1/sadasivan/student30/composable_kernel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work1/sadasivan/student30/composable_kernel/build_new

# Include any dependencies generated for this target.
include test/contraction/CMakeFiles/test_contraction_interface.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/contraction/CMakeFiles/test_contraction_interface.dir/compiler_depend.make

# Include the progress variables for this target.
include test/contraction/CMakeFiles/test_contraction_interface.dir/progress.make

# Include the compile flags for this target's objects.
include test/contraction/CMakeFiles/test_contraction_interface.dir/flags.make

test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o: test/contraction/CMakeFiles/test_contraction_interface.dir/flags.make
test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o: /work1/sadasivan/student30/composable_kernel/test/contraction/test_contraction_interface.cpp
test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o: test/contraction/CMakeFiles/test_contraction_interface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work1/sadasivan/student30/composable_kernel/build_new/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/contraction && /opt/rocm-5.7.1/bin/hipcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o -MF CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o.d -o CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o -c /work1/sadasivan/student30/composable_kernel/test/contraction/test_contraction_interface.cpp

test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.i"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/contraction && /opt/rocm-5.7.1/bin/hipcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work1/sadasivan/student30/composable_kernel/test/contraction/test_contraction_interface.cpp > CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.i

test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.s"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/contraction && /opt/rocm-5.7.1/bin/hipcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work1/sadasivan/student30/composable_kernel/test/contraction/test_contraction_interface.cpp -o CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.s

# Object files for target test_contraction_interface
test_contraction_interface_OBJECTS = \
"CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o"

# External object files for target test_contraction_interface
test_contraction_interface_EXTERNAL_OBJECTS = \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_kknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_knnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_mknn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_mnnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_mnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_mnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_mnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_mnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_mnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_mnn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_kkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_knn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_mkn_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_mnn_instance.cpp.o"

bin/test_contraction_interface: test/contraction/CMakeFiles/test_contraction_interface.dir/test_contraction_interface.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_f16_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_f32_compute_bf16_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_f64_compute_f32_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_f16_compute_f32_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_kknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_knnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_mknn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_bilinear/CMakeFiles/device_contraction_bilinear_instance.dir/device_contraction_bilinear_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_bf16_compute_f32_mnnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_mnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_f16_mnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f32_f32_f32_compute_bf16_mnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_mnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f64_f64_f64_compute_f32_mnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_f16_f16_f16_compute_f32_mnn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_kkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_knn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_mkn_instance.cpp.o
bin/test_contraction_interface: library/src/tensor_operation_instance/gpu/contraction_scale/CMakeFiles/device_contraction_scale_instance.dir/device_contraction_scale_m2_n2_k2_xdl_c_shuffle_bf16_bf16_bf16_compute_f32_mnn_instance.cpp.o
bin/test_contraction_interface: test/contraction/CMakeFiles/test_contraction_interface.dir/build.make
bin/test_contraction_interface: lib/libgtest_main.a
bin/test_contraction_interface: lib/libutility.a
bin/test_contraction_interface: lib/libgtest.a
bin/test_contraction_interface: /opt/rocm-5.7.1/lib/libamdhip64.so.5.7.50701
bin/test_contraction_interface: /opt/rocm-5.7.1/llvm/lib/clang/17.0.0/lib/linux/libclang_rt.builtins-x86_64.a
bin/test_contraction_interface: test/contraction/CMakeFiles/test_contraction_interface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work1/sadasivan/student30/composable_kernel/build_new/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/test_contraction_interface"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/contraction && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_contraction_interface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/contraction/CMakeFiles/test_contraction_interface.dir/build: bin/test_contraction_interface
.PHONY : test/contraction/CMakeFiles/test_contraction_interface.dir/build

test/contraction/CMakeFiles/test_contraction_interface.dir/clean:
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/contraction && $(CMAKE_COMMAND) -P CMakeFiles/test_contraction_interface.dir/cmake_clean.cmake
.PHONY : test/contraction/CMakeFiles/test_contraction_interface.dir/clean

test/contraction/CMakeFiles/test_contraction_interface.dir/depend:
	cd /work1/sadasivan/student30/composable_kernel/build_new && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work1/sadasivan/student30/composable_kernel /work1/sadasivan/student30/composable_kernel/test/contraction /work1/sadasivan/student30/composable_kernel/build_new /work1/sadasivan/student30/composable_kernel/build_new/test/contraction /work1/sadasivan/student30/composable_kernel/build_new/test/contraction/CMakeFiles/test_contraction_interface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/contraction/CMakeFiles/test_contraction_interface.dir/depend

