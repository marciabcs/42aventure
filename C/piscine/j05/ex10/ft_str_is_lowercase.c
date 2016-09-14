/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:03:35 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/16 15:05:19 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	if (!*str)
		return (1);
	while (*(str + i))
	{
		if (!(*(str + i) >= 'a' && *(str + i) <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
