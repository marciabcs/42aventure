/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:49:55 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/16 17:58:54 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void			readkeys(char **tabkey, char **tabresult)
{
	unsigned int	t1;
	unsigned int	i;
	unsigned int	j;
	char			*c;
	char			*key;

	while (1)
	{
		c = (char *)malloc(100 * sizeof(char));
		t1 = read(0, c, 100);
		if (t1 == 1 && c[0] == '\n')
			break ;
		key = (char*)malloc((t1) * sizeof(char));
		j = -1;
		while (++j < t1)
			key[j] = c[j];
		key[t1] = '\0';
		i = ft_hash(key, 131072);
		while (tabkey[i])
		{
			i++;
			if (i == 131072)
				i = 0;
		}
		tabkey[i] = key;
		free(c);
		c = (char *)malloc(100 * sizeof(char));
		t1 = read(0, c, 100);
		tabresult[i] = (char*)malloc((t1) * sizeof(char));
		j = -1;
		while (++j < t1)
			tabresult[i][j] = c[j];
		tabresult[i][t1] = '\0';
		free(c);
	}
}

void			searchkeys(char **tabkey, char **tabresult)
{
	unsigned int	i;
	unsigned int	j;
	char			*c;
	int				flag;
	char			*key;

	while (1)
	{
		flag = 0;
		c = (char *)malloc(100 * sizeof(char));
		i = read(0, c, 100);
		key = (char*)malloc((i) * sizeof(char));
		j = -1;
		while (++j < i)
			key[j] = c[j];
		key[i] = '\0';
		free(c);
		i = ft_hash(key, 131072);
		j = i;
		while (!tabkey[i] || ft_strcmp(tabkey[i], key) != 0)
			if (++i == 131072)
				i = 0;
			else if (i == j)
			{
				flag = 1;
				while (*key != '\n')
					write(1, key++, 1);
				write(1, ": Not found.\n", 13);
				break ;
			}
		if (!flag)
		{
			free(key);
			j = 0;
			while (tabresult[i][j] != '\0')
				write(1, &tabresult[i][j++], 1);
		}
	}
}

int				main(void)
{
	unsigned int	i;
	char			**tabkey;
	char			**tabresult;

	i = 0;
	tabkey = (char**)malloc(sizeof(char*) * 131072);
	tabresult = (char**)malloc(sizeof(char*) * 131072);
	while (i < 131072)
		tabkey[i++] = NULL;
	readkeys(tabkey, tabresult);
	searchkeys(tabkey, tabresult);
	return (0);
}
