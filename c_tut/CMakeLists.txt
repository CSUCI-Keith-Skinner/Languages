cmake_minimum_required(VERSION 3.8)

project(c_tut)

set(CMAKE_C_STANDARD 99)
if (CMAKE_COMPILER_IS_GNUCC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -O0 -D_DEBUG -Wall -Wextra -Wpedantic")
endif()

include_directories(AFTER src)

add_executable(argc-argv src/argc-argv.c)
add_executable(array src/array.c)
add_executable(array-ptr src/array-ptr.c)
add_executable(array-arg src/array-arg.c)
add_executable(file src/file.c)
add_executable(functions src/functions.c)
add_executable(hello src/hello.c)
add_executable(if-then-else src/if-then-else.c)
add_executable(mem-alloc src/mem-alloc.c)
add_executable(pointer src/pointer.c)
add_executable(ptr-arg src/ptr-arg.c)
add_executable(ptr-arg-2 src/ptr-arg-2.c)
add_executable(ptr-arg-3 src/ptr-arg-3.c)
add_executable(ptr-func src/ptr-func.c)
add_executable(ptr-problems src/ptr-problems.c)
add_executable(ref-arg src/ref-arg.c)
add_executable(strings src/strings.c)
add_executable(type-conv src/type-conv.c)

add_executable(types src/types.c)
add_executable(words src/words.c)
add_executable(calc src/calc.c)
add_executable(struct src/struct.c src/person.c)
add_executable(test_processor src/test_processor.c src/processor.c)

#edited files:
#  Question 1: 
#  Question 2: types.c
#  Question 3: if-then-else.c
#  Question 4: array.c
#  Question 5: words.c
#  Question 6: file.c data.txt
#  Question 7: ptr-arg-2.c
#  Question 8: calc.c
#  Question 9: person.h person.c struct.c
#  Question 10: test_processor.c processor.c processor.h



