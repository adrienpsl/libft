# *------------------------------------*\
#
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_s.init.c
        ft_s.add.c
        ft_s.addn.c
        ft_s.free.c
        ft_s.clear.c
        ft_s.remove_from.c
        ft_s.replace_str.c
        ft_s.search_str.c

        #[[ test]]
        tests/ft_s.init.test.c
        tests/ft_s.add.test.c
        tests/ft_s.free.test.c
        tests/ft_s.clear.test.c
        tests/ft_s.remove_from.test.c
        tests/ft_s.replace_str.test.c
        tests/main.test.c
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__}  libft)