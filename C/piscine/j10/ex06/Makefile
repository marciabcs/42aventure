# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 14:11:12 by mcostaes          #+#    #+#              #
#    Updated: 2016/01/07 14:48:55 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	do-op

SRC	=	do_op.c			\
		ft_fonctions.c	\
		ft_putchar.c	\
		ft_putnbr.c		\
		ft_putstr.c		\
		ft_atoi.c	

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all	:	
		@make $(NAME)

$(NAME)	:	
		gcc $(FLAGS) -o $(NAME) $(SRC)

clean	:	
		rm -f $(OBJS)
		rm -f *~

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
