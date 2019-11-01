/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:32:42 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 21:31:17 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char		*fresh;
	size_t		start;
	size_t		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
	{
		fresh = malloc(sizeof(char) * 1);
		ft_strclr(fresh);
		return (fresh);
	}
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (end < start)
		end = start;
	if ((fresh = ft_strnew(end - start)) == NULL)
		return (NULL);
	fresh = ft_strsub(s, start, end - start + 1);
	return (fresh);
}
