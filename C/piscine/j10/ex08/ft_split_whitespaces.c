#include <stdio.h>
#include <stdlib.h>

int	lines_matrix(char *str)
{
	int	i;
	int	k;
	char	a;

	i = 0;
	k = 0;
	while (*(str + k))
	{
		a = *(str + k);
		if (a == 9 || a == 32 || a == '\n')
			k++;
		else
		{
			k++;
			a = *(str + k);
			if (a == 9 || a == 32 || a == '\n' || !(a))
					i++;
		}
	}
	return (i);
}

int	taille(char *str, int ind)
{
	int	i;
	int	j;
	int	k;
	char	a;

	i = 0;
	k = 0;
	j = 0;
	while (*(str + k))
	{
		a = *(str + k);
		if (a == 9 || a == 32 || a == '\n')
			k++;
		else
		{
			k++;
			j++;
			a = *(str + k);
			if (a == 9 || a == 32 || a == '\n' || !(a))
			{
					if (i == ind)
						return (j);
					else
						j = 0;
					i++;
			}
		}
	}
	return (0);
}

void	write_vector(char *str, char **dest)
{
	int	i;
	int	j;
	int	k;
	char	a;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		a = *(str + k);
		if (a == 9 || a == 32 || a == '\n')
			k++;
		else
		{
			*(*(dest + i) + j) = *(str + k);
			k++;
			j++;
			a = *(str + k);
			if (a == 9 || a == 32 || a == '\n' || !(a))
			{
				*(*(dest + i) + j) = 0;
				i++;
				j = 0;
			}
		}
	}
	*(dest + i) = 0;
}

char **ft_split_whitespaces(char *string)
{
	char	**dest;
	char	*str;
	int	line;
	int	i;
	int	n;

	str = string;
	line = lines_matrix(str);
	dest = (char**)malloc((line + 1) * (sizeof(*dest)));
	i = 0;
	while (i < line)
	{
		n = taille(str, i);
		*(dest + i) = (char*)malloc((n + 1) * (sizeof(dest)));
		i++;
	}
	write_vector(str, dest);
	return (dest);
}
