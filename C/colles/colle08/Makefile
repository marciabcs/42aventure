# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckramer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 11:32:47 by ckramer           #+#    #+#              #
#    Updated: 2016/03/03 11:45:26 by ckramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

NAME	=	puissance4

SRCS	=	pss4_game.c pss4_tests_game.c pss4_print.c pss4_ai_player.c \
			pss4_ai_test_tab.c pss4_utilities.c ft_atoi.c

OBJ		=	$(SRCS:.c=.o)

all: gen
	
gen:
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
