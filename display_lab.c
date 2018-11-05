#include	"labyrinthe.h"

void	temp_display(labyrinthe L)
{
	int	i;
	int	j;

	for(i = 0 ; i < L.lab_height ; i++)
	{
		for(j = 0 ; j < L.lab_width ; j++)
		{
			printf("%hu\t", L.grid[i][j]);
		}
		printf("\n");
	}
}



void	display(labyrinthe L)
{
	int i;
	int j;
	for(i = 0 ; i < L.lab_height ; i++)
	{
		for(j = 0 ; j < L.lab_width ; j++)
		{
			printf("+");
			(L.grid[i][j]>=8) ?	printf("---") : printf("   ");
		}
		printf("+\n");
		for(j = 0 ; j < L.lab_width ; j++)
		{
			(L.grid[i][j]%2==1) ? printf("|   ") : printf("    ");
		}
		printf("|\n");
	}
	for(j = 0 ; j < L.lab_width ; j++)
	{
		printf("+---");
	}
	printf("+\n");
}