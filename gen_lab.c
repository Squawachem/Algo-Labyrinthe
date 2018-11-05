#include	"labyrinthe.h"

void	init_lab(labyrinthe *L, int lab_height, int lab_width)
{
	int			i;
	position	temp;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * lab_height);
	for(i = 0 ; i < lab_height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), lab_width);
	L->lab_height = lab_height;
	L->lab_width = lab_width;
	temp.x = rand() % lab_width;
	temp.y = rand() % lab_height;
	L->pos_entrance = temp;
	temp.x = rand() % lab_width;
	temp.y = rand() % lab_height;
	L->pos_exit = temp;
	L->cursor = L->pos_entrance;
	init_wall(*L);
}

void	init_wall(labyrinthe L)
{
	int	i;
	int	j;

	for(i = 0 ; i < L.lab_height ; i++)
		for(j = 0 ; j < L.lab_width ; j++)
		{
			L.grid[i][j] += i == 0 ? TW : bottom_wall(L.grid[i - 1][j]) * TW;//top wall
			L.grid[i][j] += j == 0 ? LW : right_wall(L.grid[i][j - 1]) * LW;//left wall
			L.grid[i][j] += i == L.lab_height - 1 ? BW : !(rand() % WALL_PROB) * BW;//bottom wall
			L.grid[i][j] += j == L.lab_width - 1 ? RW : !(rand() % WALL_PROB) * RW;//right wall
		}
}

char	left_wall(unsigned short cell)
{
	return cell % 2;
}

char	bottom_wall(unsigned short cell)
{
	return (cell / 2) % 2;
}

char	right_wall(unsigned short cell)
{
	return (cell / 4) % 2;
}

char	top_wall(unsigned short cell)
{
	return (cell / 8) % 2;
}