cmake_minimum_required(VERSION 3.8)
project(scanner1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-m64 -g -O0 -D_DEBUG -Wall -Wextra -Wpedantic")


add_executable(scanner1 src/main.c
        src/scanner_ad_hoc.c)
