# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/12 09:25:05 by mcostaes          #+#    #+#              #
#    Updated: 2016/03/15 11:27:41 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_tail

SRC	=	ft_tail.c	ft_support_tail.c	

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
