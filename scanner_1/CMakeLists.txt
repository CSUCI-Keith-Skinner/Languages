# Keith Skinner
# Lab 3: Scanner 1

cmake_minimum_required(VERSION 3.8)
project(scanner1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-m64 -g -O0 -D_DEBUG -Wall -Wextra -Wpedantic")


add_executable(scanner_1_file src/main.c src/scanner.c)
add_executable(scanner_1_stdin src/main.c src/scanner.c)
