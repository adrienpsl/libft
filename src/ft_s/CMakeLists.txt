# *------------------------------------*\
#
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_s.init.c
        ft_s.add.c
        ft_s.free.c

        #[[ test]]
        tests/ft_s.add.init.test.c
        tests/main.test.c
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__}  libft)