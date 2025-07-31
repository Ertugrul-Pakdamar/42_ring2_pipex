CC = cc
CFLAGS = -Wall -Wextra -Werror

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
	@echo "$(GREEN)ft_printf: libftprintf.a created successfully$(SET_DEF)"

clean:
	@rm -rf $(OBJS)
	@echo "$(GREEN)ft_printf: object files removed$(SET_DEF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)ft_printf: libftprintf.a removed$(SET_DEF)"

re: fclean all
