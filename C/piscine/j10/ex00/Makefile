# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 14:58:15 by mcostaes          #+#    #+#              #
#    Updated: 2016/01/06 15:03:42 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB	=	libft.a

SRC	=	ft_putchar.c	\
		ft_putstr.c	\
		ft_strcmp.c	\
		ft_strlen.c	\
		ft_swap.c

SRC_DIR	=	srcs/

SOURCES	=	$(addprefix $(SRC_DIR),$(SRC))

H_DIR	=	includes
	
OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all	:	lib

lib	:	
		gcc $(FLAGS) -I$(H_DIR) -c $(SOURCES)
		ar rc $(LIB) $(OBJS)
		ranlib $(LIB)

clean	:	
		rm -f $(OBJS)
		rm -f *~

fclean	:	clean
		rm -f $(LIB)

re	:	fclean all
