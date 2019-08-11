#set(CMAKE_C_STANDARD 99)
#cmake_minimum_required(VERSION 3.14)

#include_directories(cunit/CUnit/CUnit)
#include_directories(cunit/CUnit)
include_directories(/usr/local/include)

add_library(ft_array STATIC
        #[[ src ]]
        ft_array.add.c
        ft_array.bubble.c
        ft_array.cmp.c
        ft_array.free.c
        ft_array.func.c
        ft_array.init.c
        ft_array.next.c
        ft_array.prev.c
        ft_array.remove.c
        ft_array.utils.c
        ft_array_at.c
        ft_array_copy.c

        #[[ test]]
        tests/ft_array.test.c
        tests/ft_array.init.test.c)


add_executable(ft_array_ex ft_array.main.c)

#set_target_properties (ft_array_ex PROPERTIES LINK_FLAGS -Wl,-lcunit)

target_include_directories(ft_array PUBLIC includes)
target_link_libraries(ft_array libft)
target_link_libraries(ft_array_ex /usr/local/Cellar/cunit/2.1-3/lib/libcunit.a)
