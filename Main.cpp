#include"FuncoesGame.h"



void main() {
	int x = 0;
	
	while (x != 2) {
		criacaoFase();
		exibeFase();
		if (validacaoDaFase() == false){
			cout << "Fase nao validada!!\n";
		} else {
			cout << "Fase validada!!\n";
		}
		
		//exibeTabelaASCII();
		
		cout << "Digite 1 para continuar ou 2 para sair do programa:";
		cin >> x;
		system("cls");
		
	}
}