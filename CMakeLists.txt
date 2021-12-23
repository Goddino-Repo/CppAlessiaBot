cmake_minimum_required(VERSION 3.20)
project(CppAlessiaBot)

set(CMAKE_CXX_STANDARD 23)

add_executable(CppAlessiaBot main.cpp stringUtils.cpp stringUtils.h emoji.cpp emoji.h constants.h)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 67e12da316754ff3c6c91b50aafb2658438f3c1e) # the commit hash for 1.7.0
FetchContent_MakeAvailable(cpr)
target_link_libraries(CppAlessiaBot PRIVATE cpr::cpr)