/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brd_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:29:40 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/01 22:37:37 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

char		**brd_create(int size)
{
	int		x;
	int		y;
	char	**board;

	x = -1;
	y = -1;
	board = (char **)malloc(sizeof(char *) * (size));
	while (++y < size)
	{
		board[y] = (char *)malloc(sizeof(char) * size);
		while (++x < size)
			board[y][x] = 46;
		x = -1;
	}
	return (board);
}

int			**brd_rmv(char ***board, int size, char alph, int **min)
{
	int x;
	int y;
	int flag;

	x = -1;
	y = -1;
	flag = 1;
	while (++y < size)
	{
		while (++x < size)
			if ((*board)[y][x] == alph)
			{
				if (flag)
				{
					(*min)[0] = x;
					(*min)[1] = y;
					flag = 0;
				}
				(*min)[0] = x <= (*min)[0] ? x : (*min)[0];
				(*min)[1] = y <= (*min)[1] ? y : (*min)[1];
				(*board)[y][x] = 46;
			}
		x = -1;
	}
	(*min)[0]++;
	return (min);
}

int			brd_put(char ***board, t_etrimino *elem, int *xy)
{
	int i;

	i = -1;
	while (++i < 4)
		(*board)[elem->coors[i][1] + xy[1]][elem->coors[i][0] + xy[0]] =
				elem->alph;
	return (1);
}

void		brd_clr(char **board, int size)
{
	int y;

	y = -1;
	while (++y < size)
		free(board[y]);
	free(board);
}
