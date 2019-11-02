/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:24:09 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/01 22:58:37 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
//#include "libft/libft.h"

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
	int			min_xy[2];
	int			ijk[3];

	*elem = malloc(sizeof(t_etrimino));
	(*elem)->alph = alpha;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;

	ijk[0] = -1;
	ijk[1] = -1;
	ijk[2] = 0;
	min_xy[0] = 3;
	min_xy[1] = 3;
	(*elem)->coors = (int **)malloc(sizeof(int *) * 4);
	while (++ijk[0] < 4)
	{
		while (++ijk[1] < 4)
			if (array[ijk[0]][ijk[1]] == '#')
			{
				(*elem)->coors[ijk[2]] = (int *)malloc(sizeof(int) * 2);
				(*elem)->coors[ijk[2]][0] = ijk[1];
				(*elem)->coors[ijk[2]++][1] = ijk[0];
				min_xy[0] = ijk[1] < min_xy[0] ? ijk[1] : min_xy[0];
				min_xy[1] = ijk[0] < min_xy[1] ? ijk[0] : min_xy[1];
			}
		ijk[1] = -1;
	}
	brd_clr(array, 4);
	correct_coors(&(*elem)->coors, min_xy[0], min_xy[1]);
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

void			ttr_clr(t_etrimino **head)
{
	t_etrimino	*current;
	int			y;

	//current = (*head);
	while ((*head) != NULL)
	{
		current = (*head)->next;
		y = -1;
		while (++y < 4)
			free((*head)->coors[y]);
		free((*head)->coors);
		free(*head);
		*head = current;
	}
}
