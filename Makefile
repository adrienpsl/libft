#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 19:25:43 by nbrucker          #+#    #+#              #
#    Updated: 2017/12/02 19:25:43 by nbrucker         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

INCSDIR = includes/

SRCSDIR = src/

OBJSDIR = objs/

SRCS = \
ft_systm.check_file.c \
ft_array.at.c \
ft_array.cmp.c \
ft_array.cmp_utils.c \
ft_array.copy.c \
ft_array.double_size.c \
ft_array.extract_by_func.c \
ft_array.find.c \
ft_array.free.c \
ft_array.free_func.c \
ft_array.func.c \
ft_array.func.utils.c \
ft_array.init.c \
ft_array.insert.c \
ft_array.next.c \
ft_array.prev.c \
ft_array.push.c  \
ft_array.remove.c \
ft_array.remove_from.c \
ft_array.remove_func.c \
ft_array.slice.c \
ft_array.slice_and_remove.c \
ft_array.sort.utils.c \
ft_array.sort_bubble.c \
ft_array.utils.c \
ft_atoi.c \
ft_bzero.c \
ft_catch_options.c \
ft_free_split.c \
ft_io.catch_options.c \
ft_itoa.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memdup.c \
ft_memmove.c \
ft_memset.c \
ft_memswap.c \
ft_pf.catch_format.c \
ft_pf.get_number.c \
ft_pf.get_str.c \
ft_pf.print.c \
ft_pf.utils.c \
ft_printf.c \
ft_pstrjoin_chr.c \
ft_putnstr.c \
ft_s.add.c \
ft_s.add_at.c \
ft_s.addn.c \
ft_s.clear.c \
ft_s.free.c \
ft_s.init.c \
ft_s.remove_from.c \
ft_s.replace_str.c \
ft_s.search_str.c \
ft_str.add_buffer.c \
ft_str.by_func.c \
ft_str.char_helper_1.c \
ft_str.char_helper_2.c \
ft_str.find_str.c \
ft_str.free.c \
ft_str.ncmp.c \
ft_str.replace.c \
ft_str.search_start.c \
ft_str_print_split.c \
ft_str_split_count.c \
ft_strcat.c \
ft_strchr.c \
ft_strchrreplace.c \
ft_strcmp.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlen.c \
ft_strsplit.add.c \
ft_strsplit.c \
ft_strsplit.cmp.c \
ft_strsplit.copy.c \
ft_strsplit.remove.c \
ft_strsplit.search.c \
ft_strsub.c \
ft_systm.c \
ft_systm.find_in_directory.c \
ft_systm.find_in_path.c \
ft_systm.get_current_path.c \
ft_log.utils.c \
ft_systm.check_exe.c

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -I $(INCSDIR) -o $@ -c $<

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
