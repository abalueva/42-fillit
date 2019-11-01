/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:24:31 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 20:32:43 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int ch, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buffer;
	while (count--)
		if (*ptr != (unsigned char)ch)
			ptr++;
		else
			return (ptr);
	return (NULL);
}
