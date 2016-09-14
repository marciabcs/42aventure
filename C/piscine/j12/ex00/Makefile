# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/12 09:23:54 by mcostaes          #+#    #+#              #
#    Updated: 2016/03/15 11:15:55 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_display_file

SRC	=	display_file.c		

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
