# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__} PUBLIC
        #[[ src ]]
        src/ft_putnstr.c
        src/ft_str.add_buffer.c
        src/ft_str.char_helper_1.c
        src/ft_str.char_helper_2.c
        src/ft_str.free.c
        src/ft_str.search_start.c
        src/ft_strcat.c
        src/ft_strchr.c
        src/ft_strchrreplace.c
        src/ft_strcmp.c
        src/ft_strjoin.c
        src/ft_strdup.c
        src/ft_strlen.c
        src/ft_strsub.c

        src/ft_str.replace.c
        src/ft_str.find_str.c
        src/ft_str.ncmp.c
        )

target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__} libft)