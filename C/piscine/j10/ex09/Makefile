# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 15:08:10 by mcostaes          #+#    #+#              #
#    Updated: 2016/01/07 15:08:42 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_advanced_do-op

SRC	=	advanced_do_op.c		\
		ft_fonctions.c			\
		ft_putchar.c			\
		ft_putnbr.c				\
		ft_putstr.c				\
		ft_atoi.c				\
		ft_strcmp.c	

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
