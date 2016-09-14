/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translator_expr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:40:43 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/02 16:41:48 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include "ft_utils.h"
#include <unistd.h>

void	ft_pile_push(t_pile **begin, int val, char ope);

int			ft_is_higher_priority(char a, char b)
{
	int i;
	int j;
	if (a == '*' || a == '/' || a == '%')
		i = 1;
	if (a == '+' || a == '-')
		i = 2;
	if (b == '*' || b == '/' || b == '%')
		j = 1;
	if (b == '+' || b == '-')
		j = 2;
	if (i > j)
		return (1);
	else
		return (0);
}

t_pile		*ft_translator_expr(char *str)
{
	t_pile	*pile;
	t_pile	*stack;
	char *aux;

	stack = NULL;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			aux = str;
			pile_push_operand(&pile, ft_atoi(aux));
			while (*str && *str >= '0' && *str <= '9')
				str++;
		}
		else if (*str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '%')
		{
			while (stack && ft_is_higher_priority(*str, (char)stack->item) && (char)stack->item != '(')
				pile_push_operator(&pile, ft_stack_pop_operator(&stack));
			ft_stack_push_operator(&stack, (int)*str);
		}
		else if (*str == '(')
			ft_stack_push_operator(&stack, (int)*str);
		else if (*str == ')')
		{
			while (stack && (char)stack->item != '(')
				pile_push_operator(&pile, ft_stack_pop_operator(&stack));
			ft_stack_pop_operator(&stack);
		}
		str++;
	}
	while (stack)
			pile_push_operator(&pile, ft_stack_pop_operator(&stack));
	return (pile);
}

int main (int c, char **v)
{
	t_pile	*pile;
	t_pile	*p1;

	if (c == 2)
	{
		p1 = ft_translator_expr(v[1]);
		pile = p1;
		while (pile)
		{
			ft_putchar(' ');
			if (pile->type == TYPE_OPERAND)
				ft_putnbr(pile->item);
			else
				ft_putchar((char)pile->item);
			ft_putchar(' ');
			pile = pile->next;
			if (pile == p1)
				return (0);
		}
		return (0);
	}
}
