/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:01:56 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/31 23:57:35 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF 21

void		vld_hash(char *line, int i, int *counter)
{
	if (i >= 5 && line[i - 5] == '#')
		(*counter)++;
	if (i <= 13 && line[i + 5] == '#')
		(*counter)++;
	if (i % 5 != 0 && line[i - 1] == '#')
		(*counter)++;
	if (line[i + 1] != '\n' && line[i + 1] == '#')
		(*counter)++;
}

int			vld_newline(char *line)
{
	int x;

	x = 4;
	while (x < 19)
	{
		if (line[x] != '\n')
			return (0);
		x += 5;
	}
	if (line[x] == '\0' || line[x] == '\n')
		return (1);
	return (0);
}

int			vld_block(char *line)
{
	int	i;
	int	counter;
	int	symbls[3];

	i = 0;
	counter = 0;
	symbls[0] = 0;
	symbls[1] = 0;
	symbls[2] = 0;
	if (!vld_newline(line))
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '#')
		{
			symbls[0]++;
			vld_hash(line, i, &counter);
		}
		else if (line[i] == '.')
			symbls[1]++;
		else if (line[i] == '\n')
			symbls[2]++;
		else
			return (0);
		i++;
	}
	if (symbls[0] == 4 && symbls[1] == 12 &&
			(symbls[2] == 4 || symbls[2] == 3) && counter >= 6)
		return (1);
	return (0);
}

int			vld_file(const int fd, t_etrimino **head)
{
	char		buff[BUFF + 1];
	char		*p_n;
	int			ret;
	int			l_count;
	char		alph;
	t_etrimino	*curr_element;
	t_etrimino	*ptr;

	l_count = 0;
	p_n = NULL;
	alph = 'A';
	if (fd < 0 || (ret = read(fd, buff, 0) < 0))
		return (-1);
	while (!p_n && ((ret = read(fd, buff, BUFF)) > 0))
	{
		if (alph > 'Z')
			return (-1);
		if (buff[ret - 1] == '\n' || buff[ret - 1] == '\0')
			buff[ret - 1] = '\0';
		if (vld_block(buff))
		{
			curr_element = ttr_create(buff, alph);
			alph++;
			if (l_count > 0)
				ttr_add(&ptr, curr_element);
			else
				*head = curr_element;
			ptr = curr_element;
			l_count++;
		}
		else
			return (-1);
	}
	return (l_count);
}
