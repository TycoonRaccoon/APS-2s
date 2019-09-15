#ifndef numA_h
#define numA_h

#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void criaAleatorios(int vetor[5], int tamVetor, int limiteNum)
{
	int aux;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < tamVetor; i++)
	{
		aux =rand() % limiteNum;
		if (aux % 2 == 0)
			vetor[i] = 1;
		else
			vetor[i] = 0;
	}
}

#endif
