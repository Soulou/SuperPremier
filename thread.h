#ifndef THREAD_H
#define THREAD_H


struct plage
{
	long nbPremier;
	long * res;
	long taille;
    long min;
    long max;
} plage;

int Premier(long i);
int sum(int n);
void initTab(long *, long);
void *SuperPremier(void *p_data);
void initThread(int nbthread, int choix);

#endif
