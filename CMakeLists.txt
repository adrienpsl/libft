cmake_minimum_required(VERSION 3.9)
project(library C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB head "sources/include/*.h")
#file(GLOB head "")

include_directories(sources/include/*.h)
file(GLOB sources1 "sources/src/**/*.c")
file(GLOB sources2 "sources/src/**/**/*.c")
file(GLOB sources3 "sources/src/**/**/**/*.c")
file(GLOB sources4 "sources/src/**/**/**/**/*.c")
file(GLOB sources5 "sources/src/**/**/**/**/**/*.c")
file(GLOB sources6 "test/*.c")

# all sources
set(
        sources
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}

        sources/src/list/simple_list/simple_linked_list/src/sll_drop.c)
add_executable(library
        # type of lib
        main.c

        # All files
        ${head}
        ${sources}

#        sources/ft_library_header.h
        )