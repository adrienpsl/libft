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
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")

# ------------------------------------------------------------------------------
#    Libft init
# ------------------------------------------------------------------------------
add_library(${__LIB_NAME__} "" src/ft_printf/tests/ft_pf.catch_format.test.c src/ft_printf/ft_pf.get_number.c src/ft_printf/tests/ft_pf.get_nb.test.c src/ft_printf/ft_pf.get_str.c src/ft_printf/tests/ft_pf.get_str.test.c src/ft_printf/ft_pf.print.c src/ft_printf/tests/ft_pf.print.test.c src/ft_buffer/tests/ft_buffer.main.test.c src/ft_buffer/tests/ft_buffer.test.c src/ft_printf/tests/ft_printf.test.c) # must have ""
target_include_directories(${__LIB_NAME__} PUBLIC includes)

add_subdirectory(src)
add_subdirectory(tests)

# ------------------------------------------------------------------------------
#    create on link executable
# ------------------------------------------------------------------------------
add_executable(libft_run main.c)

target_link_libraries(libft_run ${__LIB_NAME__})


















# add the lib C Unit from the homebrow install repository
#target_link_libraries(libft_run /usr/local/Cellar/cunit/2.1-3/lib/libcunit.a)
# the homebrew install repo
#include_directories(/usr/local/include/CUnit)
#target_link_libraries(${__LIB_NAME__} /usr/local/Cellar/cunit/2.1-3/lib/libcunit.a)
# add all module