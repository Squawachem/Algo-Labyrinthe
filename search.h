#ifndef			SEARCH_H
#define			SEARCH_H

#include		<math.h>
#include		"labyrinthe.h"



typedef struct cell_path {
	position p;
	position* next;
	position* previous;
} cell_path;

typedef struct path {
	position* first;
} path;



unsigned int cell(labyrinthe L, position p);

int set_distance(labyrinthe L, position p, int distance);	// actualize the distance (8 strongest bits)
int distance(labyrinthe L, position p);						// distance from the entrance to position p
int init_distances(labyrinthe L);							// let all distances to the entry at "infinite", except the entrance set at 0
int actualize_distance(labyrinthe L, position s1, position s2);

int mark (labyrinthe L, position p);
int is_marked (labyrinthe L, position p);
int in_tab(position p, position* V, int size);
path find_path(labyrinthe L, position* V, position* P);



path	BFS(labyrinthe L);		// Breadth First Search
path	DFS(labyrinthe L);		// Depth First Search





#endif
