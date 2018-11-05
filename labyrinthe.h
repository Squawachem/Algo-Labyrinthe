#ifndef				LABYRINTHE_H
#define				LABYRINTHE_H

#include			<stdio.h>
#include			<stdlib.h>
#include			<time.h>

enum name			wall
{
					LW = 1,
					BW = 2,
					RW = 4,
					TW = 8
};

typedef struct		position
{
	int				x;
	int				y;	
}					position;

typedef	struct		labyrinthe
{
	unsigned short	**grid;
	int				lab_height;
	int				lab_width;
	position		pos_entrance;
	position		pos_exit;
	position		cursor;
}					labyrinthe;

#endif