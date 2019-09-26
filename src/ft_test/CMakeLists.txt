# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        libft_utils_test.c

        #[[ test]]
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)