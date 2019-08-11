# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_bzero.c
        ft_memalloc.c
        ft_memccpy.c
        ft_memchr.c
        ft_memcmp.c
        ft_memcpy.c
        ft_memdel.c
        ft_memdup.c
        ft_memmove.c
        ft_memset.c
        ft_memswap.c

        #[[ test]]
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__}  libft)