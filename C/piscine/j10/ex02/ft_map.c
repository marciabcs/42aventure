/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:33:19 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/06 15:33:25 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *func;

	func = (int*)malloc((length + 1) * sizeof(func));
	i = 0;
	while (i < length)
	{
		*(func + i) = f(*(tab + i));
		i++;
	}
	*(func + i) = 0;
	return (func);
}
