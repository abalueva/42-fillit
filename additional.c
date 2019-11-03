/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:38:08 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 15:21:02 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*clear_xy(int **array, int size)
{
	while (--size >= 0)
		(*array)[size] = 0;
	return (*array);
}

int			*clear_symbls(int array[3], int size)
{
	while (--size >= 0)
		array[size] = 0;
	return (array);
}

void		array_free(char **board, int size)
{
	int y;

	y = -1;
	while (++y < size)
		free(board[y]);
	free(board);
}

void		print_board(char ***board, int size)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++y < size)
	{
		while (++x < size)
			ft_putchar((*board)[y][x]);
		x = -1;
		ft_putchar('\n');
	}
}
