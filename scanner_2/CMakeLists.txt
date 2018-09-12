# Keith Skinner
# Lab 3: Scanner 2

cmake_minimum_required(VERSION 3.8)
project(scanner2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-m64 -g -O0 -D_DEBUG -Wall -Wextra -Wpedantic")


add_executable(scanner_2 src/main.c src/scanner.c src/table.c)
