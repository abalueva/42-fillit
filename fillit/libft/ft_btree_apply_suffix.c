/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 00:54:13 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/29 16:38:38 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		ft_btree_apply_infix(root->left, applyf);
	if (root->right)
		ft_btree_apply_infix(root->right, applyf);
	applyf(root->item);
}
