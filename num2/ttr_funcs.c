/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:24:09 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/31 23:57:19 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

void			correct_coors(int ***coors, int min_x, int min_y)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		(*coors)[i][0] = (*coors)[i][0] >= min_x ?
						(*coors)[i][0] - min_x : (*coors)[i][0];
		(*coors)[i][1] = (*coors)[i][1] >= min_y ?
						(*coors)[i][1] - min_y : (*coors)[i][1];
	}
}

t_etrimino		*ttr_init(t_etrimino **elem, char **array, char alpha)
{
	int			i;
	int			j;
	int			k;
	int			min_x;
	int			min_y;

	*elem = malloc(sizeof(t_etrimino));
	(*elem)->alph = alpha;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	k = 0;
	i = -1;
	j = -1;
	min_x = 3;
	min_y = 3;
	(*elem)->coors = (int **)malloc(sizeof(int *) * 4);
	while (++i < 4)
	{
		while (++j < 4)
			if (array[i][j] == '#')
			{
				(*elem)->coors[k] = (int *)malloc(sizeof(int) * 2);
				(*elem)->coors[k][0] = j;
				(*elem)->coors[k++][1] = i;
				min_x = j < min_x ? j : min_x;
				min_y = i < min_y ? i : min_y;
			}
		j = -1;
	}
	//	brd_clr(array, 4);
	correct_coors(&(*elem)->coors, min_x, min_y);
	return (*elem);
}

t_etrimino		*ttr_create(char *block, char alph)
{
	int			i;
	int			j;
	char		**array;
	t_etrimino	*elem;

	i = 0;
	j = 0;
	array = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		array[i] = ft_strsub(block, j, 4);
		i += 1;
		j += 5;
	}
	return (ttr_init(&elem, array, alph));
}

void			ttr_add(t_etrimino **prev, t_etrimino *new)
{
	(*prev)->next = new;
	new->prev = *prev;
	*prev = new;
}

void			ttr_coors_clr(int **coors)
{
	int i;

	i = -1;
	while (++i < 4)
		free(coors[i]);
}

void			ttr_clr(t_etrimino **elem)
{
	t_etrimino		*prev;
	t_etrimino		*tmp;

	prev = *elem;
	while (prev != 0)
	{
		tmp = prev->next;
		(*elem)->alph = 0;
		//	ttr_coors_clr((*elem)->coors);
		(*elem)->next = NULL;
		(*elem)->prev = NULL;
		prev = tmp;
	}
	*elem = NULL;
}
