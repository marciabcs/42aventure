/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:38:01 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 10:31:21 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	t_btree		*aux;
	int			size_r;
	int			size_l;

	aux = root;
	if (!aux)
		return (0);
	size_r = (btree_level_count(aux->right) + 1);
	size_l = (btree_level_count(aux->left) + 1);
	return ((size_r > size_l) ? size_r : size_l);
}
