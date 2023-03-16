NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_atoi.c\
		ft_isdigit.c\
		ft_lst.c\
		ft_split.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\

OBJECTS = $(SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
