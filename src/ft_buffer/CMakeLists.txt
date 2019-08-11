set(CMAKE_C_STANDARD 99)
cmake_minimum_required(VERSION 3.14)

set(__NAME__ ft_buffer)

add_library(${__NAME__} STATIC
        #[[ src ]]
        ft_buffer.c

        #[[ test]]

        )

target_include_directories(${__NAME__} PUBLIC includes)
target_link_libraries(${__NAME__}  libft)