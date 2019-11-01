/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:14:53 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/20 18:01:22 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

char		*rem_check(char **rem, char **line)
{
	char *p_n;

	p_n = NULL;
	if (*rem)
	{
		if ((p_n = ft_strchr(*rem, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(*rem);
			ft_strcpy(*rem, ++p_n);
		}
		else
		{
			*line = ft_strdup(*rem);
			ft_memdel((void **)rem);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int			get_next_line(const int fd, char **line)
{
	static char		*rem[FD_MAX];
	char			buff[BUFF_SIZE + 1];
	char			*p_n;
	int				ret;
	char			*tmp;

	if ((fd < 0 || line == NULL) || (ret = read(fd, buff, 0) < 0))
		return (-1);
	p_n = rem_check(&rem[fd], line);
	while (!p_n && ((ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if ((p_n = ft_strchr(buff, '\n')))
		{
			*p_n = '\0';
			p_n++;
			rem[fd] = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		ft_memdel((void **)&tmp);
	}
	return (ret || (ft_strcmp(*line, "") != 0) || (rem[fd])) ? 1 : 0;
}

#include <stdio.h>

int main()
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "efghijkl\nasdadasdasd", 8);
	close(p[1]);
	dup2(out, fd);
	printf("%d\n", get_next_line(p[0], &line));
	printf("%d\n", get_next_line(p[0], &line));
	return (0);
}
