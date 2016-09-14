/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:56:20 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/16 17:32:18 by mcostaes         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	i = ft_strlen(dest);
	k = ft_strlen(src);
	if (!size || !(i + k))
		return (i + k);
	j = 0;
	while (j < (size - 1) && j < (i + k))
	{
		if (j < i)
			*(dest + j) = *(dest + j);
		else
			*(dest + j) = *(src + j - i);
		j++;
	}
	*(dest + j) = '\0';
	return (i + k);
}
