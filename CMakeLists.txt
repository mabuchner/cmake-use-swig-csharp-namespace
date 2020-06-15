cmake_minimum_required(VERSION 3.17.0)

project(mylib)

add_library(mylib STATIC)

target_compile_features(mylib PUBLIC cxx_std_14)

target_include_directories(mylib PUBLIC .)

target_sources(mylib PRIVATE mylib.cpp)

set_target_properties(mylib PROPERTIES PUBLIC_HEADER mylib.hpp)

find_package(SWIG 4.0.1 REQUIRED)
set(UseSWIG_MODULE_VERSION 2)
include(${SWIG_USE_FILE})

set_property(SOURCE mylib.i PROPERTY CPLUSPLUS ON)

swig_add_library(mylib_csharp
    TYPE SHARED
    LANGUAGE csharp
    SOURCES mylib.i
)

set_target_properties(mylib_csharp
    PROPERTIES
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE
)

target_link_libraries(mylib_csharp PRIVATE mylib)

get_target_property(
    MYLIB_CSHARP_SUPPORT_FILES_DIR
    mylib_csharp
    SWIG_SUPPORT_FILES_DIRECTORY
)

install(
    TARGETS mylib_csharp
    DESTINATION .
)
install(
    DIRECTORY ${MYLIB_CSHARP_SUPPORT_FILES_DIR}/
    DESTINATION .
)

