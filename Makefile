
NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRC = 	parsing.c\
		moves.c\
		dump.c\
		helper.c\
		sorting.c\
		do_a.c\
		do_b.c\

LIBFT = libft/libft.a

PATH_LIBFT = libft

OBJ = $(SRC:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)

${LIBFT}	:
	make -C ${PATH_LIBFT}

%.o : %.c $(INCLUDES) ${LIBFT}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) ${LIBFT}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(RM) $(OBJ)
	make clean -C ${PATH_LIBFT}

fclean: clean
	$(RM) $(NAME)
	make fclean -C ${PATH_LIBFT}

re: fclean all
