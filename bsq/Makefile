# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 22:05:16 by hguo              #+#    #+#              #
#    Updated: 2025/02/05 18:44:29 by yanzhao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./srcs/

SRC = main.c write_to_file.c basic1.c check_char_old_map.c check_line_col_oldmap.c check_solution.c \
		count_col.c find_fill.c load_oldmap.c prep_map.c print_map.c \

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

SRCS_OBJ = ${SRCS:.c=.o}

HEADER_DIR = ./includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OUTPUT = bsq

.c.o:
	${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o ${<:.c=.o}

${OUTPUT} : ${SRCS_OBJ}
	${CC} ${CFLAGS} -o ${OUTPUT} ${SRCS_OBJ}

all : ${OUTPUT}

clean :
	rm -f ${SRCS_OBJ}

fclean : clean
	rm -f ${OUTPUT}

re : fclean all

.PHONY : all clean fclean re
