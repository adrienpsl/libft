set(CMAKE_C_STANDARD 99)
cmake_minimum_required(VERSION 3.14)


add_library(ft_printf STATIC
        #[[ src ]]
        ft_printf.c

        #[[ test]]

        )

target_include_directories(ft_printf PUBLIC includes)
target_link_libraries(ft_printf libft)