NAME	=	libftprintf.a
LIBDIR	=	./libft/
LIBFT	=	libft.a

SRCS	=	ft_printf.c\
			ft_convert.c\
			ft_flags_status.c\
			ft_flags_update.c\
			ft_print_int.c\
			ft_print_str.c\
			ft_check_char.c\
			ft_calcul_malloc.c

OBJS	=	$(SRCS:.c=.o)
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

$(NAME)		:	$(OBJS)
		make all -C $(LIBDIR)
		cp $(LIBDIR)/$(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

all		:	$(NAME)

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBDIR)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBDIR)

re		:	fclean all

.PHONY	:	all re clean fclean