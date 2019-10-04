cmake_minimum_required(VERSION 3.14)

# ------------------------------------------------------------------------------
#    Set up
# ------------------------------------------------------------------------------
set(__LIB_NAME__ libft)

# ------------------------------------------------------------------------------
#    compilation flag
# ------------------------------------------------------------------------------
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wmissing-prototypes")
#set(CMAKE_C_FLAGS "-Weverything -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")

# ------------------------------------------------------------------------------
#    Libft init
# ------------------------------------------------------------------------------
add_library(${__LIB_NAME__} "") # must have ""
target_include_directories(${__LIB_NAME__} PUBLIC includes)

add_subdirectory(src)

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