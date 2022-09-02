cmake_minimum_required(VERSION 3.20)
project(MCSL C)

set(CMAKE_C_STANDARD 11)

include_directories(MCSL)

add_subdirectory(MCSL)

add_executable(MCSL main.c)

target_link_libraries(MCSL MCSL_LIB)
