# /**
# * Name: Keith Skinner
# * Lab: Lab 1 C Tutorial
# * Date: 09/18/18
# **/

cmake_minimum_required(VERSION 3.10)
project(c_tut)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -O0 -D_DEBUG -Wall -Wextra -Wpedantic")
add_executable(test_processor src/test_processor.c src/processor.c)
