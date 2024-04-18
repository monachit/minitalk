NAME1 = client
NAME2 = server
CC = cc
CFALGS = -Wall -Wextra -Werror
SRCS1 = client.c ft_printf/ft_printf.c ft_printf/ft_adr.c ft_printf/ft_putnbr.c ft_printf/ft_allfunc.c
SRCS2 = server.c ft_printf/ft_printf.c ft_printf/ft_adr.c ft_printf/ft_putnbr.c ft_printf/ft_allfunc.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJS1)
	$(CC) $(CFALGS) -o $(NAME1) $(OBJS1)

$(NAME2) : $(OBJS2)
	$(CC) $(CFALGS) -o $(NAME2) $(OBJS2)

clean :
	rm -rf $(OBJS1) $(OBJS2)

fclean : clean
	rm -rf $(NAME1) $(NAME2)

re : fclean all 

.PHONY: all clean fclean re 