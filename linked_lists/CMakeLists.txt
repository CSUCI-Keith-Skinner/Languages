cmake_minimum_required(VERSION 3.6)
project(linked_list)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
<<<<<<< HEAD
=======
add_compile_options(-Wall -Wextra -Wpedantic)
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79

add_executable(linked_list 
    src/main.c 
    src/list.c
<<<<<<< HEAD
    src/personel.c)
=======
    src/person.c)

add_executable(linked_list_test
        src/person.test.c
        src/list.c
        src/person.c)
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
