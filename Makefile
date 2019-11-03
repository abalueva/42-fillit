# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 23:12:52 by abalueva          #+#    #+#              #
#    Updated: 2019/11/02 19:49:20 by abalueva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = additional_ft.c additional.c additional_ttr.c additional_vld.c \
			validation.c tetrimino.c board.c solver.c main.c
OBJECTS = additional_ft.o additional.o additional_ttr.o additional_vld.o \
			validation.o tetrimino.o board.o solver.o main.o
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