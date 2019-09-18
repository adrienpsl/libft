


# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        src/ft_systm.find_in_directory.c
        src/ft_systm.find_in_path.c

        #[[ test]]
        tests/ft_systm.main.test.c
        tests/ft_systm.find_in_directory.test.c
        tests/ft_systm.find_in_path.test.c
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)