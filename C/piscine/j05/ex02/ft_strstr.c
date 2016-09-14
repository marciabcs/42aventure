/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:28:40 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/04 10:37:15 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_test(char *str, char *to_find)
{
	int j;

	j = 0;
	while ((*str) && (*to_find == *str))
	{
		j++;
		to_find++;
		str++;
	}
	return (j);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (!*to_find)
		return (str);
	while (*(str + i))
	{
		while (*(str + i + j) && (*(to_find + j) == *(str + i + j)))
			j++;
		if (!*(to_find + j))
			return (str + i);
		else if (!*(str + i + j))
			return (0);
		else
		{
			j = 0;
		}
		i++;
	}
	return ((void*)0);
}
