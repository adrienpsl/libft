# *------------------------------------*\
# link les
# *------------------------------------*/
target_sources(${__LIB_NAME__}
        PUBLIC
        #[[ src ]]
        ft_capitalize.c
        ft_char_test.c
        ft_isalnum.c
        ft_isalpha.c
        ft_isascii.c
        ft_isdigit.c
        ft_isprint.c
        ft_isspace.c
        ft_putchar.c
        ft_putchar_fd.c
        ft_putendl.c
        ft_putendl_fd.c
        ft_putnstr.c
        ft_putsteret.c
        ft_str_free.c
        ft_str_replace.c
        ft_strcat.c
        ft_strchr.c
        ft_strchrreplace.c
        ft_strcmp.c
        ft_strdup.c
        ft_streq.c
        ft_strjoin.c
        ft_strlcat.c
        ft_strlen.c
        ft_strnew.c
        ft_strsub.c
        str.ft_str_search.c

        #[[ test]]
        )


target_include_directories(${__LIB_NAME__} PUBLIC includes)
target_link_libraries(${__LIB_NAME__}  libft)