#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "io.h"
#include "thread.h"

int main()
{
	int choix = 0;
	char schoix[10];
	int nbthread = 0;
	char snbthread[10];

	/*introduction du programme*/
	printf("----- Programme SuperPremier -----\n");
	printf("Voici les nombres des premiers nombres premiers que vous pouvez chercher:\n");
	printf("\t0 : exit\t5 : 2M\n");
	printf("\t1 : 128K\t6 : 4M\n");
	printf("\t2 : 256K\t7 : 8M\n");
	printf("\t3 : 512K\t8 : 16M\n");
	printf("\t4 : 1M  \t9 : 32M\n");
	
	/*selection du nb de nombre premier*/
	printf("Faites votre choix: ");
	lecture(schoix);
	choix = atoi(schoix);

#ifdef DEBUG
    debug("choix = %d",choix);
#endif
	
	if(choix != 0)
	{
		/*selection du nb de thread*/
		printf("Choississez le nombre de threads (de 1 à 8) : ");
		lecture(snbthread);

		nbthread = atoi(snbthread);
#ifdef DEBUG
		debug("snbthread = %s",snbthread);
		debug("nbthread = %d",nbthread);
		debug("initThread(nbthread = %d, choix = %d)",nbthread,choix);
#endif

		initThread(nbthread, choix);
	}
	printf("\n----- Fin du programme -----\n");
    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
