#include"FuncoesGame.h"



void main() {
	int x = 0;

	while (x != 2) {
		criacaoFase();
		exibeFase();
		validacaoDaFase();
		//exibeTabelaASCII();
		//for (int i = 0; i < tamanhoVetorObjetos; i++){
		//	cout << vetorDosObjetos[i] << "\n";
		//}
		
		cout << "Digite 1 para continuar ou 2 para sair do programa:";
		cin >> x;
		system("cls");
		
	}
}