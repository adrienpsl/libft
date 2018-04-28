

trick = cd src ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ' | pbcopy  ; ..

NAME = libft.a

HEADER = ft_library_header.h

#SOURCES_FILE = sources/

OBJ_DIR = $(SOURCES_FILE)obs/

SRC_DIR = $(SOURCES_FILE)src/

SRC = \
		argv/argv_contruct.c argv/src/argv_get_option.c argv/src/argv_go_prev_argv.c argv/src/argv_utils.c argv/src/get_next_argv_1.c argv/src/get_next_argv_2.c debug/print_tab.c list/double_list/double_linked_list/debug/dll_print_nb.c list/double_list/double_linked_list/debug/dll_print_str.c list/double_list/double_linked_list/dll_construct.c list/double_list/double_linked_list/src/dll_add.c list/double_list/double_linked_list/src/dll_drop_end.c list/double_list/double_linked_list/src/dll_drop_index.c list/double_list/double_linked_list/src/dll_drop_top.c list/double_list/double_linked_list/src/dll_fill_list_circular.c list/double_list/double_linked_list/src/dll_index.c list/double_list/double_linked_list/src/dll_push.c list/double_list/double_linked_list/utils.c list/double_list/double_linked_list_circular/debug/dll_c_debug_print.c list/double_list/double_linked_list_circular/dll_c_construct.c list/double_list/double_linked_list_circular/src/dll_c_add_after.c list/double_list/double_linked_list_circular/src/dll_c_copie.c list/double_list/double_linked_list_circular/src/dll_c_drop_link.c list/double_list/double_linked_list_circular/src/dll_c_iter.c list/double_list/double_linked_list_circular/src/dll_c_push_link.c list/double_list/double_linked_list_link/dll_l_construct.c list/double_list/double_linked_list_link/src/dll_l_get_content.c list/simple_list/simple_linked_list/debug/sll_print_str.c list/simple_list/simple_linked_list/sll_construct.c list/simple_list/simple_linked_list/src/drop_utils.c list/simple_list/simple_linked_list/src/sll_add.c list/simple_list/simple_linked_list/src/sll_drop_index.c list/simple_list/simple_linked_list/src/sll_drop_link.c list/simple_list/simple_linked_list_link/sll_l_construct.c memory/ft_bzero.c memory/ft_exit_lack_memory.c memory/ft_malloc_protect.c memory/ft_memalloc.c memory/ft_memccpy.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memdel.c memory/ft_memmove.c memory/ft_memset.c memory/soa.c nb/ft_atoi.c nb/ft_putnbr.c nb/ft_putnbr_fd.c printf/buffer/head_buffer.c printf/data/manage_before_printer.c printf/data/nb/float/head_double.c printf/data/nb/integer/head_integer_signed.c printf/data/nb/integer/head_interger_n.c printf/data/nb/unsigned/head_integer_unsigned.c printf/data/nb/unsigned/utils_unsigned_integer.c printf/data/nb/unsigned_variation/head_unsigned_binairy.c printf/data/nb/unsigned_variation/head_unsigned_hexa.c printf/data/nb/unsigned_variation/head_unsigned_octal.c printf/data/nb/unsigned_variation/head_unsigned_ptr.c printf/data/text/char/head_char.c printf/data/text/other/head_percent.c printf/data/text/str/manage_str.c printf/main_pfff.c printf/parseur/head_parseur.c printf/parseur/parseur_flag.c printf/parseur/parseur_flag_utils.c printf/parseur/parseur_utils.c printf/printer/function_printer.c printf/printer/head_printer.c printf/printer/utils_printer.c printf/utils_main.c sort/ft_quick_sort.c sort/quick_sort_dll.c string/char/ft_free_doublechar_tab.c string/char/ft_isalnum.c string/char/ft_isalpha.c string/char/ft_isascii.c string/char/ft_isdigit.c string/char/ft_isprint.c string/char/ft_put_uni.c string/char/ft_putchar.c string/char/ft_putchar_fd.c string/char/ft_tolower.c string/char/ft_toupper.c string/str/check_char_into_str.c string/str/ft_free_split.c string/str/ft_is_all_number.c string/str/ft_itoa.c string/str/ft_putendl.c string/str/ft_putendl_fd.c string/str/ft_putstr.c string/str/ft_putstr_fd.c string/str/ft_str_rev.c string/str/ft_strcat.c string/str/ft_strchr.c string/str/ft_strchr_dup.c string/str/ft_strchr_how_many.c string/str/ft_strchr_len.c string/str/ft_strclr.c string/str/ft_strcmp.c string/str/ft_strcpy.c string/str/ft_strdel.c string/str/ft_strdup.c string/str/ft_strequ.c string/str/ft_striter.c string/str/ft_striteri.c string/str/ft_strjoin.c string/str/ft_strlcat.c string/str/ft_strlen.c string/str/ft_strmap.c string/str/ft_strmapi.c string/str/ft_strncat.c string/str/ft_strncmp.c string/str/ft_strncpy.c string/str/ft_strndup.c string/str/ft_strnequ.c string/str/ft_strnew.c string/str/ft_strnjoin.c string/str/ft_strnstr.c string/str/ft_strrchr.c string/str/ft_strsplit.c string/str/ft_strstr.c string/str/ft_strsub.c string/str/ft_strtrim.c string/str/get_last_char_str.c string/str/index_of_char.c string/str/str_by_func.c

OBJS = $(addprefix $(SRC_DIR),$(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re