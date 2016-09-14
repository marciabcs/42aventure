/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:08:33 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 14:36:36 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int high;
	int low;
	int result;

	i = 1;
	high = 1;
	low = 1;
	if (length <= 0)
		return (0);
	if (length == 1)
		return (1);
	while (i < length)
	{
		result = f(*(tab + i - 1), *(tab + i));
		if (result <= 0)
			high++;
		if (result >= 0)
			low++;
		i++;
	}
	if (high == length || low == length)
		return (1);
	else
		return (0);
}
