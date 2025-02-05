NAME = libft.a
FLAG = -Wall -Wextra -Werror
PATH_SRC = ./srcs/
SRC = $(PATH_SRC)ft_putchar.c $(PATH_SRC)ft_swap.c $(PATH_SRC)ft_putstr.c $(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_strcmp.c
OBJ = $(PATH_SRC)ft_putchar.o $(PATH_SRC)ft_swap.o $(PATH_SRC)ft_putstr.o $(PATH_SRC)ft_strlen.o $(PATH_SRC)ft_strcmp.o
PATH_HEADER = ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

$(PATH_SRC)%.o: $(PATH_SRC)%.c
	cc $(FLAG) -I$(PATH_HEADER) -c $< -o $@ 

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all



