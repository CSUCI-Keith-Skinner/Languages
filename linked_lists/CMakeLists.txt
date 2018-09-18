cmake_minimum_required(VERSION 3.6)
project(linked_list)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_executable(linked_list 
    src/main.c 
    src/list.c
    src/personel.c)
