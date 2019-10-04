#include"BibliotecasGame.h"



void transformarVetorObjetoEmMatriz(int vetorDosObjetos[], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos){
	for (int i = 0, k = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase; j++){
			if (i == 0 || i == tamanhoFase - 1 || j == 0 || j == tamanhoFase - 1){
				matrizObjetos[i][j] = tamanhoObjetos;
			} else {
				matrizObjetos[i][j] = vetorDosObjetos[k];
				k++;
			}
		}
	}
}


void main() {
	int x = 0;
	char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase];
	int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase];
	int vetorObjetos[tamanhoVetorObjetos];
	int valorPosicaoRato[2], valorPosicaoQueijo[2];
	int tamanhoFase = 7;
	int tamanhoObjetos = (tamanhoFase - 2) * (tamanhoFase - 2);
	int inicioParedes = tamanhoObjetos - tamanhoObjetos * 9 /25;

	while (x != 3){
		do{	
			cout << "digite o tamanho desejado da fase!(Ex: 5 para criar uma fase 5x5, tendo como limite valores entre 2 e 60)\n-";
			cin >> tamanhoFase;
			tamanhoFase += 2, tamanhoObjetos = (tamanhoFase - 2) * (tamanhoFase - 2), inicioParedes = tamanhoObjetos - tamanhoObjetos * 9 /25, x = 0;
			system("cls");
		}while (!(tamanhoFase >= 4 && tamanhoFase <= 62));
		while (x != 2 && x != 3) {
			criacaoFase(matrizFase, vetorObjetos, tamanhoFase, tamanhoObjetos, inicioParedes);
			exibeFase(matrizFase, tamanhoFase);
			transformarVetorObjetoEmMatriz(vetorObjetos, matrizObjetos, tamanhoFase, tamanhoObjetos);
			if (!validacaoDaFase(matrizObjetos, tamanhoFase, tamanhoObjetos, inicioParedes, valorPosicaoRato, valorPosicaoQueijo)){
				cout << "Hoje nao tem queijo!!\n";
			} else {
				cout << "Fase validada!!\n";
				movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, valorPosicaoRato[0], valorPosicaoRato[1], valorPosicaoQueijo[0], valorPosicaoQueijo[1], inicioParedes);
				//movimentoInteligenteRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, valorPosicaoRato, valorPosicaoQueijo, inicioParedes);
			}

			cout << "Digite:\n1 para gerar outra fase do mesmo tamanho.\n2 para escolher outro tamanho da fase.\n3 para sair do programa:";
			cin >> x;
			system("cls");
		}
	}
}