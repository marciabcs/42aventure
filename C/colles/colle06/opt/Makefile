# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouaret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 16:38:36 by mouaret           #+#    #+#              #
#    Updated: 2016/02/02 14:27:34 by mouaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main_utils

SRC1 = ../ex00/ft_pile.c ../ex00/ft_utils.c main_ho.c 

HEADERS = ft_utils.h ft_pile.h ft_stack.h ft_expr.h ft_scan.h ft_eval.h		\

OBJS = $(SRC:.c=.o)

OPTIONS = -Wall -Werror -Wextra -I../opt

all:	ho1

$(NAME): $(SRC) $(HEADERS)
	gcc $(OPTIONS) -o $(NAME) $(SRC) 

clean:
	rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)
	rm ho1

re:	fclean	all

norm:
	@norminette $(SRC)

EXPR1 = "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1"

ho1:	$(SRC1)
	@gcc $(OPTIONS) -o ho1 $(SRC1) -I../ex00

tst1: 	ho1
	./ho1 1 + 1 - 2 * 3 / 4 % 5
