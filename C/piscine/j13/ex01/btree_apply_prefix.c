/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:30:22 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 10:20:44 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	t_btree		*aux;

	aux = root;
	if (aux)
	{
		applyf(aux->item);
		btree_apply_prefix(aux->left, applyf);
		btree_apply_prefix(aux->right, applyf);
	}
}
