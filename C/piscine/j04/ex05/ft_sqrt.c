/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:38:02 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/09 10:54:27 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	int i;

	i = 1;
	while (i <= (n / 2))
	{
		if ((i * i) == n)
			return (i);
		i++;
	}
	return (0);
}
