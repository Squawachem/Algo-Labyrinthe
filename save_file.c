#include "labyrinthe.h"

void save_file(labyrinthe *L)
{
	char name_file[100]="";

	printf("Nom du fichier ?");
	scanf("%s",name_file);

	FILE* file = NULL;
	file = fopen(name_file,"w");

	if(file == NULL)
		printf("Impossible de créer le fichier %s",name_file);

	else
	{
		//on récupère les informations générales sur de la 1ère ligne
		fprintf(file, "%d %d ", L->lab_height, L->lab_width);
		fprintf(file, "%d %d ", L->pos_entrance.x, L->pos_entrance.y);
		fprintf(file,"%d %d \n", L->pos_exit.x, L->pos_exit.y);

		for(int i=0; i<(L->lab_height); i++)
		{
			for(int j=0; j<(L->lab_width)-1; j++)
				fprintf(file, "%d ", (L->grid)[i][j]);
			fprintf(file, "%d \n", (L->grid)[i][L->lab_width]);
		}
	}

	fclose(file);

	
}
