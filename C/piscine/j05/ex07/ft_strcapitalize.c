/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:35:02 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/04 10:49:03 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) >= 'A') && (*(str + i) <= 'Z'))
			*(str + i) = *(str + i) + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	s;

	str = ft_strlowcase(str);
	i = 0;
	if ((*(str + i) >= 'a') && (*(str + i) <= 'z'))
		*(str + i) = *(str + i) - 32;
	while (*(str + i))
	{
		s = *(str + i);
		if (!((s >= 'a') && (s <= 'z')) && (!(s >= '0') && (s <= '9')))
		{
			if ((*(str + i + 1) >= 'a') && (*(str + i + 1) <= 'z'))
			{
				*(str + i + 1) = *(str + i + 1) - 32;
				i = i + 2;
			}
		}
		i++;
	}
	return (str);
}
