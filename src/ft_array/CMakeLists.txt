

target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_array.add.c
        ft_array.bubble.c
        ft_array.cmp.c
        ft_array.free.c
        ft_array.func.c
        ft_array.init.c
        ft_array.next.c
        ft_array.prev.c
        ft_array.remove.c
        ft_array.utils.c
        ft_array_at.c
        ft_array_copy.c

        #[[ test]]
        tests/ft_array.test.c
        tests/ft_array.init.test.c
        )

target_include_directories(libft PUBLIC includes)
