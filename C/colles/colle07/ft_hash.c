/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:47:18 by mdaoui            #+#    #+#             */
/*   Updated: 2016/02/24 11:50:47 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_hash(char *key, int size)
{
	unsigned int	hashval;
	int				i;

	hashval = 0;
	i = 0;
	while (key[i] != '\0')
	{
		hashval = (hashval << 5) ^ key[i] ^ size;
		i++;
	}
	return (hashval % size);
}
