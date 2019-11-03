/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:08:49 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 19:54:37 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			ttr_count;
	t_etrimino	*head;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	ttr_count = vld_file(fd, &head);
	if (ttr_count <= 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	real_solver(head, ttr_count);
	ttr_free(&head);
	return (0);
}
