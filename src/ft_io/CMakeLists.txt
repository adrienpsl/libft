# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_atoi.c
        ft_itoa.c
        ft_io.catch_options.c

        #[[ test]]
        tests/ft_io.catch_options.test.c
        tests/ft_io.main.test.c
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)