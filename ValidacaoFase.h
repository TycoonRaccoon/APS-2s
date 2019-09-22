#ifndef VALIDACAOFASE_H 
#define VALIDACAOFASE_H 

#include"ConstrucaoFase.h"


void transformarVetorObjetoEmMatriz(int vetorDosObjetos[], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase]){
	for (int i = 0, k = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (i == 0 || i == tamanhoMatrizFase - 1 || j == 0 || j == tamanhoMatrizFase - 1){
				matrizObjetos[i][j] = 25;
			} else {
				matrizObjetos[i][j] = vetorDosObjetos[k];
				k++;
			}
		}
	}
}


void zerarMatrizDeArea(int MatrizASerZerada[tamanhoMatrizFase][tamanhoMatrizFase]){
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			MatrizASerZerada[i][j] = 0;
		}
	}
}


void marcaERetornaPosicoes(int linha, int coluna, int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase],int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], int posicoes[], int &indexArray){
	
	bool paredeDireita = (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25),
	paredeCima = (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25),
	paredeEsquerda = (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25),
	paredeBaixo = (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25),
	marcadoDireita = matrizArea[linha][coluna + 1] == 1,
	marcadoCima = matrizArea[linha - 1][coluna] == 1,
	marcadoEsquerda = matrizArea[linha][coluna - 1] == 1,
	marcadoBaixo = matrizArea[linha + 1][coluna] == 1;
	
	if (!paredeDireita && !marcadoDireita){
		if (!paredeCima && !marcadoCima){
			if (!paredeEsquerda && !marcadoEsquerda){
				if (!paredeBaixo && !marcadoBaixo){
					matrizArea[linha][coluna + 1] = 1,matrizArea[linha - 1][coluna] = 1,matrizArea[linha][coluna - 1] = 1,matrizArea[linha + 1][coluna] = 1;
					posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
					posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++,
					posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++,
					posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
				} else {
					matrizArea[linha][coluna + 1] = 1,matrizArea[linha - 1][coluna] = 1,matrizArea[linha][coluna - 1] = 1;
					posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
					posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++,
					posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++;
				}
				
			} else {
				if (!paredeBaixo && !marcadoBaixo){
					matrizArea[linha][coluna + 1] = 1,matrizArea[linha - 1][coluna] = 1,matrizArea[linha + 1][coluna] = 1;
					posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
					posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++,
					posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
				} else {
					matrizArea[linha][coluna + 1] = 1,matrizArea[linha - 1][coluna] = 1;
					posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
					posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
				}
			}
			
		} else {
			if (!paredeEsquerda && !marcadoEsquerda){
				if (!paredeBaixo && !marcadoBaixo){
					matrizArea[linha][coluna + 1] = 1,matrizArea[linha][coluna - 1] = 1,matrizArea[linha + 1][coluna] = 1;
					posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
					posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++,
					posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
				} else {
					matrizArea[linha][coluna + 1] = 1,matrizArea[linha][coluna - 1] = 1;
					posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
					posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++;
				}
			} else if (!paredeBaixo && !marcadoBaixo){
				matrizArea[linha][coluna + 1] = 1,matrizArea[linha + 1][coluna] = 1;
				posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++,
				posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
			} else {
				matrizArea[linha][coluna + 1] = 1;
				posicoes[indexArray] = linha, indexArray++, posicoes[indexArray] = coluna + 1, indexArray++;
			}
		}

	} else {
		if (!paredeCima && !marcadoCima){
			if (!paredeEsquerda && !marcadoEsquerda){
				if (!paredeBaixo && !marcadoBaixo){
					matrizArea[linha - 1][coluna] = 1,matrizArea[linha][coluna - 1] = 1,matrizArea[linha + 1][coluna] = 1;
					posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++,
					posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++,
					posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
				} else {
					matrizArea[linha - 1][coluna] = 1,matrizArea[linha][coluna - 1] = 1;
					posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++,
					posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++;
				}
			} else if (!paredeBaixo && !marcadoBaixo){
				matrizArea[linha - 1][coluna] = 1,matrizArea[linha + 1][coluna] = 1;
				posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++,
				posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
			} else {
				matrizArea[linha - 1][coluna] = 1;
				posicoes[indexArray] = linha - 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
			}
		} else if (!paredeEsquerda && !marcadoEsquerda){
			if (!paredeBaixo && !marcadoBaixo){
				matrizArea[linha][coluna - 1] = 1,matrizArea[linha + 1][coluna] = 1;
				posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++,
				posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
			} else {
				matrizArea[linha][coluna - 1] = 1;
				posicoes[indexArray] = linha, indexArray++,posicoes[indexArray] = coluna - 1, indexArray++;
			}
		} else if (!paredeBaixo && !marcadoBaixo){
			matrizArea[linha + 1][coluna] = 1;
			posicoes[indexArray] = linha + 1, indexArray++, posicoes[indexArray] = coluna, indexArray++;
		}
	}
	
}

