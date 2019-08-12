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
add_library(${__LIB_NAME__} "" src/ft_log/tests/ft_log_test.c) # must have ""
include_directories(includes)

# add all module
add_subdirectory(src)

# ------------------------------------------------------------------------------
#    create on link executable
# ------------------------------------------------------------------------------
add_executable(libft_run main.c)

target_link_libraries(libft_run ${__LIB_NAME__})

# add the lib C Unit from the homebrow install repository
include_directories(/usr/local/include)
target_link_libraries(libft_run /usr/local/Cellar/cunit/2.1-3/lib/libcunit.a)

