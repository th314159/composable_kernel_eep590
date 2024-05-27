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
include test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/compiler_depend.make

# Include the progress variables for this target.
include test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/progress.make

# Include the compile flags for this target's objects.
include test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/flags.make

test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o: test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/flags.make
test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o: /work1/sadasivan/student30/composable_kernel/test/convnd_fwd/convnd_fwd.cpp
test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o: test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work1/sadasivan/student30/composable_kernel/build_new/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd && /opt/rocm-5.7.1/bin/hipcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o -MF CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o.d -o CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o -c /work1/sadasivan/student30/composable_kernel/test/convnd_fwd/convnd_fwd.cpp

test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.i"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd && /opt/rocm-5.7.1/bin/hipcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work1/sadasivan/student30/composable_kernel/test/convnd_fwd/convnd_fwd.cpp > CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.i

test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.s"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd && /opt/rocm-5.7.1/bin/hipcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work1/sadasivan/student30/composable_kernel/test/convnd_fwd/convnd_fwd.cpp -o CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.s

# Object files for target test_convnd_fwd
test_convnd_fwd_OBJECTS = \
"CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o"

# External object files for target test_convnd_fwd
test_convnd_fwd_EXTERNAL_OBJECTS = \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_f32_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_f16_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_c_shuffle_nhwc_kyxc_nhwk_f16_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_bf16_instance.cpp.o" \
"/work1/sadasivan/student30/composable_kernel/build_new/library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_int8_instance.cpp.o"

bin/test_convnd_fwd: test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/convnd_fwd.cpp.o
bin/test_convnd_fwd: library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_f32_instance.cpp.o
bin/test_convnd_fwd: library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_f16_instance.cpp.o
bin/test_convnd_fwd: library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_c_shuffle_nhwc_kyxc_nhwk_f16_instance.cpp.o
bin/test_convnd_fwd: library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_bf16_instance.cpp.o
bin/test_convnd_fwd: library/src/tensor_operation_instance/gpu/conv2d_fwd/CMakeFiles/device_conv2d_fwd_instance.dir/device_conv2d_fwd_xdl_nhwc_kyxc_nhwk_int8_instance.cpp.o
bin/test_convnd_fwd: test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/build.make
bin/test_convnd_fwd: lib/libgtest_main.a
bin/test_convnd_fwd: lib/libutility.a
bin/test_convnd_fwd: lib/libgtest.a
bin/test_convnd_fwd: /opt/rocm-5.7.1/lib/libamdhip64.so.5.7.50701
bin/test_convnd_fwd: /opt/rocm-5.7.1/llvm/lib/clang/17.0.0/lib/linux/libclang_rt.builtins-x86_64.a
bin/test_convnd_fwd: test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work1/sadasivan/student30/composable_kernel/build_new/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/test_convnd_fwd"
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_convnd_fwd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/build: bin/test_convnd_fwd
.PHONY : test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/build

test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/clean:
	cd /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd && $(CMAKE_COMMAND) -P CMakeFiles/test_convnd_fwd.dir/cmake_clean.cmake
.PHONY : test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/clean

test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/depend:
	cd /work1/sadasivan/student30/composable_kernel/build_new && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work1/sadasivan/student30/composable_kernel /work1/sadasivan/student30/composable_kernel/test/convnd_fwd /work1/sadasivan/student30/composable_kernel/build_new /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd /work1/sadasivan/student30/composable_kernel/build_new/test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/convnd_fwd/CMakeFiles/test_convnd_fwd.dir/depend

