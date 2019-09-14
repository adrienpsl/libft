# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        ft_putnstr.c
        ft_str.add_buffer.c
        ft_str.char_helper_1.c
        ft_str.char_helper_2.c
        ft_str.free.c
        ft_str.search_start.c
        ft_strcat.c
        ft_strchr.c
        ft_strchrreplace.c
        ft_strcmp.c
        ft_strdup.c
        ft_strlen.c
        ft_strsub.c#[[ src ]]

        )

target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)