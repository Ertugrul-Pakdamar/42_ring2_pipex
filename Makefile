NAME = pipex
LIBS = libft/libft.a ft_printf/libftprintf.a

SRC = ft_main.c \
	srcs/* \
	get_next_line/* \


GREEN=\033[0;32m
SET_DEF=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@make -C ft_printf
	@cc -Wall -Wextra -Werror $(SRC) $(LIBS) -o $(NAME) -Ilibft -Ift_printf -Iget_next_line -Iincludes
	@echo "$(GREEN)Project Compiled Successfully$(SET_DEF)"

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@echo "$(GREEN)Project Cleaned.$(SET_DEF)"

fclean:
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "$(GREEN)Project Cleaned.$(SET_DEF)"

re: fclean all
