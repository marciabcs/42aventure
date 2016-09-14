#include <stdio.h>

char	**ft_split_whitespaces(char *str);

void	ft_sort_wordtab(char **tab);

int	main(void)
{
	char *str = "clara clarinha claro clareta claria claro clara claro";
	char **dest;
	int	i;

	i = 0;
	dest = ft_split_whitespaces(str);
	ft_sort_wordtab(dest);
	while (*(dest + i))
	{
		printf("%s\n", *(dest + i));
		i ++;
	}
	return (0);
}
