/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:28:20 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 10:21:37 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	t_btree		*aux;

	aux = root;
	if (aux)
	{
		btree_apply_infix(aux->left, applyf);
		applyf(aux->item);
		btree_apply_infix(aux->right, applyf);
	}
}
