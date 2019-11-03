/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_vld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:46:45 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/02 19:50:57 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			vld_symbls(char *line, int symbls[3], int *counter)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
		{
			symbls[0]++;
			vld_hash(line, i, counter);
		}
		else if (line[i] == '.')
			symbls[1]++;
		else if (line[i] == '\n')
			symbls[2]++;
		else
			return (0);
		i++;
	}
	return (1);
}
