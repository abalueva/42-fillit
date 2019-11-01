# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 23:12:52 by abalueva          #+#    #+#              #
#    Updated: 2019/10/31 23:39:42 by abalueva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = vld_funcs.c ttr_funcs.c brd_funcs.c solver.c main.c
OBJECTS = vld_funcs.o ttr_funcs.o brd_funcs.o solver.o main.o
NAME = fillit
INCLUDE = fillit.h

all: $(NAME)

%.o:
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDE)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -L libft -lft -o $(NAME) $(OBJECTS)

.PHONY: all clean flcean re

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all