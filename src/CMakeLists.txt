

#[[ add all subdirectory to build the full lib ]]
add_subdirectory(ft_buffer)
add_subdirectory(ft_array)
add_subdirectory(ft_printf)

#[[ create the lib  ]]
add_library(libft_ STATIC lib.c ft_log/includes/ft_log.h)

#[[ link the lib with all the module ]]
target_link_libraries(libft_ ft_array)
target_link_libraries(libft_ ft_buffer)
target_link_libraries(libft_ ft_printf)
