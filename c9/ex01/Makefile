CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = $(SRCS:.c=.o)
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
HEADER = includes

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

re : fclean all

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
