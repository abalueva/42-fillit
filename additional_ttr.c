/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_ttr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:38:07 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 15:38:18 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ttr_correct(int ***coors, int min_x, int min_y)
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

int				*ttr_init_hash(t_etrimino **elem, int ijk[3], int min_xy[2])
{
	(*elem)->coors[ijk[2]] = (int *)malloc(sizeof(int) * 2);
	(*elem)->coors[ijk[2]][0] = ijk[1];
	(*elem)->coors[ijk[2]++][1] = ijk[0];
	min_xy[0] = ijk[1] < min_xy[0] ? ijk[1] : min_xy[0];
	min_xy[1] = ijk[0] < min_xy[1] ? ijk[0] : min_xy[1];
	return (min_xy);
}
