#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void     ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
	
	
// Fonction d'affichage
void affichage (int grille[9][9])
{
	char v;

	//puts("------------------------------");
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			v = grille[i][j];
			if (v == 0)
				ft_putchar('.');
			else
				ft_putchar(v + '0');
			ft_putchar(' ');
/*
			if (! ((j + 1) % 3))
				ft_putchar('|');
*/
			// v = (grille[i][j]) ? grille[i][j]+'0' : '-';
			//printf( ((j+1)%3) ? " %c " : " %c |", v);
		}
		putchar('\n');
/*		if (!((j + 1 ) % 3))
			puts("---------------------------");
*/
	}
	ft_putchar('\n');
}

bool absentSurLigne (int k, int grille[9][9], int i)
{
	for (int j=0; j < 9; j++)
		if (grille[i][j] == k)
			return false;
	return true;
}

bool absentSurColonne (int k, int grille[9][9], int j)
{
	for (int i=0; i < 9; i++)
		if (grille[i][j] == k)
			return false;
	return true;
}

bool absentSurBloc (int k, int grille[9][9], int i, int j)
{
	int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
	for (i=_i; i < _i+3; i++)
		for (j=_j; j < _j+3; j++)
			if (grille[i][j] == k)
				return false;
	return true;
}

bool estValide (int grille[9][9], int position)
{
	//	printf("@");
	if (position == 9*9)
		return true;

	int i = position/9, j = position%9;

	if (grille[i][j] != 0)
	{ 
		// printf("/[%2d]",position); 
		return estValide(grille, position+1);
	}

	for (int k=1; k <= 9; k++)
	{
		if (absentSurLigne(k,grille,i) && absentSurColonne(k,grille,j) 
				&& absentSurBloc(k,grille,i,j))
		{
			grille[i][j] = k;
			if ( estValide (grille, position+1) )
			{ 
				// printf("+[%2d]",position); 
				return true; 
			}
			else 
			{ 
				// printf("*[%2d]",position); 
				grille[i][j] = 0; 
			}
		}
	}
	grille[i][j] = 0;
//	printf(".[%2d]",position);
//	putchar('<');
	return false;
}

bool	ligcorrecte(int grille[9][9], int lig, int j, int k)
{
	
	   if (grille [lig][j] !=0 && j != k)
	   if (grille[lig][j] == grille[lig][k])
	   {
//	   ft_putstr("ERREUR");
//	   printf("[l%d x %d = %d]\n\n", lig+1, j+1, k+1);
	   return false;
	   }
	return (true);
}

bool	colcorrecte(int grille[9][9], int i, int col, int k)
{
	   if (grille[i][col] != 0 && i != k)
	   if (grille[i][col] == grille[k][col])
	   {
	   //ft_putstr("ERREUR");
	   //printf("[c%d x %d = %d]\n\n", col+1, i+1, k+1);
	   return false;
	   }
	return (true);
}

bool	bloccorrect(int grille[9][9], int i, int j, int k)
{
	/*
	   int i2;
	   int j2;

	   i2 = i - (i % 3); j2 = j - ( j % 3);
	   i = i2;
	   while (i < i2 + 3)
	   {
	   j = j2;
	   while (j < j2 + 3)
	   {
	   if (grille[i][j] == k)
	   return (false);
	   j++;
	   }
	   i++;
	   }
	   */
	return (true);
}

bool	grillecorrecte(int grille[9][9])
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = 0;
			while (k < 9) 
			{
				if (! ligcorrecte(grille, i, j, k) )
					return false;
				if (! colcorrecte(grille, j, i, k))
					return false;
				/*
				   if (! bloccorrect(grille, i, j, k))
				   return false;
				   */
				k++;
			}
			j++;
		}
		i++;
	}
	return (true);
}


void	sudoku_solve(int grille[9][9])
{
	printf("--Grille entree--\n");
	affichage(grille);
	if (grillecorrecte(grille))
	{
		if (estValide(grille,0))
		{
			puts("\n");
			printf("-- Solution--\n");
			affichage(grille);
		}
		else
		{
			ft_putstr("ERREUR\n");
		}

	}
}

int main (void)
{
	int grille1l[9][9] =
	{
		{9,0,0,1,0,0,0,0,5},
		{0,0,5,0,9,0,2,0,1},
		{8,0,0,0,4,0,0,0,0},
		{0,0,0,0,8,0,0,0,0},
		{0,0,0,7,0,0,0,0,0},
		{0,0,0,0,2,6,0,0,9},
		{2,0,0,3,0,0,0,0,6},
		{0,0,0,2,0,0,9,0,0},
		{7,0,1,9,0,4,5,7,0} // {0,0,1,9,0,4,5,7,0}
	};

	int grille1c[9][9] =
	{
		{9,0,0,1,0,0,0,0,5},
		{0,0,5,0,9,0,2,0,1},
		{8,0,0,0,4,0,0,0,0},
		{0,0,0,0,8,0,0,0,0},
		{0,0,0,7,0,0,0,0,0},
		{0,0,0,0,2,6,0,0,9},
		{2,0,0,3,0,0,0,0,6},
		{0,0,0,2,0,0,9,0,0},
		{0,0,5,9,0,4,0,7,0} // {0,0,1,9,0,4,5,7,0}
	};

	int grille1b[9][9] =
	{
		{9,0,0,1,0,0,0,0,5},
		{0,0,5,0,9,0,2,0,1},
		{8,0,0,0,4,0,0,0,0},
		{0,0,0,0,8,0,0,0,0},
		{0,0,0,7,0,0,0,0,0},
		{0,0,0,0,2,6,0,0,9},
		{2,0,0,3,0,0,0,0,6},
		{0,0,0,2,0,0,9,0,0},
		{0,0,2,9,0,4,5,7,0} // {0,0,1,9,0,4,5,7,0}
	};

	int grille1[9][9] =
	{
		{9,0,0,1,0,0,0,0,5},
		{0,0,5,0,9,0,2,0,1},
		{8,0,0,0,4,0,0,0,0},
		{0,0,0,0,8,0,0,0,0},
		{0,0,0,7,0,0,0,0,0},
		{0,0,0,0,2,6,0,0,9},
		{2,0,0,3,0,0,0,0,6},
		{0,0,0,2,0,0,9,0,0},
		{0,0,1,9,0,4,5,7,0}
	};

	int grille2[9][9] =
	{
		{9,0,0,0,7,0,0,0,0},
		{2,0,0,0,9,0,0,5,3},
		{0,6,0,0,1,2,4,0,0},
		{8,4,0,0,0,1,0,9,0},
		{5,0,0,0,0,0,8,0,0},
		{0,3,1,0,0,4,0,0,0},
		{0,0,3,7,0,0,6,8,0},
		{0,9,0,0,5,0,7,4,1},
		{4,7,0,0,0,0,0,0,0}
	};

	int grille3[9][9] =
	{
		{9,0,0,0,7,0,0,0,0},
		{2,0,0,0,9,0,0,5,3},
		{0,6,0,0,1,2,4,0,0},
		{8,4,0,0,0,1,0,9,0},
		{5,0,0,0,0,0,8,0,0},
		{0,3,1,0,0,4,0,0,0},
		{0,0,3,7,0,0,6,8,0},
		{0,0,0,0,5,0,7,4,1},
		{0,0,0,0,0,0,0,0,0}
	};

	sudoku_solve(grille1l);
	sudoku_solve(grille1c);
	sudoku_solve(grille1b);
	//sudoku_solve(grille1);
	sudoku_solve(grille2);
	sudoku_solve(grille3);
}
