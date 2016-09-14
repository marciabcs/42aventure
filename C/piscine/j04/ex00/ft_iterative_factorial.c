/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:44:18 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/08 14:48:15 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int f;
	int i;

	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	else
		i = nb;
	f = 1;
	while (i > 0)
	{
		f = f * i;
		i--;
	}
	return (f);
}
