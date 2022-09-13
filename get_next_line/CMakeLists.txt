cmake_minimum_required(VERSION 3.16.3)

project(get_next_line VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
add_executable(get_next_line main.c get_next_line_utils.c get_next_line.c)