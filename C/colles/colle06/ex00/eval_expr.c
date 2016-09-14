/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:31:01 by ckramer           #+#    #+#             */
/*   Updated: 2016/02/02 23:15:32 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"
#include "ft_pile.h"

int		eval_expr(char *str)
{
	t_pile	*postfix;
	t_pile	*stack;
	t_pile	*begin;
	int		val1;
	int		val2;

	if (!(postfix = ft_trans_expr(str)))
		return (0);
	postfix = postfix->prev;
	begin = postfix;
	while (postfix)
	{
		if (postfix->type == TYPE_OPERAND)
			ft_stack_push_operand(&stack, postfix->item);
		else
		{
			val2 = ft_stack_pop_operand(&stack);
			val1 = ft_stack_pop_operand(&stack);
			ft_stack_push_operand(&stack, ft_doop(postfix->item, val1, val2));
		}
		postfix = postfix->prev;
		if (postfix == begin)
			break ;
	}
	return (ft_stack_pop_operand(&stack));
}

int		is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	else
		return (0);
}
