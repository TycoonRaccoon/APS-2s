#include"BibliotecasGame.h"



void main() {
	int x = 0;
	char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase];
	int vetorObjetos[tamanhoVetorObjetos];
	int tamanhoFase = 7;
	int tamanhoObjetos = (tamanhoFase - 2) * (tamanhoFase - 2);
	int quantParedes = tamanhoObjetos - tamanhoObjetos * 9 /25;
	
	while (x != 3){
		do{	
			cout << "digite o tamanho desejado da fase!(Ex: 5 para criar uma fase 5x5, tendo como limite valores entre 2 e 70)\n-";
			cin >> tamanhoFase;
			tamanhoFase += 2, tamanhoObjetos = (tamanhoFase - 2) * (tamanhoFase - 2), quantParedes = tamanhoObjetos - tamanhoObjetos * 9 /25, x = 0;
			system("cls");
		}while (!(tamanhoFase >= 4 && tamanhoFase <= 72));
		while (x != 2 && x != 3) {
			criacaoFase(matrizFase, vetorObjetos, tamanhoFase, tamanhoObjetos, quantParedes);
			exibeFase(matrizFase, tamanhoFase);
			if (!validacaoDaFase(vetorObjetos, tamanhoFase, tamanhoObjetos, quantParedes)){
				cout << "Hoje nao tem queijo!!\n";
			} else {
				cout << "Fase validada!!\n";
			}

			cout << "Digite:\n1 para gerar outra fase do mesmo tamanho.\n2 para escolher outro tamanho da fase.\n3 para sair do programa:";
			cin >> x;
			system("cls");
		}
	}
}