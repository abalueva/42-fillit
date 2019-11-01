/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:25:48 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/29 16:39:50 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree		*ft_btree_create_node(void *item)
{
	t_btree *node;

	if (!(node = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	node->left = 0;
	node->right = 0;
	node->item = item;
	return (node);
}
