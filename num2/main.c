/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:08:49 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/31 23:59:09 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			ttr_count;
	t_etrimino	*head;

	ac = 2;
	head = (t_etrimino *)malloc(sizeof(t_etrimino));
	fd = open(av[1], O_RDONLY);
	ttr_count = vld_file(fd, &head);
	if (ttr_count < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	real_solver(head, ttr_count);
	//ttr_clr(&head);
	//printf("HEAD IS %c\n", head->alph);
	return (0);
}
