#include	"labyrinthe.h"

int	main(int argc, char const *argv[])
{
	labyrinthe L;

	if(argc != 3)
	{
		printf("2 arg\n");
		return 0;
	}
	srand(time(NULL));
	init_lab(&L, atoi(argv[1]), atoi(argv[2]));
	temp_display(L);
	printf("\n\n\n");
	display(L);
	return 0;
}
