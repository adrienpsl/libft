

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
        ft_array.double_size.c

        #[[ test]]
        tests/ft_array.test.c
        tests/ft_array.init.test.c
        tests/ft_array.add.test.c
        tests/ft_array.main.test.c
        )

target_include_directories(libft PUBLIC includes)
