# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_free_split.c
        ft_str_print_split.c
        ft_str_split_count.c
        ft_strsplit.add.c
        ft_strsplit.c
        ft_strsplit.cmp.c
        ft_strsplit.copy.c
        ft_strsplit.remove.c
        ft_strsplit.search.c
        #[[ test]]
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)