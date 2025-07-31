NAME = libftprintf.a
SRCS = ft_printf.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putunsigned.c \
	ft_putnbr_base.c
OBJS = $(SRCS:.c=.o)


GREEN=\033[0;32m
SET_DEF=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@cc -Wall -Wextra -Werror $(SRCS) -c -o $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
