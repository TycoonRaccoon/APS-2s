#include"BibliotecasGame.h"



void main() {
	int x = 0;
	char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase];
	int vetorObjetos[tamanhoVetorObjetos];
	//int VetorObjetos[];
	while (x != 2) {
		criacaoFase(matrizFase, vetorObjetos);
		exibeFase(matrizFase);
		if (!validacaoDaFase(vetorObjetos)){
			cout << "Fase nao validada!!\n";
		} else {
			cout << "Fase validada!!\n";
		}

		
		cout << "Digite 1 para continuar ou 2 para sair do programa:";
		cin >> x;
		system("cls");
		
	}
}