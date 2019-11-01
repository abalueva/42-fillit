/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:12:56 by abalueva          #+#    #+#             */
/*   Updated: 2019/10/03 15:00:15 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char *str)
{
	long	prev;
	long	nb;
	int		negative;

	nb = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	negative = 1;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = nb;
		nb = nb * 10 + (*str++ - '0');
		if (prev > nb)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)(nb * negative));
}
