/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_operand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:52:56 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/01 16:39:52 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include <stdlib.h>

t_pile	*ft_create_elem_opr(int value)
{
	t_pile	*elem;

	if (!(elem = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->item = value;
	elem->type = TYPE_OPERAND;
	return (elem);
}

void	ft_stack_push_operand(t_pile **begin_pile, int value)
{
	t_pile	*aux;

	aux = ft_create_elem_opr(value);
	if (*begin_pile)
		aux->next = *begin_pile;
	*begin_pile = aux;
}
