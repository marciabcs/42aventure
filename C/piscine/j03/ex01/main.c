/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:45:55 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/03 09:55:08 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_ultimate_ft(int *********nbr);

void	ft_putnbr(int nb)
{
	int temp1;
	int	temp2;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp1 = nb;
	temp2 = 1;
	while (temp1 > 10)
	{
		temp2 *= 10;
		temp1 /= 10;
	}
	temp1 = nb;
	while (temp2 > 0)
	{
		ft_putchar((temp1 / temp2) + '0');
		temp1 %= temp2;
		temp2 /= 10;
	}
}

int		main(void)
{
	int n;
	int *********ptr;
	int ********ptr8;
	int *******ptr7;
	int ******ptr6;
	int *****ptr5;
	int ****ptr4;
	int ***ptr3;
	int **ptr2;
	int *ptr1;

	n = 99;
	ptr1 = &n;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr = &ptr8;
	ft_putnbr(n);
	ft_putchar('\n');
	ft_ultimate_ft(ptr);
	ft_putnbr(n);
	return (0);
}
