/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:24:09 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 15:39:09 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

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
				ttr_init_hash(elem, ijk, min_xy);
		ijk[1] = -1;
	}
	array_free(array, 4);
	ttr_correct(&(*elem)->coors, min_xy[0], min_xy[1]);
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

void			ttr_add(t_etrimino *head, t_etrimino *new)
{
	t_etrimino *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void			ttr_free(t_etrimino **head)
{
	t_etrimino	*current;
	int			y;

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
