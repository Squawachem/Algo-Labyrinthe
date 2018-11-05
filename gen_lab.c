#include	"labyrinthe.h"

void	init_lab(labyrinthe *L, int lab_height, int lab_width)
{
	int			i;
	position	temp;

	labyrinthe->grid = (unsigned short **)malloc(sizeof(unsigned short *) * lab_height);
	for(i = 0 ; i < lab_height ; i++)
		(labyrinthe->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), lab_width);
	labyrinthe->lab_height = lab_height;
	labyrinthe->lab_width = lab_width;
	temp.x = rand() % lab_width;
	temp.y = rand() % lab_height;
	labyrinthe->pos_entrance = temp;
	temp.x = rand() % lab_width;
	temp.y = rand() % lab_height;
	labyrinthe->pos_exit = temp;
	labyrinthe->cursor = labyrinthe->pos_entrance;
	init_wall(*L);
}

void	init_wall(labyrinthe L)
{
	int	i;
	int	j;

	for(i = 0 ; i < lab_height ; i++)
		for(j = 0 ; j < lab_width ; j++)
		{
			L.grid[i][j] += i == 0 ? TW : bottom_wall(grid[i - 1][j]) * TW;//top wall
			L.grid[i][j] += j == 0 ? LW : right_wall(grid[i][j - 1]) * LW;//left wall
			L.grid[i][j] += i == lab_height - 1 ? BW : rand() % 2 * BW;//bottom wall
			L.grid[i][j] += j == lab_width - 1 ? RW : rand() % 2 * RW;//right wall
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