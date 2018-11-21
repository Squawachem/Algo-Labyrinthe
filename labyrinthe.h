#ifndef				LABYRINTHE_H
#define				LABYRINTHE_H

#include			<stdio.h>
#include			<stdlib.h>
#include			<time.h>		//pour srand(tinme(NULL))
#include			<unistd.h>		//pour usleep()
//#include			<termios.h>
#include 			<string.h>		//pour strcmp

#define				WALL_PROB	3 //probabilité de mettre un mur lors de la géné := 1 / WALL_PROB


char* dragon[15];
char* knight[10];
char* lab[6];
char* oratoire[6];


enum { LW = 1, BW = 2, RW = 4, TW = 8 };

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

void	init_lab(labyrinthe *L, int lab_height, int lab_width);
void	create_lab(labyrinthe *L, int lab_height, int lab_width);
void	init_wall(labyrinthe L);
char	left_wall(unsigned short cell);
char	bottom_wall(unsigned short cell);
char	right_wall(unsigned short cell);
char	top_wall(unsigned short cell);
void	temp_display(labyrinthe L);
void	display(labyrinthe L);
void	creating_display(labyrinthe L, int half);
void	create_lab(labyrinthe *L, int lab_height, int lab_width);
void	init_displayer();
void	menu_display(labyrinthe L, position pos_dragon, position pos_knight, position pos_lab, position pos_oratoire);

void 	menu(labyrinthe* L);

void	read_file(labyrinthe *L);
void	save_file(labyrinthe *L);





#endif
