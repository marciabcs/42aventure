# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 14:10:54 by mcostaes          #+#    #+#              #
#    Updated: 2015/12/08 17:03:46 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     =		colle-2

SRCS     =		colle2.c           	\
				ft_utiles.c       	\
				ft_testcolles.c

COLLES	 =		colle-00				\
				colle-01				\
				colle-02				\
				colle-03				\
				colle-04

GFLAGS   =		-Wall -Werror -Wextra


all      :       
				@make $(NAME)
								
$(NAME)  :
				gcc $(GFLAGS) -o $(NAME) $(SRCS)
								
colle00  :
				gcc $(GFLAGS) -o colle-00 colle00.c
								
colle01  :
				gcc $(GFLAGS) -o colle-01 colle01.c

colle02  :
				gcc $(GFLAGS) -o colle-02 colle02.c
								
colle03  :
				gcc $(GFLAGS) -o colle-03 colle03.c
								
colle04  :
				gcc $(GFLAGS) -o colle-04 colle04.c
								
norme    :
				norminette -R CheckForbiddenSourceHeader *.c
								
clean	:
				rm -f  $(NAME)

cleancolles:	
				rm -f $(COLLES)

colles  :		cleancolles colle00 colle01 colle02 colle03 colle04 

fclean  :		clean all
				
