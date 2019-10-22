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
	char opcao = '3', opcaoMovimento;
	char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase];
	int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase];
	int vetorObjetos[tamanhoVetorObjetos];
	int valorPosicaoRato[2], valorPosicaoQueijo[2];
	int tamanhoFase;
	int tamanhoObjetos;
	int inicioParedes;
	int minutos;
	double segundos;
	clock_t Ticks[2];

	cout << endl << char(244) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(244) << endl;
	cout << char(179) << "\t\t\t" << char(179) << endl;
	cout << char(179) << "     JOGO DO RATO\t" << char(179) << endl;
	cout << char(179) << "\t\t\t" << char(179) << endl;
	cout << char(245) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(245) << endl << endl;

	while (opcao != '4'){
		if (opcao == '3'){
			do {
				cout << "Digite:\n1 para o rato movimentar aleatoriamente.\n2 para o rato movimentar percorrendo um dos menores caminhos ate o queijo.\n-";
				cin >> opcaoMovimento;
				system("cls");
			} while (opcaoMovimento != '1' && opcaoMovimento != '2');
		}
		
		do {	
			cout << "digite o tamanho desejado da fase!(Ex: 5 para criar uma fase 5x5, tendo como limite valores entre 2 e 50)\n-";
			cin >> tamanhoFase;
			tamanhoFase += 2, tamanhoObjetos = (tamanhoFase - 2) * (tamanhoFase - 2), inicioParedes = tamanhoObjetos - tamanhoObjetos * 9 /25;
			system("cls");
		} while (!(tamanhoFase >= 4 && tamanhoFase <= 52));
		
		do {
			do{
				cout << "Criando faze...";
				criacaoFase(matrizFase, vetorObjetos, tamanhoFase, tamanhoObjetos, inicioParedes);
				transformarVetorObjetoEmMatriz(vetorObjetos, matrizObjetos, tamanhoFase, tamanhoObjetos);
				system("cls");
			} while (!validacaoDaFase(matrizObjetos, tamanhoFase, tamanhoObjetos, inicioParedes, valorPosicaoRato, valorPosicaoQueijo));
			Ticks[0] = clock();
			if (opcaoMovimento == '1'){	
				movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, valorPosicaoRato, valorPosicaoQueijo, inicioParedes);
			} else {
				movimentoInteligenteRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, valorPosicaoRato, valorPosicaoQueijo, inicioParedes);
			}
			Ticks[1] = clock();
			minutos = (Ticks[1] - Ticks[0]) / 60000;
			segundos = ((Ticks[1] - Ticks[0]) - minutos * 60000.0) / 1000.0;
			cout << "\nO tempo de execucao foi de " << minutos << "minutos e " << segundos << "segundos\nDigite:\n1 para gerar outra fase do mesmo tamanho.\n2 para escolher outro tamanho da fase.\n3 para mudar o tipo de movimento.\n4 para sair do programa.\n-";
			cin >> opcao;
			system("cls");
		} while (opcao != '2' && opcao != '3' && opcao != '4');
	}
}