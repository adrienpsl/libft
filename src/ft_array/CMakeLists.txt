

target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_array.push.c
        ft_array.add_at.c
        ft_array.at.c
        ft_array.bubble.c
        ft_array.cmp.c
        ft_array.cmp_utils.c
        ft_array.copy.c
        ft_array.double_size.c
        ft_array.free.c
        ft_array.func.c
        ft_array.init.c
        ft_array.next.c
        ft_array.prev.c
        ft_array.remove.c
        ft_array.utils.c
        ft_array.func_cmp.c


        #[[ test]]
        tests/ft_array.at.test.c
        tests/ft_array.init.test.c
        tests/ft_array.push.test.c
        tests/ft_array.bubble.test.c
        tests/ft_array.prev.next.test.c
        tests/ft_array.cmp.test.c
        tests/main.test.c
        )

target_include_directories(libft PUBLIC includes)
