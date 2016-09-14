/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:00:04 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/23 11:38:33 by mcostaes         ###   ########.fr       */
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

int	ft_is_prime(int n)
{
	int i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i <= ft_sqrt_mod(n))
	{
		if ((n % i) == 0)
			return (0);
		i++;
	}
	return (1);
}
