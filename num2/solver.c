/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:36:47 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/31 22:23:12 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*clear_xy(int **array, int size)
{
	while (--size >= 0)
		(*array)[size] = 0;
	return (*array);
}

int			solver(char ***board, int size, t_etrimino *elem)
{
	int flag;
	int	*xy;

	flag = 1;
	xy = (int *)malloc(sizeof(int) * 2);
	clear_xy(&xy, 2);
	while (flag)
	{
		if (elem->next == NULL)
			flag = 0;
		if (brd_space(*board, size, elem, xy))
		{
			brd_put(board, elem, xy);
			elem = elem->next;
			clear_xy(&xy, 2);
		}
		else
		{
			if (elem->prev == NULL)
				return (0);
			flag = 1;
			elem = elem->prev;
			brd_rmv(board, size, elem->alph, &xy);
		}
	}
	free(xy);
	return (1);
}

int			brd_find_size(int ttrmns)
{
	int brd_size;

	brd_size = 1;
	ttrmns = ttrmns * 4;
	while (++brd_size <= 11)
	{
		if (brd_size * brd_size >= ttrmns)
			return (brd_size);
	}
	return (brd_size);
}

void		real_solver(t_etrimino *head, int ttr_count)
{
	int		brd_size;
	char	**board;

	brd_size = brd_find_size(ttr_count);
	board = brd_create(brd_size);
	while (solver(&board, brd_size, head) == 0)
	{
		brd_clr(board, 4);
		board = brd_create(++brd_size);
	}
	print_board(&board, brd_size);
}
