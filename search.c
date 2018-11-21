#include	"search.h"


int set_distance(labyrinthe L, position p, int distance) {
	L.grid[p.y][p.x] %= 256; // it remains the 8 least significant bits 
	L.grid[p.y][p.x] += distance * 256;
	return 0;
}

int distance(labyrinthe L, position p) {
	return L.grid[p.y][p.x] / 256;
}





/*** A FAIRE : init distance à 11111111
test actu distances si >= 128
***/
int init_distances(labyrinthe L) {
	int i;
	int j;
	position tmp;
	for(i = 0 ; i < L.lab_height ; i++) {
		for(j = 0 ; j < L.lab_width ; j++) {
			if ( (i != L.pos_entrance.y) || (j != L.pos_entrance.x) ) {		// distance entrance/entrance = 0
				tmp.x = j;
				tmp.y = i;
				set_distance(L, tmp, L.lab_height * L.lab_width);	// "infinite" = height * width (the distances never exceeds that)
			}
		}
	}
	return 0;
}


int actualize_distance(labyrinthe L, position s1, position s2) {
	if ( distance(L, s1) > distance(L, s2)+1 ) {
		set_distance(L, s2, distance(L, s1)+1);
		return 1;	// distance actualized
	}
	return 0;	// s1 is not a good way to access to s2
}



unsigned int cell(labyrinthe L, position p) {
	return L.grid[p.y][p.x];
}

int mark (labyrinthe L, position p) {
	if ( is_marked(L, p) == 0 ) {
		L.grid[p.y][p.x] += 16;
	}
	return 0;
}

int is_marked (labyrinthe L, position p) {
	return ( (L.grid[p.y][p.x] %32) /16);
} // 1 if marked ; 0 if not



int in_tab(position p, position* V, int size) {
	int i;
	for (i=0; i<size; i++) {
		if (V[i].x == p.x && V[i].y == p.y) {
			return i;	// p is in T at the index i
		}
	}
	return -1; // p is not in T
}


/***
position* find_path(labyrinthe L, position* V, position* P) {
	//L.pos_entrance;
	//L.pos_exit;
	int size_V = L.lab_height * L.lab_width;
	

	//position pos_null;
	//pos_null.x = -1;
	//pos_null.y = -1;


	position* shortest_path = malloc(size_V * sizeof(position));	// à remplacer par une structure "path" en liste chaînée

	position backward;
	backwards.x = L.pos_exit.x;
	backwards.y = L.pos_exit.y;

	int SP_index = 0;	// shortest_path index


	int i = in_tab( backward, V, size_V ) ;
	while (i != -1) {
		shortest_path[SP_index] = backward;	// append backward at the table shortest_path
		
		i = in_tab( backward, V, size_V );	// index of the predecessor of 
		backward = 
	}
	//append /0
	return shortest_path;


} // end find_path
***/

int pos_equal(position s1, position s2) {
	if ( (s1.x == s2.x) && (s1.y == s2.y) ) {
		return 1;
	}
	return 0;
}

path BFS(labyrinthe L) {  // pas encore fonctionnel
	init_distances(L);
	position* V = malloc(L.lab_height * L.lab_width * sizeof(position));	// order of visit of the vertex
	position* P = malloc(L.lab_height * L.lab_width * sizeof(position));	// P[i] predecessor of V[i]
	

	/*** initializarion of V and P with positions (-1, -1) ***/
	int i;
	for (i=0; i< L.lab_height * L.lab_width; i++) {
		V[i].x = -1;
		V[i].y = -1;
		P[i].x = -1;
		V[i].y = -1;
	}
	V[0] = L.pos_entrance;



	int V_index = 1;	// index of adding elements in the tables V and P
	int V_visit = 0;	// index of the visited vertex (table V)
	// 0 = left ; 1 = bottom ; 2 = right ; 3 = top. 


	position visited; 
	position next;
	while ( V_index != V_visit || ( pos_equal(V[V_visit], L.pos_exit)) ) {

		visited = V[ V_visit ];
		
		if ( left_wall( cell(L, visited) ) == 0 ) {	// if there is no left wall
			next.y = visited.y;
			next.x = visited.x - 1;
			if (is_marked(L, next) == 0) {	// cell not marked
				actualize_distance(L, visited, next);	// distance(next) := distance(visited) + 1
				V[ V_index ] = next;		// add next at the table of vertex to visit
				P[ V_index ] = visited;		// "next" predecessor := visited
				V_index ++;					// indice to add the next cell after this one 
			}
		} // end if left_wall

		if ( bottom_wall( cell(L, visited) ) == 0 ) {	// if there is no bottom wall
			next.y = visited.y + 1;
			next.x = visited.x;
			if (is_marked(L, next) == 0) {
				actualize_distance(L, visited, next);
				V[ V_index ] = next;
				P[ V_index ] = visited;
				V_index ++;
			}
		} // bottom


		if ( right_wall( cell(L, visited) ) == 0 ) {	// if there is no right wall
			next.y = visited.y;
			next.x = visited.x + 1;
			if (is_marked(L, next) == 0) {
				actualize_distance(L, visited, next);
				V[ V_index ] = next;
				P[ V_index ] = visited;
				V_index ++;
			}
		} // right

		if ( top_wall( cell(L, visited) ) == 0 ) {	// if there is no top wall
			next.y = visited.y - 1;
			next.x = visited.x ;
			if (is_marked(L, next) == 0) {
				actualize_distance(L, visited, next);
				V[ V_index ] = next;
				P[ V_index ] = visited;
				V_index ++;
			}
		} // top

		mark(L, V[V_visit]);
		V_visit ++;



	} // end while










	path shortest_path;
	return shortest_path;

} // end BFS

