/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:01:40 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/04 10:34:26 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int m, int n)
{
	ft_putchar((m / 10) + '0');
	ft_putchar((m % 10) + '0');
	ft_putchar(' ');
	ft_putchar((n / 10) + '0');
	ft_putchar((n % 10) + '0');
	if (m != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int		m;
	int		n;

	m = 0;
	while (m <= 99)
	{
		n = m + 1;
		while (n <= 99)
		{
			ft_print(m, n);
			n++;
		}
		m++;
	}
}
