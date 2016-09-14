/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 10:24:41 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/05 11:02:10 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *dest;
	int i;
	int rg;

	rg = max - min;
	if (rg < 0)
		rg = -rg;
	if (min >= max)
		return ((void*)0);
	dest = (int*)malloc(sizeof(int) * (rg + 1));
	if (!dest)
		return ((void*)0);
	i = 0;
	while (i < rg)
	{
		*(dest + i) = min + i;
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}
