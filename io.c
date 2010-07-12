#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void debug(char * s, ...)
{
    char * format = malloc(strlen(s)+19);
    sprintf(format, "--- DEBUG : %s ---\n",s);
    va_list args;
    va_start(args,s);
    vprintf(format,args);
    va_end(args);
}

void die(char * s)
{
	printf("ERREUR === %s ===\n",s);
	exit(0);
}

/* Lecture d'une chaine en entree standard */
void lecture(char * s)
{
	int i;
	char c;

	for(i = 0; i<9 && (c=getchar()) != '\n' ; i++)
		s[i] = c;

	s[i] = '\0';
	
}

void ecrireLog(long * res, long n, FILE * f)
{
	long i, j = 0;


	for(i = 0; i < n; i++)
	{
		if(j == 10)
		{
			fprintf(f, "%ld\n", res[i]);
			j = 0;
		}
		else fprintf(f, "%ld,", res[i]);
		j++;
	}

}
