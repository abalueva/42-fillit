# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 23:12:52 by abalueva          #+#    #+#              #
#    Updated: 2019/11/01 20:13:31 by abalueva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = ft_putchar.c ft_putstr.c ft_strsub.c additional.c \
			vld_funcs.c ttr_funcs.c brd_funcs.c solver.c main.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strsub.o additional.o \
			vld_funcs.o ttr_funcs.o brd_funcs.o solver.o main.o
NAME = fillit
INCLUDE = fillit.h

all: $(NAME)

%.o:
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDE) -g

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $(NAME) $(OBJECTS) -g

.PHONY: all clean flcean re

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all