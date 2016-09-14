/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 10:36:16 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/06 10:05:23 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int rg;
	int *temp;

	rg = max - min;
	if (min >= max)
	{
		return (0);
		temp = (void*)0;
	}
	temp = (int*)malloc(sizeof(int) * (rg + 1));
	*range = temp;
	if (!temp)
		return (0);
	i = 0;
	while (i < rg)
	{
		*(temp + i) = min + i;
		i++;
	}
	return (i);
}
