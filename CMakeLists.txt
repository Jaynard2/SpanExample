cmake_minimum_required(VERSION 3.16)
project(span_example)

add_executable(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
add_subdirectory(src)
