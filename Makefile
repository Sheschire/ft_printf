SRC        =   	

OBJ				= $(SRC:.c=.o)

CC				= clang

FLAGS			= -Wall -Werror -Wextra

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJ)
					ar rcs $@ $^

%.o: %.c
					$(CC) -I. -o $@ -c $? $(FLAGS)

clean:
					rm -f $(OBJ) $(OBJ_BONUS)

fclean:			clean
					rm -f $(NAME)

re:				fclean all

.PHONY: all bonus clean fclean re