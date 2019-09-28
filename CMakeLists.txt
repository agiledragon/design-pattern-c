cmake_minimum_required(VERSION 2.8)

project(design-pattern-in-c)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}")

include_directories(
"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

file(GLOB_RECURSE all_files
	src/*.c)

add_executable(design-pattern-in-c ${all_files})
