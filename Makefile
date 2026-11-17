NAME = libftprintf.a

CC = cc

SRC = ft_printf.c ft_print_csi.c ft_print_xp.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clear fclear re