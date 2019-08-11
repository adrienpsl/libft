set(CMAKE_C_STANDARD 99)
cmake_minimum_required(VERSION 3.14)
project(libft C)


set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")

# I got all the includes to my directory
include_directories(PRIVATE src/includes)
#include_directories(CUnit-2.1-3/CUnit/Headers)
#include_directories(PRIVATE src/ft_array/includes)

add_subdirectory(src)

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
        src/ft_buffer/ft_buffer.c
        src/ft_replace.c
        src/ft_strcat.c
        src/ft_strlcat.c


        src/ft_memalloc.c src/ft_memccpy.c src/ft_memchr.c src/ft_memcmp.c src/ft_memdel.c src/ft_memmove.c src/ft_memset.c src/ft_putchar.c src/ft_putchar_fd.c src/ft_putendl.c src/ft_putendl_fd.c src/ft_putnstr.c src/ft_strsplit.c src/ft_char_test.c src/ft_capitalize.c src/ft_strdup.c src/ft_memdup.c src/ft_free_split.c src/ft_str_print_split.c src/ft_strchr.c src/ft_str_split_count.c src/ft_catch_options.c src/ft_strsplit.cmp.c src/ft_printf/ft_printf.c src/ft_streq.c src/ft_strjoin.c src/ft_strnew.c  src/ft_strcmp.c src/ft_strsplit.add.c src/get_next_line.c src/ft_strsub.c src/ft_putsteret.c src/ft_strchrreplace.c src/ft_strsplit.search.c src/ft_testing_function.c src/ft_strsplit.remove.c src/ft_strsplit.mix.c src/ft_strsplit.copy.c src/ft_strsplit.func.c src/str.ft_str_search.c src/ft_str_free.c   src/ft_errno/ft_errno.utils.c src/ft_errno/ft_perror.c src/ft_errno/ft_strerror.c src/libft_utils.c  src/ft_mem/ft_memswap.c  "no_finish/ quick_sort.c" no_finish/array_add_att.c
        src/ft_log/ft_log.c src/ft_buffer/includes/ft_buffer.h src/lib.c)

target_include_directories(libft PUBLIC src/includes)

add_executable(libft_run main.c

        #[[ test]]
        tests/ft_buffer.test.c
        tests/ft_char.test.c
        tests/ft_io.test.c
        tests/ft_str.test.c

        #[[ printf]]
        )


target_link_libraries(libft libft_)
target_link_libraries(libft_run libft_)
target_link_libraries(libft_run libft)
