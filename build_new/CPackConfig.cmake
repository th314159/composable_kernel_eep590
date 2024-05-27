# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_ARCHIVE_COMPONENT_INSTALL "ON")
set(CPACK_BUILD_SOURCE_DIRS "/work1/sadasivan/student30/composable_kernel;/work1/sadasivan/student30/composable_kernel/build_new")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "devel;tests;examples;profiler")
set(CPACK_COMPONENTS_ALL_SET_BY_USER "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")
set(CPACK_DEBIAN_DEVEL_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_DEVEL_PACKAGE_NAME "composablekernel-dev")
set(CPACK_DEBIAN_DEVEL_PACKAGE_PROVIDES "composablekernel (= 1.1.0)")
set(CPACK_DEBIAN_EXAMPLES_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_EXAMPLES_PACKAGE_NAME "composablekernel-examples")
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "/work1/sadasivan/student30/composable_kernel/build_new/debian/postinst;/work1/sadasivan/student30/composable_kernel/build_new/debian/prerm")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "rocm-core")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "MIOpen Kernels Dev Team <dl.MIOpen@amd.com>")
set(CPACK_DEBIAN_PACKAGE_RELEASE "c2784145d~dirty")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PROFILER_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_PROFILER_PACKAGE_NAME "composablekernel-ckprofiler")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_RECOMMENDS "composablekernel-dev (>=1.1.0)")
set(CPACK_DEBIAN_TESTS_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_TESTS_PACKAGE_NAME "composablekernel-tests")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/opt/ohpc/pub/utils/cmake/3.25.2/share/cmake-3.25/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "composable_kernel built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "TGZ;ZIP;RPM")
set(CPACK_INSTALL_CMAKE_PROJECTS "/work1/sadasivan/student30/composable_kernel/build_new;composable_kernel;ALL;/")
set(CPACK_INSTALL_PREFIX "/opt/rocm")
set(CPACK_MODULE_PATH "/work1/sadasivan/student30/composable_kernel/cmake;/opt/rocm-5.7.1/share/rocm/cmake")
set(CPACK_NSIS_DISPLAY_NAME "composablekernel 1.1.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_MODIFY_PATH "ON")
set(CPACK_NSIS_PACKAGE_NAME "composablekernel")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "/usr/bin/objcopy")
set(CPACK_OBJDUMP_EXECUTABLE "/usr/bin/objdump")
set(CPACK_OUTPUT_CONFIG_FILE "/work1/sadasivan/student30/composable_kernel/build_new/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/opt/ohpc/pub/utils/cmake/3.25.2/share/cmake-3.25/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "High Performance Composable Kernel for AMD GPUs")
set(CPACK_PACKAGE_FILE_NAME "composablekernel-1.1.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "composablekernel 1.1.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "composablekernel 1.1.0")
set(CPACK_PACKAGE_NAME "composablekernel")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Advanced Micro Devices, Inc")
set(CPACK_PACKAGE_VERSION "1.1.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGING_INSTALL_PREFIX "")
set(CPACK_READELF_EXECUTABLE "/usr/bin/readelf")
set(CPACK_RESOURCE_FILE_LICENSE "/work1/sadasivan/student30/composable_kernel/LICENSE")
set(CPACK_RESOURCE_FILE_README "/opt/ohpc/pub/utils/cmake/3.25.2/share/cmake-3.25/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/opt/ohpc/pub/utils/cmake/3.25.2/share/cmake-3.25/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_COMPONENT_INSTALL "ON")
set(CPACK_RPM_DEVEL_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_DEVEL_PACKAGE_NAME "composablekernel-devel")
set(CPACK_RPM_DEVEL_PACKAGE_PROVIDES "composablekernel = 1.1.0")
set(CPACK_RPM_EXAMPLES_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_EXAMPLES_PACKAGE_NAME "composablekernel-examples")
set(CPACK_RPM_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_PACKAGE_AUTOREQPROV "Off")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_NAME "composablekernel")
set(CPACK_RPM_PACKAGE_RELEASE "c2784145d_dirty%{?dist}")
set(CPACK_RPM_PACKAGE_RELOCATABLE "Off")
set(CPACK_RPM_PACKAGE_REQUIRES "rocm-core")
set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE "/work1/sadasivan/student30/composable_kernel/build_new/debian/postinst")
set(CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE "/work1/sadasivan/student30/composable_kernel/build_new/debian/prerm")
set(CPACK_RPM_PROFILER_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_PROFILER_PACKAGE_NAME "composablekernel-ckprofiler")
set(CPACK_RPM_RUNTIME_PACKAGE_SUGGESTS "composablekernel-devel >= 1.1.0")
set(CPACK_RPM_TESTS_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_TESTS_PACKAGE_NAME "composablekernel-tests")
set(CPACK_SET_DESTDIR "ON")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/work1/sadasivan/student30/composable_kernel/build_new/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "0")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/work1/sadasivan/student30/composable_kernel/build_new/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
