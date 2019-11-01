/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:35:46 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 00:00:51 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	while (count-- > 0)
		*(dest_p++) = *(src_p++);
	return (dest);
}
