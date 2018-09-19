cmake_minimum_required(VERSION 3.8)
project(personnel)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(linked_list 
    src/main.c 
    src/list.c
    src/personel.c)
