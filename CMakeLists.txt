cmake_minimum_required(VERSION 3.10)

project(calculations)
set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include)
add_library(long_arithmetic SHARED ${SOURCES})
target_include_directories(long_arithmetic PUBLIC include)

add_executable(main main.cpp)
target_link_libraries(main long_arithmetic)