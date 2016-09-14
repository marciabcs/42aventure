/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:32:57 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 10:18:46 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = (t_btree*)malloc(sizeof(t_btree));
	elem->right = NULL;
	elem->left = NULL;
	elem->item = item;
	return (elem);
}
