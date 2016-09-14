/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:34:25 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/16 17:46:43 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = ft_strlen(src);
	if (!i || !size)
		return (i);
	j = 0;
	while (j < (size - 1) && j < i)
	{
		*(dest + j) = *(src + j);
		j++;
	}
	*(dest + j) = '\0';
	return (i);
}
