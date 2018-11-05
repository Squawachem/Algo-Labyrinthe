#include	"labyrinthe.h"

int	main(int argc, char const *argv[])
{
	labyrinthe L;

	srand(time(NULL));
	init_lab(&L, atoi(argv[1]), atoi(argv[2]));
	return 0;
}
