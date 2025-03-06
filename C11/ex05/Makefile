NAME = do-op
SRCS_PATH = ./srcs/
SRCS = $(SRCS_PATH)calculate.c $(SRCS_PATH)ft_atoi.c $(SRCS_PATH)ft_operators.c $(SRCS_PATH)ft_strlen.c $(SRCS_PATH)print_nbr.c $(SRCS_PATH)main.c
OBJS = $(SRCS_PATH)calculate.o $(SRCS_PATH)ft_atoi.o $(SRCS_PATH)ft_operators.o $(SRCS_PATH)ft_strlen.o $(SRCS_PATH)print_nbr.o $(SRCS_PATH)main.o
HEADER_PATH = ./includes/
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAG) $^ -o $@

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c
	cc $(FLAG) -I$(HEADER_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all
