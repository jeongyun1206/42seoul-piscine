CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = dp_square.c get_confirm_map.c get_map_by_file.c main.c dp_prt_square.c get_fill_map.c get_map_info.c
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
