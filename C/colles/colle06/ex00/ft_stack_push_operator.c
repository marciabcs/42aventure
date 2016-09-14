/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:57:35 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/01 16:40:07 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include <stdlib.h>

t_pile	*ft_create_elem_opt(int ope)
{
	t_pile	*elem;

	if (!(elem = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->item = ope;
	elem->type = TYPE_OPERATOR;
	return (elem);
}

void	ft_stack_push_operator(t_pile **begin_pile, int ope)
{
	t_pile	*aux;

	aux = ft_create_elem_opt(ope);
	if (*begin_pile)
		aux->next = *begin_pile;
	*begin_pile = aux;
}
