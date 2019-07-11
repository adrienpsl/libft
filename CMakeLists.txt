set(CMAKE_C_STANDARD 99)
cmake_minimum_required(VERSION 3.14)
project(libft C)


set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")

# I got all the includes to my directory
include_directories(PRIVATE includes)

add_library(libft STATIC

        #[[ char ]]

        #[[ io ]]

        #[[ list ]]

        #[[ memory ]]

        #[[ printf ]]

        #[[ str ]]

        #[[ printf ]]

        #[[ buffer ]]

        #[[ test ]]

        #[[ array ]]
        src/ft_atoi.c src/ft_itoa.c src/ft_strlen.c src/ft_memcpy.c src/ft_bzero.c
        src/ft_isalnum.c
        src/ft_isalpha.c
        src/ft_isascii.c
        src/ft_isdigit.c
        src/ft_isprint.c
        src/ft_isspace.c
        src/ft_buffer.c
        src/array.func.c
        src/array.handle.c
        src/array.sort.c
        src/ft_replace.c


        src/ft_memalloc.c src/ft_memccpy.c src/ft_memchr.c src/ft_memcmp.c src/ft_memdel.c src/ft_memmove.c src/ft_memset.c src/ft_putchar.c src/ft_putchar_fd.c src/ft_putendl.c src/ft_putendl_fd.c src/ft_putnstr.c src/ft_str_split.c src/ft_char_test.c src/ft_capitalize.c src/ft_strdup.c src/ft_memdup.c src/ft_free_split.c src/ft_str_print_split.c src/ft_strchr.c src/ft_str_split_count.c src/ft_catch_options.c src/ft_split_cmp.c src/ft_printf.c src/ft_streq.c src/ft_strjoin.c src/ft_strnew.c src/ft_strjoin.h src/ft_strcmp.c src/ft_split_add.c src/get_next_line.c src/ft_strsub.c)


target_include_directories(libft PUBLIC includes)

add_executable(libft_run main.c

        #[[ test]]
        tests/ft_array.test.c
        tests/ft_buffer.test.c
        tests/ft_char.test.c
        tests/ft_io.test.c

        #[[ printf]]
        )

target_link_libraries(libft_run libft)