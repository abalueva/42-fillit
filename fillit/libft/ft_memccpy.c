/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:43:59 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 13:05:45 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_p;
	unsigned char		*src_p;
	size_t				i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		if (src_p[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
