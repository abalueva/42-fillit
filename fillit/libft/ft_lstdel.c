/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:12:50 by abalueva          #+#    #+#             */
/*   Updated: 2019/09/26 22:30:08 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*prev;
	t_list		*tmp;

	prev = *alst;
	while (prev != 0)
	{
		tmp = prev->next;
		ft_lstdelone(&prev, del);
		prev = tmp;
	}
	*alst = NULL;
}
