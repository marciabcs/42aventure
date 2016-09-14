/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:14:49 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/01 16:39:35 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include <stdlib.h>

int	ft_stack_pop_operator(t_pile **begin_list)
{
	t_pile	*aux;
	char	c;

	aux = *begin_list;
	if (*begin_list)
	{
		c = aux->item;
		*begin_list = aux->next;
		free(aux);
		return (c);
	}
	else
		return ('0');
}
