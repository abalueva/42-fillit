/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:15:21 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/29 16:38:06 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btree_insert_data(t_btree **root, void *item,
				int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (!root || !*root || !item)
	{
		if (item && root)
			*root = ft_btree_create_node(item);
		return ;
	}
	node = *root;
	if (cmpf(item, node->item) < 0)
	{
		if (node->left)
			ft_btree_insert_data(&node->left, item, cmpf);
		else
			node->left = ft_btree_create_node(item);
	}
	else
	{
		if (node->right)
			ft_btree_insert_data(&node->right, item, cmpf);
		else
			node->right = ft_btree_create_node(item);
	}
}
