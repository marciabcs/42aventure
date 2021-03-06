/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:11:50 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 14:54:54 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi(char *str)
{
	long int number;
	int sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			number = number * 10 + (*str - '0');
		else
			return (number * sign);
		str++;
	}
	return (number * sign);
}
