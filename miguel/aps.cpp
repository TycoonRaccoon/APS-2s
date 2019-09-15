#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "numA.h"


using namespace std;


int main(){
	
	const int var = 25;
	int fundo[var];
	
	criaAleatorios(fundo,var,5);
	for (int i = 0; i < var ; i++)
	{
		cout << fundo[i] << "\t";
		if (i == 4 || i==9 || i ==14 || i==19 || i== 24)
			cout << endl;
	}
	return 0;
}
