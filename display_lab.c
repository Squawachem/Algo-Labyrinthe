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