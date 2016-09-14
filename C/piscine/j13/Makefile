# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 15:08:10 by mcostaes          #+#    #+#              #
#    Updated: 2016/02/04 11:28:54 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME1	=	j13

SRC1	=	main.c		\
			ex00/btree_create_node.c   \
			ex01/btree_apply_prefix.c	\
			ex02/btree_apply_infix.c  \
			ex03/btree_apply_suffix.c		\
			ex04/btree_insert_data.c   \
			ex05/btree_search_item.c	\
			ex06/btree_level_count.c

H_DIR	=	ex00

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all	:	
		@make $(NAME1)

1	:	
		gcc $(FLAGS) -o $(NAME1) -I$(H_DIR) $(SRC1)

clean	:	
		rm -f $(OBJS)
		rm -f *~

fclean	:	clean
		$(RM) $(NAME1)

