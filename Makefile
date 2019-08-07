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

SRCS = array.func.c \
       array.handle.c \
       array.sort.c \
       ft_atoi.c \
       ft_buffer.c \
       ft_bzero.c \
       ft_capitalize.c \
       ft_catch_options.c \
       ft_char_test.c \
       ft_free_split.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_isspace.c \
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
       ft_printf.c \
       ft_putchar.c \
       ft_putchar_fd.c \
       ft_putendl.c \
       ft_putendl_fd.c \
       ft_putnstr.c \
       ft_putsteret.c \
       ft_replace.c \
       ft_str_free.c \
       ft_str_print_split.c \
       ft_str_split_count.c \
       ft_strcat.c \
       ft_strchr.c \
       ft_strchrreplace.c \
       ft_strcmp.c \
       ft_strdup.c \
       ft_streq.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlen.c \
       ft_strnew.c \
       ft_strsplit.add.c \
       ft_strsplit.c \
       ft_strsplit.cmp.c \
       ft_strsplit.copy.c \
       ft_strsplit.func.c \
       ft_strsplit.mix.c \
       ft_strsplit.remove.c \
       ft_strsplit.search.c \
       ft_strsub.c \
       ft_testing_function.c \
       get_next_line.c \
       str.ft_str_search.c \

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
