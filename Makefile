NAME = push_swap

NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRC = 	mandatory/parsing.c\
		mandatory/moves.c\
		mandatory/dump.c\
		mandatory/helper.c\
		mandatory/sorting.c\
		mandatory/do_a.c\
		mandatory/do_b.c\
		commun/ft_digit.c\
		commun/ft_lst.c\
		commun/ft_split.c\

OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/checker.c\
			bonus/parsing_bonus.c\
			bonus/moves_b.c\
			bonus/ft_strtrim.c\
			commun/ft_digit.c\
			commun/ft_lst.c\
			commun/ft_split.c\
			commun/get_next_line.c\
			commun/get_next_line_utils.c\

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = mandatory/push_swap.h

INCLUDES_BONUS = bonus/push_swap_bonus.h

all: $(NAME)

bonus :$(NAME_BONUS)

mandatory/%.o: Mandatory/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: Bonus/%.c $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all
