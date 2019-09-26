target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
       src/ft_array.at.c
       src/ft_array.cmp.c
       src/ft_array.cmp_utils.c
       src/ft_array.copy.c
       src/ft_array.double_size.c
       src/ft_array.extract_by_func.c
       src/ft_array.find.c
       src/ft_array.free.c
       src/ft_array.free_func.c
       src/ft_array.func.c
       src/ft_array.func.utils.c
       src/ft_array.init.c
       src/ft_array.insert.c
       src/ft_array.next.c
       src/ft_array.prev.c
       src/ft_array.push.c
       src/ft_array.remove.c
       src/ft_array.remove_from.c
       src/ft_array.remove_func.c
       src/ft_array.slice.c
       src/ft_array.slice_and_remove.c
       src/ft_array.sort.utils.c
       src/ft_array.sort_bubble.c
       src/ft_array.utils.c

        #[[ test]]
       tests/ft_array.at.test.c
       tests/ft_array.bubble.test.c
       tests/ft_array.cmp.test.c
       tests/ft_array.copy.test.c
       tests/ft_array.double_size.test.c
       tests/ft_array.extract_by_func.test.c
       tests/ft_array.find.test.c
       tests/ft_array.free.test.c
       tests/ft_array.func.test.c
       tests/ft_array.init.test.c
       tests/ft_array.main.test.c
       tests/ft_array.prev.next.test.c
       tests/ft_array.push.test.c
       tests/ft_array.remove.test.c
       tests/ft_array.remove_from.test.c
       tests/ft_array.slice.test.c
       tests/ft_array.slice_and_remove.test.c
       tests/ft_array.utils.test.c
        )

target_include_directories(libft PUBLIC includes)
