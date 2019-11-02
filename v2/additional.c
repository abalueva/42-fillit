/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:38:08 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/01 20:36:48 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*clear_xy(int **array, int size)
{
	while (--size >= 0)
		(*array)[size] = 0;
	return (*array);
}

int			brd_check_x(char **board, int size, t_etrimino *elem, int *xy)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (elem->coors[i][1] + xy[1] == size)
			return (0);
		if (board[elem->coors[i][1] + xy[1]][elem->coors[i][0] + xy[0]] != 46)
			return (0);
	}
	return (1);
}

int			brd_space(char **board, int size, t_etrimino *elem, int *xy)
{
	while (xy[1] < size)
	{
		while (brd_check_x(board, size, elem, xy) == 0 && xy[0] < size)
			xy[0]++;
		if (xy[0] == size)
		{
			xy[0] = 0;
			xy[1]++;
		}
		else
			break ;
	}
	if (xy[1] == size)
		return (0);
	return (1);
}
