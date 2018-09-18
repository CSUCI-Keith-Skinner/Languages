cmake_minimum_required(VERSION 3.10)
project(parser LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(parser
        src/main.c
        src/scanner.c
        src/parser.c)