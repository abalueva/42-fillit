/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:12:34 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 00:13:55 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			flag;
	int			nb;

	flag = n >= 0 ? 0 : 1;
	len = n >= 0 ? 0 : 1;
	nb = n;
	while ((nb = nb / 10) != 0)
		len++;
	if (!(str = malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		if (len == 0 && flag)
			str[len] = '-';
		else
			str[len] = n > 0 ? n % 10 + 48 : (n % 10) * (-1) + 48;
		n /= 10;
		len--;
	}
	return (str);
}
