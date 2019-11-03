/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:21:54 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 19:59:56 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_tetrimino
{
	int					**coors;
	char				alph;
	struct s_tetrimino	*next;
	struct s_tetrimino	*prev;
}				t_etrimino;

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

int				*clear_xy(int **array, int size);
int				*clear_symbls(int array[3], int size);
void			array_free(char **board, int size);
void			print_board(char ***board, int size);

void			vld_hash(char *line, int i, int *counter);
int				vld_newline(char *line);
int				vld_symbls(char *line, int symbls[3], int *counter);

int				vld_block(char *line);
int				vld_xtr(char a_r[2], char *buff, t_etrimino **head, int r_c[2]);
int				vld_file(const int fd, t_etrimino **head);

void			ttr_correct(int ***coors, int min_x, int min_y);
int				*ttr_init_hash(t_etrimino **elem, int ijk[3], int min_xy[2]);

t_etrimino		*ttr_init(t_etrimino **elem, char **array, char alpha);
t_etrimino		*ttr_create(char *block, char alph);
void			ttr_add(t_etrimino *prev, t_etrimino *new);
void			ttr_free(t_etrimino **elem);

char			**brd_create(int size);
int				**brd_rmv(char ***board, int size, char alph, int **min);
int				brd_check_x(char **board, int size, t_etrimino *elem, int *xy);
int				brd_space(char **board, int size, t_etrimino *elem, int *xy);
int				brd_put(char ***board, t_etrimino *elem, int *xy);

void			solver_put(char ***board, t_etrimino **elem, int *xy);
int				solver_rmv(char ***board, int size, t_etrimino **elem, int *xy);
int				solver(char ***board, int size, t_etrimino *elem);
int				brd_find_size(int ttrmns);
void			real_solver(t_etrimino *head, int block_count);

#endif
