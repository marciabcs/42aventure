# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:47:44 by dcastela          #+#    #+#              #
#    Updated: 2016/03/22 14:32:46 by dcastela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc -Wall -Werror -Wextra

RM		=	rm -f

NAME	=	bsq

SRCS	=	bsq.c bsq_read.c \
			bsq_search_square.c bsq_write_map.c

OBJS	=	bsq.o bsq_read.o \
			bsq_search_square.o bsq_write_map.o

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

$(OBJS)	:	$(SRCS)	
			$(CC) -c $(SRCS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

test	:	all clean
