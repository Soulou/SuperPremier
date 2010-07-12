#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#include "thread.h"
#include "io.h"

int sum(int n)
{
	int i,sum = 0;
	for(i = n; i > 0; i--)
		sum += i;

	return sum;
}

void initTab(long * res, long n)
{
	int i = 0;
	for(i = n; i < n; i++)
		res[i] = 0;
}

int Premier(long i)
{
        int j,racine, res = 1;
        racine = (int) sqrt((double)i);

        for(j=2;j<=racine && res;j++)
                if(i%j == 0)
                        res = 0;
        return res;
}

void *SuperPremier(void *p_data)
{

        struct plage *p = (struct plage *) p_data;
        long i = p->min , fin = p->max, j = 0;

#ifdef DEBUG
        debug("i = p->min = %ld | fin = p-> max = %ld | p->taille = %ld",p->min, p->max, p->taille);
#endif
        while(i<=fin)
		{
			if(Premier(i))
			{
				p->res[j] = i;
				p->nbPremier++;
				j++;
			}
			i++;
		}
        return NULL;
}


void initThread(int nbthread, int choix)
{
	#ifdef DEBUG
    debug("%d thread(s) et choix %d", nbthread, choix);
	#endif

    struct timeval deb,fin;

    /* Début du chronomètre */
    printf("Début des calculs ...\n");
    gettimeofday(&deb,NULL);

	
    pthread_t t[nbthread];
	struct plage p[9];
	int i, max, min;
	double taille;
	for(i = 1; i <= nbthread; i++)
	{
		p[i].taille = pow((double)2,(double)(18+choix))/(nbthread*2-1);
		
		#ifdef DEBUG
		debug("p[i].taille = %ld",p[i].taille);
		#endif

		p[i].res = malloc(p[i].taille*sizeof(long));
		initTab(p[i].res, p[i].taille);
	    p[i].min = plageThread[choix-1][sum(nbthread)+i-2];
	    p[i].max = plageThread[choix-1][sum(nbthread)+i-1];
		p[i].nbPremier = 0;

		#ifdef DEBUG
		debug("sum(nbthread)+i-2 = %d, sum(nbthread) = %d, p.min = %d, p.max = %d, i = %d, &t[i] : 0x%x",sum(nbthread-1)+i-1,sum(nbthread-1),p[i].min,p[i].max,i,&t[i]);
		#endif
	    /* Initialisation du thread */
	    pthread_create(&(t[i]),NULL,SuperPremier,(void *) &p[i]);	

	}
	
	/* Attente de la fin du thread*/
	for(i = 1; i <= nbthread; i++)
		pthread_join(t[i],NULL);
	
     /* FIN - Calcul de la durée */
    gettimeofday(&fin,NULL);

    long nbsec = (long) fin.tv_sec - deb.tv_sec;	
    float nbusec = (float) fin.tv_usec - deb.tv_usec;
    nbusec = nbusec * 1e-6;

	#ifdef DEBUG
    debug("nbsec = %ld\n",nbsec);
    debug("nbusec = %f\n",nbusec);
	#endif

    int heure = (int) nbsec/3600;
    int minute = (int) nbsec/60;
    float sec = nbsec%60 + nbusec;

    printf("Durée : %d heures, %d minutes et %.2f secondes.\n",heure,minute,sec);
	printf("Ecriture des logs\n");

	/*Ecriture de chaque tableau dans le log*/
	FILE * f = fopen("./SuperPremier.log", "w");
	if(f == NULL)
		die("Echec d'ouverture du fichier de log.");
	for(i = 1; i <= nbthread; i++)
		ecrireLog(p[i].res, p[i].nbPremier, f);
	fclose(f);
}

