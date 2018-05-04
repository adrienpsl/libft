

trick = cd src ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ' | pbcopy  ; ..

NAME = libft.a

HEADER = $(SOURCES_FILE)ft_library_header.h

SOURCES_FILE = sources/

OBJ_DIR = $(SOURCES_FILE)obs/

SRC_DIR = $(SOURCES_FILE)src/

SRC := $(shell cd ${SRC_DIR} ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ')

OBJS = $(addprefix $(SRC_DIR),$(SRC:.c=.o))

#$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#	@mkdir -p $(OBJ_DIR)
#	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
#
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