/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:44:39 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 10:29:51 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *found;

	if (root)
	{
		if (root->left)
		{
			found = btree_search_item(root->left, data_ref, cmpf);
			if (found)
				return (found);
		}
		if (cmpf(data_ref, root->item) == 0)
			return (root->item);
		if (root->right)
		{
			found = btree_search_item(root->right, data_ref, cmpf);
			if (found)
				return (found);
		}
	}
	return ((void*)0);
}
