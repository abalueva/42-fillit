/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:25:31 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/03 19:38:44 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_find_size(char const *s, char c)
{
	size_t	i;
	int		fl;
	int		len;

	i = 0;
	fl = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && fl == 0)
		{
			fl = 1;
			len++;
		}
		else if (s[i] == c)
			fl = 0;
		i++;
	}
	return (len);
}

static char		**find(char const *s, char c, int len)
{
	int		i;
	int		j;
	int		z;
	char	**fresh;

	i = 0;
	j = 0;
	z = -1;
	if (!(fresh = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (++z < len)
	{
		while (s[i] == c && s[i] != '\0')
			++i;
		j = i;
		while (s[j] != c && s[j] != '\0')
			++j;
		fresh[z] = ft_strsub(s, i, j - i);
		i = j;
	}
	fresh[z] = NULL;
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**fresh;

	if (!s || !c)
		return (NULL);
	len = ft_find_size(s, c);
	fresh = find(s, c, len);
	return (fresh);
}
