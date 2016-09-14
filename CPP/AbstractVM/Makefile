# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/07 14:56:46 by mcostaes          #+#    #+#              #
#    Updated: 2016/09/07 15:12:23 by mcostaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =  AbstractVM

SRC    =    main.cpp 		\
			abstractvm.cpp	\
			factory.cpp		\
			exception.cpp	\
			lexer.cpp		\
			parser.cpp		

OBJS    =    $(SRC:.cpp=.o)

FLAGS    =    -Wall -Wextra -Werror

all    :    
	        @make $(NAME)

$(NAME)   :    
	        g++ $(FLAGS) -o $(NAME)  $(SRC)

clean    :    
	        rm -f $(OBJS)
			 rm -f *~

fclean    :    clean
	        $(RM) $(NAME)

re		: fclean all
