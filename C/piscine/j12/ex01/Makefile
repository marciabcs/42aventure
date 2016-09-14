# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/12 09:25:58 by mcostaes          #+#    #+#              #
#    Updated: 2016/03/15 11:16:31 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_cat

SRC	=	ft_cat.c		

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all	:	
		@make $(NAME)

$(NAME)	:	
		gcc $(FLAGS) -o $(NAME) $(SRC)

clean	:	
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
