#include	"labyrinthe.h"


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
			(L.grid[i][j]%2==1) ? printf("|") : printf(" ");

			if (L.pos_entrance.x==j && L.pos_entrance.y==i)
			{
				if (L.pos_exit.x==j && L.pos_exit.y==i)
					printf("EX!"); // le ! est de la part de Clément :)
				else
					printf(" E ");
			}
			else if (L.pos_exit.x==j && L.pos_exit.y==i)
				printf(" X ");
			else
				printf("   ");

		}
		printf("|\n");
	}
	for(j = 0 ; j < L.lab_width ; j++)
	{
		printf("+---");
	}
	printf("+\n");
}



void	creating_display(labyrinthe L, int half)
{
	int i;
	int j;
	printf("\n\n\n\n\n\nzqsd pour se déplacer et 8462 pour placer/retirer les murs :\n");
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
			(L.grid[i][j]%2==1) ? printf("|") : printf(" ");
			if (half == 1 && L.cursor.x == j && L.cursor.y == i)
				printf(" _ ");
			else
				printf("%2hu ",L.grid[i][j]);
		}
		printf("|\n");
	}
	for(j = 0 ; j < L.lab_width ; j++)
	{
		printf("+---");
	}
	printf("+\n\tvaleur courante    : %d\n",L.grid[L.cursor.y][L.cursor.x]);
	printf(   "\tposition d'entrée  : (%d,%d)\n",L.pos_entrance.x ,L.pos_entrance.y);
	printf(   "\tposition de sortie : (%d,%d)\n\n\n\n\n\n\n",L.pos_exit.x ,L.pos_exit.y);
}