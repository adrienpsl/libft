# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_atoi.c
        ft_catch_options.c
        ft_itoa.c
        get_next_line.c

        #[[ test]]
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__}  libft)