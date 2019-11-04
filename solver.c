/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:36:47 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/03 19:52:25 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		solver_put(char ***board, t_etrimino **elem, int *xy)
{
	brd_put(board, *elem, xy);
	*elem = (*elem)->next;
	clear_xy(&xy, 2);
}

int			solver_rmv(char ***board, int size, t_etrimino **elem, int *xy)
{
	if ((*elem)->prev == NULL)
	{
		free(xy);
		return (0);
	}
	*elem = (*elem)->prev;
	brd_rmv(board, size, (*elem)->alph, &xy);
	return (1);
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
		flag = elem->next == NULL ? 0 : 1;
		if (brd_space(*board, size, elem, xy))
			solver_put(board, &elem, xy);
		else
		{
			if (solver_rmv(board, size, &elem, xy) == 0)
				return (0);
			flag = 1;
		}
	}
	free(xy);
	return (1);
}

int			brd_find_size(int ttrmns)
{
	int brd_size;

	brd_size = 2;
	while (brd_size * brd_size < ttrmns * 4)
		brd_size++;
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
		array_free(board, brd_size);
		board = brd_create(++brd_size);
	}
	print_board(&board, brd_size);
	array_free(board, brd_size);
}
