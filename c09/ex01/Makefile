CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ./root/libft.a
OBJS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
SRCS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
HEADER = includes/ft.h

$(TARGET) : $(OBJS)
	ac -rc $@ $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) -c $(CFLAGS) -I $(HEADER) $(SRCS)

all : $(TARGET)
