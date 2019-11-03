/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:01:56 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 19:48:00 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF 21

int			vld_block(char *line)
{
	int	counter;
	int	symbls[3];

	counter = 0;
	clear_symbls(symbls, 3);
	if (!vld_newline(line))
		return (0);
	if (!vld_symbls(line, symbls, &counter))
		return (0);
	if (symbls[0] == 4 && symbls[1] == 12 &&
			(symbls[2] == 4 || symbls[2] == 3) && counter >= 6)
		return (1);
	return (0);
}

int			vld_xtr(char a_r[2], char *buff, t_etrimino **head, int r_c[2])
{
	t_etrimino *elem;

	if (a_r[0] > 'Z')
		return (-1);
	a_r[1] = buff[r_c[0]];
	buff[r_c[0] - 1] = buff[r_c[0] - 1] == '\n' ? '\0' : buff[r_c[0] - 1];
	if (vld_block(buff))
	{
		elem = ttr_create(buff, a_r[0]);
		a_r[0]++;
		if (r_c[1] > 0)
			ttr_add(*head, elem);
		else
			*head = elem;
		r_c[1]++;
	}
	else
		return (-1);
	return (1);
}

int			vld_file(const int fd, t_etrimino **head)
{
	char		buff[BUFF + 1];
	int			r_c[2];
	char		alph_rem[2];

	r_c[1] = 0;
	alph_rem[0] = 'A';
	if (fd < 0 || (read(fd, buff, 0) < 0))
		return (-1);
	while ((r_c[0] = read(fd, buff, BUFF)) > 0)
	{
		if (vld_xtr(alph_rem, buff, head, r_c) == -1)
			return (-1);
	}
	if (alph_rem[1] == '\0')
		return (r_c[1]);
	return (-1);
}
