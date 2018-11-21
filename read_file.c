#include "labyrinthe.h"

void read_file(labyrinthe *L)
{
	char name_file[100]="";

	printf("\tNom du fichier ?");
	scanf("%s",name_file);

	FILE* file = NULL;
	file = fopen(name_file,"r");

	while(file == NULL)
	{
		printf("Impossible d'ouvrir le fichier %s\n",name_file);
		printf("-m- pour retourner au menu ou Nom du fichier : ");
		scanf("%s",name_file);
		if(strcmp(name_file,"m") == 0)
			return;
		else
			file = fopen(name_file,"r");
	}
	
	//on récupère les informations de la 1ère ligne	
	fscanf(file, "%d ", &L->lab_height);	
	fscanf(file, "%d ", &L->lab_width);
	fscanf(file, "%d ", &L->pos_entrance.x);
	fscanf(file, "%d ", &L->pos_entrance.y);
	fscanf(file, "%d ", &L->pos_exit.x);
	fscanf(file, "%d", &L->pos_exit.y);

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * L->lab_height);
	for(int i = 0 ; i < L->lab_height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), L->lab_width);

	for(int i=0; i<L->lab_height; i++)
	{
		for(int j=0; j<(L->lab_width)-1; j++)
		{
			fscanf(file, "%hu ", &(L->grid)[i][j]);
		}
		fscanf(file, "%hu", &(L->grid)[i][L->lab_width]);
	}

	fclose(file);

	
}
