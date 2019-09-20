#ifndef CONSTRUCAOFASE_H
#define CONSTRUCAOFASE_H

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

const int tamanhoMatrizFase = 7, tamanhoVetorObjetos = (tamanhoMatrizFase - 2) * (tamanhoMatrizFase - 2);




void ZerarMatrizFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase]){
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < 2 * tamanhoMatrizFase; j++){
			matrizFase[i][j] = 'a';
		}
	}
}

bool teste(int valor, int array[], int max){

		for(int i = 0; i <= max; i++) if(valor == array[i]) return true;
		return false;
}

void geraNumeroAleatorio(int array[]){
	int i, x ;
	i = x = 0;

	memset(array, 0, sizeof(int) * tamanhoVetorObjetos);
	srand(time(NULL));
	while(true){
		if (i == tamanhoVetorObjetos) break;
		x = (1 + (rand() % tamanhoVetorObjetos));
		if(!teste(x, array, i)) array[i++] = x;
	}
}

void criacaoFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase],int vetorDosObjetos[]) {

	geraNumeroAleatorio(vetorDosObjetos);
	ZerarMatrizFase(matrizFase);

	for (int i = 0, k = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase * 2; j++){
			if (i == 0 || i == tamanhoMatrizFase - 1){
				matrizFase[i][j] = (char)219;
			}
			else if (j == 0 || j == 1 || j == tamanhoMatrizFase * 2 - 1 || j == tamanhoMatrizFase * 2 - 2){
				matrizFase[i][j] = (char)219;
			} else {
				if (matrizFase[i][j] == (char)219 || matrizFase[i][j] == (char)32){
				}
				else if (matrizFase[i][j - 1] == (char)81 || matrizFase[i][j - 1] == (char)82){
					matrizFase[i][j] = (char)32;
				} else {
					switch (vetorDosObjetos[k]){
					case 1:
						matrizFase[i][j] = (char)81;
						k++;
						break;
					
					case 2:
						matrizFase[i][j] = (char)82;
						k++;
						break;
					
					case 20:
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
						break;
					
					case 21:
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
						break;
					
					case 22:
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
						break;
					
					case 23:
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
						break;
					
					case 24:
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
						break;
					
					case 25:
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
						break;
					
					default:
						matrizFase[i][j] = (char)32;
						matrizFase[i][j + 1] = (char)32;
						k++;
					}
				}
			}
		}
	}
}

void exibeFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase]) {
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase * 2; j++) {
			cout << matrizFase[i][j];
		}
		cout << endl;
	}
}


#endif
