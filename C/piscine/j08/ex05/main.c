#include "ft_stock_par.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	t_stock_par	*par;

	par = ft_param_to_tab(argc, argv);
	ft_show_tab(par);
	return (0);
}
