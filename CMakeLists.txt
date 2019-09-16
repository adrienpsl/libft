cmake_minimum_required(VERSION 3.14)

# ------------------------------------------------------------------------------
#    Set up
# ------------------------------------------------------------------------------
set(__LIB_NAME__ libft)
project(libft C)

# ------------------------------------------------------------------------------
#    compilation flag
# ------------------------------------------------------------------------------
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "-Weverything -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")

# ------------------------------------------------------------------------------
#    Libft init
# ------------------------------------------------------------------------------
add_library(${__LIB_NAME__} "" src/ft_printf/tests/ft_pf.catch_format.test.c src/ft_printf/ft_pf.get_number.c src/ft_printf/tests/ft_pf.get_nb.test.c src/ft_printf/ft_pf.get_str.c src/ft_printf/tests/ft_pf.get_str.test.c src/ft_printf/ft_pf.print.c src/ft_printf/tests/ft_pf.print.test.c src/ft_buffer/tests/ft_buffer.main.test.c src/ft_buffer/tests/ft_buffer.test.c src/ft_printf/tests/ft_printf.test.c src/ft_array/src/ft_array.slice.c src/ft_array/src/ft_array.remove_from.c src/ft_array/src/ft_array.slice_and_remove.c src/ft_array/tests/ft_array.slice_and_remove.test.c src/ft_printf/ft_pf.utils.c src/ft_str/ft_str.add_buffer.c src/ft_array/src/ft_array.extract_by_func.c src/ft_array/tests/ft_array.extract_by_func.test.c src/ft_array/src/ft_array.remove_func.c src/ft_array/src/ft_array.free_func.c src/ft_array/src/ft_array.find.c src/ft_array/tests/ft_array.find.test.c src/ft_str/tests/ft_str.search_start.test.c) # must have ""
target_include_directories(${__LIB_NAME__} PUBLIC includes)

add_subdirectory(src)

# ------------------------------------------------------------------------------
#    create on link executable
# ------------------------------------------------------------------------------
add_executable(libft_run main.c src/ft_str/tests/ft_str.main.test.c)

target_link_libraries(libft_run ${__LIB_NAME__})


















# add the lib C Unit from the homebrow install repository
#target_link_libraries(libft_run /usr/local/Cellar/cunit/2.1-3/lib/libcunit.a)
# the homebrew install repo
#include_directories(/usr/local/include/CUnit)
#target_link_libraries(${__LIB_NAME__} /usr/local/Cellar/cunit/2.1-3/lib/libcunit.a)
# add all module