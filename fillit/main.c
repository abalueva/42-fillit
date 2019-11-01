/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:08:49 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/31 20:21:19 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main()
{
	int fd;
	int ttr_count;
	t_etrimino *head;

	fd = open("examples/try_to.fillit", O_RDONLY);
	ttr_count = vld_file(fd, &head);
	if (ttr_count < 0)
	{
		printf("error\n");
		return (0);
	}
	close(fd);
	real_solver(head, ttr_count);
	return (0);
}
