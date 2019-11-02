/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:21:54 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/01 22:58:27 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
//#include "libft/libft.h"

typedef struct	s_tetrimino
{
	int					**coors;
	char				alph;
	struct s_tetrimino	*next;
	struct s_tetrimino	*prev;
}				t_etrimino;

int				vld_file(const int fd, t_etrimino **head);
int				vld_block(char *line);
int				vld_newline(char *line);
void			vldk_hash(char *line, int i, int *counter);

t_etrimino		*ttr_create(char *block, char alph);
void			correct_coors(int ***coors, int min_x, int min_y);
t_etrimino		*ttr_init(t_etrimino **elem, char **array, char alpha);
void			ttr_add(t_etrimino **prev, t_etrimino *new);
void			ttr_clr(t_etrimino **elem);

void			print_board(char ***board, int size);
char			**brd_create(int size);
int				brd_check_x(char **board, int size, t_etrimino *elem, int *xy);
int				brd_space(char **board, int size, t_etrimino *elem, int *xy);
int				**brd_rmv(char ***board, int size, char alph, int **min);
int				brd_put(char ***board, t_etrimino *elem, int *xy);
void			brd_clr(char **board, int size);

int				*clear_xy(int **array, int size);
int				brd_find_size(int ttrmns);
int				solver(char ***board, int size, t_etrimino *elem);
void			real_solver(t_etrimino *head, int block_count);

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
