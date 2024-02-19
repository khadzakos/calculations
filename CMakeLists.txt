cmake_minimum_required(VERSION 3.10)

project(calculations)
set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include)
add_library(long_arithmetic SHARED ${SOURCES})
target_include_directories(long_arithmetic PUBLIC include)

add_executable(pi pi.cpp)
target_link_libraries(pi long_arithmetic)

add_executable(sample sample.cpp)
target_link_libraries(sample long_arithmetic)

add_subdirectory(googletest)
add_executable(tests tests.cpp)
target_link_libraries(tests long_arithmetic gtest gtest_main)