/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop_operand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:39:19 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/01 16:39:21 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include <stdlib.h>

int		ft_stack_pop_operand(t_pile **begin_list)
{
	t_pile	*aux;
	t_pile	*erase;
	int		n;

	aux = *begin_list;
	if (*begin_list)
	{
		n = aux->item;
		erase = aux;
		*begin_list = aux->next;
		free(erase);
		return (n);
	}
	else
		return (0);
}
