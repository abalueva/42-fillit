/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:12:45 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/26 16:55:03 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	if (!(temp = malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = malloc(content_size);
		temp->content_size = content_size;
		ft_memcpy(temp->content, content, temp->content_size);
	}
	temp->next = NULL;
	return (temp);
}
