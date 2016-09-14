# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 15:08:10 by mcostaes          #+#    #+#              #
#    Updated: 2016/02/03 14:17:44 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME1	=	a1

SRC1	=	main2.c		\
			ex00/ft_create_elem.c   \
			ex01/ft_list_push_back.c	\
			ex02/ft_list_push_front.c  \
			ex03/ft_list_size.c		\
			ex04/ft_list_last.c   \
			ex05/ft_list_push_params.c	\
			ex06/ft_list_clear.c   \
			ex07/ft_list_at.c		\
			ex08/ft_list_reverse.c	



NAME2	=	a2

SRC2	=	main3.c		\
		ex00/ft_create_elem.c   \
		ex01/ft_list_push_back.c	\
		ex02/ft_list_push_front.c  \
		ex05/ft_list_push_params.c	\
		ex09/ft_list_foreach.c		\
		ex10/ft_list_foreach_if.c	\
		ex11/ft_list_find.c		\
		ex12/ft_list_remove_if.c	\
		ex13/ft_list_merge.c


H_DIR	=	ex01

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all	:	
		@make $(NAME1)

1	:	
		gcc $(FLAGS) -o $(NAME1) -I$(H_DIR) $(SRC1)
2	:	
		gcc $(FLAGS) -o $(NAME2) -I$(H_DIR) $(SRC2)

clean	:	
		rm -f $(OBJS)
		rm -f *~

fclean	:	clean
		$(RM) $(NAME1)
		$(RM) $(NAME2)

