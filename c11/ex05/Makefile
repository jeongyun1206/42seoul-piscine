CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SRCS = doop.c set_function.c cal_function.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFALGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

re : fclean all

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
