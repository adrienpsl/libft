# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_log.c

        #[[ test]]
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__}  libft)