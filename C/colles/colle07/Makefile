# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaoui <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 17:23:22 by mdaoui            #+#    #+#              #
#    Updated: 2016/02/16 17:24:35 by mdaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCS =  ft_read_data.c ft_hash.c ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRCS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
