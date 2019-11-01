/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:44:29 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 00:56:15 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			new_str = (char *)&str[i];
		i++;
	}
	if (str[i] == (char)c)
		new_str = ((char *)&str[i]);
	return (new_str);
}
