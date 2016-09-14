/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:56:04 by ckramer           #+#    #+#             */
/*   Updated: 2016/03/02 16:58:16 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

int	ft_atoi(char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == 'r' \
		|| *str == '\v' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			value = (value * 10) + (*str - '0');
		else
			return (value * sign);
		str++;
	}
	return (value * sign);
}
