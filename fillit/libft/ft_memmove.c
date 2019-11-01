/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:52:27 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/25 16:04:53 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (ptr2 < ptr)
		while (++i <= n)
			ptr[n - i] = ptr2[n - i];
	else
		while (n-- > 0)
			*(ptr++) = *(ptr2++);
	return (dst);
}
