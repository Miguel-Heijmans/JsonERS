cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(DOWNLOAD https://gitlab.incontrolsim.com/enterprise-resource-simulator/public/ers_sdk/-/raw/main/setup.cmake
${CMAKE_BINARY_DIR}/ERSSetup.cmake)
include(${CMAKE_BINARY_DIR}/ERSSetup.cmake)
ERS_Download_SDK_Dictated()
ERS_RUN_VCPKG()

#Configure name
project(JSON VERSION 0.1)

ERS_Enable_Additional_Build_Settings()
ERS_Setup_SDK()

add_subdirectory(Src)

if(ERS_BUILD_TESTS)
    add_subdirectory(Tests)
endif()

