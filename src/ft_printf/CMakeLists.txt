# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        src/ft_pf.catch_format.c
        src/ft_pf.get_number.c
        src/ft_pf.get_str.c
        src/ft_pf.print.c
        src/ft_pf.utils.c
        src/ft_printf.c

        #[[ test]]
        tests/ft_pf.catch_format.test.c
        tests/ft_pf.get_nb.test.c
        tests/ft_pf.get_str.test.c
        tests/ft_pf.main.test.c
        tests/ft_pf.print.test.c
        tests/ft_printf.test.c
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)