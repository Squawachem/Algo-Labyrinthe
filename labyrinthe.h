#ifndef	LABYRINTHE_H
#define	LABYRINTHE_H

#include	<stdio.h>
#include	<stdlib.h>

typedef struct	position
{
	int			x;
	int			y;	
}				position;

typedef	struct	
{
	unsigned short	**;
	int				lab_length;
	int				lab_width;
	position		pos_entrance;
	position		pos_exit;
	position		cursor;
}				;

#endif