void AreasAcessiveis(int posicaoInicialLinha, int posicaoInicialColuna, int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase],int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase]){
	zerarMatrizDeArea(matrizArea);

	matrizArea[posicaoInicialLinha][posicaoInicialColuna] = 1;
	int linha = posicaoInicialLinha, coluna = posicaoInicialColuna, index = 0, posicoesMarcadas[2 * tamanhoVetorObjetos/* - 2 * numero de paredes - 2(por depois)*/];

	for (int i = 0; i < 2 * tamanhoVetorObjetos/* - 2 * numero de paredes - 2(por depois)*/; i++){
		posicoesMarcadas[i] = -1;
	}
	
	marcaERetornaPosicoes(linha, coluna, matrizObjetos, matrizArea, posicoesMarcadas, index);
	int i = 0;
	while (posicoesMarcadas[i] != -1){
		marcaERetornaPosicoes(posicoesMarcadas[i], posicoesMarcadas[i + 1], matrizObjetos, matrizArea, posicoesMarcadas, index);
		i += 2;
	}
	
	//print
	for (int i = 0, j = 0; i < 2 * tamanhoVetorObjetos/* - 2 * numero de paredes - 2(por depois)*/; i++, j++){
		cout << posicoesMarcadas[i];
		if (j % 2 == 1){
			cout << "\t";
		}
	}
	cout << endl;
}

void gerarAreasAcessiveisRatoEQueijo(int posicaoLinhaInicial, int posicaoColunaInicial, int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], int matriz[tamanhoMatrizFase][tamanhoMatrizFase]){

	zerarMatrizDeArea(matriz);
	
	AreasAcessiveis(posicaoLinhaInicial,posicaoColunaInicial, matrizArea, matrizObjetos);
	
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matriz[i][j] = matrizArea[i][j];
		}
	}
}

bool validacaoDaFase(int vetorDosObjetos[]) {
	int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], matrizAreaRato[tamanhoMatrizFase][tamanhoMatrizFase], matrizAreaQueijo[tamanhoMatrizFase][tamanhoMatrizFase];
	int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase];
	int valorPosicaoRato[2], valorPosicaoQueijo[2];
	
	transformarVetorObjetoEmMatriz(vetorDosObjetos, matrizObjetos);
	
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizObjetos[i][j] == 2){
				valorPosicaoRato[0] = i, valorPosicaoRato[1] = j;
			}
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizObjetos[i][j] == 1){
				valorPosicaoQueijo[0] = i, valorPosicaoQueijo[1] = j;
			}
		}
	}

 //PRINT MATRIZ OBJETOS!!!TIRAR DEPOIS
	/*for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			cout << matrizObjetos[i][j] << "\t";
		}
		cout << endl;
	}
 //-----------------------------------*/

	
	gerarAreasAcessiveisRatoEQueijo(valorPosicaoRato[0], valorPosicaoRato[1], matrizObjetos, matrizArea, matrizAreaRato);
	gerarAreasAcessiveisRatoEQueijo(valorPosicaoQueijo[0], valorPosicaoQueijo[1], matrizObjetos, matrizArea, matrizAreaQueijo);
	
	//	DADOS==tirardepois
	cout << "mapa rato:\n";
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			if (matrizAreaRato[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizAreaRato[i][j];
			}
		}
		cout << endl;
	}
	cout << "mapa queijo:\n";
	
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			if (matrizAreaQueijo[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizAreaQueijo[i][j];
			}
		}
		cout << endl;
	}
	//tirar----------------------

	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizAreaRato[i][j] != matrizAreaQueijo[i][j]){
				return false;
			}
		}
	}
	return true;
}




#endif  
