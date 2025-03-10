NAME = push_swap
libft = libft/libft.a
ft_printf = ft_printf/ft_printf.a
checker_linux = checker_linux
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c swap.c rotate.c revrotate.c push.c algo.c sort.c stack.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(libft) $(ft_printf) 
		 $(CC) $(CFLAGS) $(OBJ) $(libft) $(ft_printf) -o $(NAME)
$(libft):
	make -C libft
$(ft_printf):
	make -C ft_printf
$(checker_linux):
	curl -o $(checker_linux)
	chmod +x $(checker_linux)

test: all $(checker_linux)
	@echo "Testing push_swap with checker..."
	@ARG="4 2 3 1"; ./push_swap $$ARG | ./$(checker_linux) $$ARG

%.o: %.c	
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean
	make -C libft fclean
	
re: fclean all

run: re
	valgrind ./$(NAME)