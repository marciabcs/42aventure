/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:10:13 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/23 11:45:32 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_mod(int n)
{
	int i;

	i = 1;
	while (i <= (n / 2))
	{
		if ((i * i) >= n)
			return (i);
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int n)
{
	int i;
	int nn;

	nn = n;
	i = 2;
	if (n <= 2)
		return (2);
	while (i <= ft_sqrt_mod(n))
	{
		if ((n % i) == 0)
		{
			nn++;
			return (ft_find_next_prime(nn));
		}
		i++;
	}
	return (nn);
}
