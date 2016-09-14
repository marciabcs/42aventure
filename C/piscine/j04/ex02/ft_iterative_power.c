/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:14:31 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/09 10:17:06 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int f;
	int i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		i = power;
	f = 1;
	while (i > 0)
	{
		f = f * nb;
		i--;
	}
	return (f);
}
