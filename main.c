#include	"labyrinthe.h"

int	main(int argc, char const *argv[])
{
	labyrinthe L;
	long long c=0;

	if(argc != 3)
	{
		printf("2 arg\n");
		return 0;
	}
	system("clear");
	printf("\n\n");
	srand(time(NULL));
	do
	{
		init_lab(&L, atoi(argv[1]), atoi(argv[2]));
		c++;
	}
	while (L.pos_entrance.x != L.pos_exit.x || L.pos_entrance.y != L.pos_exit.y);


	//create_lab(&L, atoi(argv[1]), atoi(argv[2]));

	display(L);

	printf("\n\n%lld\n",c);

	return 0;
}
