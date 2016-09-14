/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:32:03 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 10:21:51 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	t_btree		*aux;

	aux = root;
	if (aux)
	{
		btree_apply_suffix(aux->left, applyf);
		btree_apply_suffix(aux->right, applyf);
		applyf(aux->item);
	}
}
