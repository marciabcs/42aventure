/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:36:22 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/04 10:56:44 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long int	temp1;
	int			temp2;
	long int	temp3;

	temp3 = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		temp3 = -temp3;
	}
	temp1 = temp3;
	temp2 = 1;
	while (temp3 >= 10)
	{
		temp2 *= 10;
		temp3 /= 10;
	}
	while (temp2 > 0)
	{
		ft_putchar((temp1 / temp2) + '0');
		temp1 %= temp2;
		temp2 /= 10;
	}
}
