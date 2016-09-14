/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:34:11 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 11:10:44 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root,
						void *item, int (*cmpf)(void *, void *))
{
	t_btree	*aux;

	aux = *root;
	if (!aux)
		*root = btree_create_node(item);
	else if (cmpf(item, aux->item) < 0)
		btree_insert_data(&aux->left, item, cmpf);
	else
		btree_insert_data(&aux->right, item, cmpf);
}
