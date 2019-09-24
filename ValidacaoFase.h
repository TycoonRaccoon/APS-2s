#ifndef VALIDACAOFASE_H 
#define VALIDACAOFASE_H 

#include"ConstrucaoFase.h"


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


void zerarMatrizDeArea(int MatrizASerZerada[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase){
	for (int i = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase; j++){
			MatrizASerZerada[i][j] = 0;
		}
	}
}


void marcaERetornaPosicoes(int linha, int coluna, int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase],int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], int posicoes[], int &indexArray, int tamanhoObjetos, int quantParedes){
	
	bool paredeDireita = (matrizObjetos[linha][coluna + 1] > quantParedes && matrizObjetos[linha][coluna + 1] <= tamanhoObjetos),
	paredeCima = (matrizObjetos[linha - 1][coluna] > quantParedes && matrizObjetos[linha - 1][coluna] <= tamanhoObjetos),
	paredeEsquerda = (matrizObjetos[linha][coluna - 1] > quantParedes && matrizObjetos[linha][coluna - 1] <= tamanhoObjetos),
	paredeBaixo = (matrizObjetos[linha + 1][coluna] > quantParedes && matrizObjetos[linha + 1][coluna] <= tamanhoObjetos),
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

void AreasAcessiveis(int posicaoInicialLinha, int posicaoInicialColuna, int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase],int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int quantParedes){
	zerarMatrizDeArea(matrizArea, tamanhoFase);

	matrizArea[posicaoInicialLinha][posicaoInicialColuna] = 1;
	int linha = posicaoInicialLinha,
	coluna = posicaoInicialColuna,
	index = 0,
	posicoesMarcadas[2 * tamanhoVetorObjetos];

	for (int i = 0; i < 2 * tamanhoObjetos; i++){
		posicoesMarcadas[i] = -1;
	}
	
	marcaERetornaPosicoes(linha, coluna, matrizObjetos, matrizArea, posicoesMarcadas, index, tamanhoObjetos, quantParedes);
	int i = 0;
	while (posicoesMarcadas[i] != -1){
		marcaERetornaPosicoes(posicoesMarcadas[i], posicoesMarcadas[i + 1], matrizObjetos, matrizArea, posicoesMarcadas, index, tamanhoObjetos, quantParedes);
		i += 2;
	}
	
	/*//print
	for (int i = 0, j = 0; i < 2 * tamanhoObjetos; i++, j++){
		cout << posicoesMarcadas[i];
		if (j % 2 == 1){
			cout << "\t";
		}
	}
	cout << endl;*/
}

void gerarAreasAcessiveisRatoEQueijo(int posicaoLinhaInicial, int posicaoColunaInicial, int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], int matriz[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int quantParedes){

	zerarMatrizDeArea(matriz, tamanhoFase);
	
	AreasAcessiveis(posicaoLinhaInicial,posicaoColunaInicial, matrizArea, matrizObjetos, tamanhoFase, tamanhoObjetos, quantParedes);
	
	for (int i = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase; j++){
			matriz[i][j] = matrizArea[i][j];
		}
	}
}

bool validacaoDaFase(int vetorDosObjetos[], int tamanhoFase, int tamanhoObjetos, int quantParedes) {
	int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], matrizAreaRato[tamanhoMatrizFase][tamanhoMatrizFase], matrizAreaQueijo[tamanhoMatrizFase][tamanhoMatrizFase];
	int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase];
	int valorPosicaoRato[2], valorPosicaoQueijo[2];
	
	transformarVetorObjetoEmMatriz(vetorDosObjetos, matrizObjetos, tamanhoFase, tamanhoObjetos);
	
	for (int i = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase; j++){
			if (matrizObjetos[i][j] == 2){
				valorPosicaoRato[0] = i, valorPosicaoRato[1] = j;
			}
		}
	}
	for (int i = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase; j++){
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

	
	gerarAreasAcessiveisRatoEQueijo(valorPosicaoRato[0], valorPosicaoRato[1], matrizObjetos, matrizArea, matrizAreaRato, tamanhoFase, tamanhoObjetos, quantParedes);
	gerarAreasAcessiveisRatoEQueijo(valorPosicaoQueijo[0], valorPosicaoQueijo[1], matrizObjetos, matrizArea, matrizAreaQueijo, tamanhoFase, tamanhoObjetos, quantParedes);
	
	//	DADOS==tirardepois
	cout << "mapa rato:\n";
	for (int i = 0; i < tamanhoFase; i++) {
		for (int j = 0; j < tamanhoFase; j++) {
			if (matrizAreaRato[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizAreaRato[i][j];
			}
		}
		cout << endl;
	}
	cout << "mapa queijo:\n";
	
	for (int i = 0; i < tamanhoFase; i++) {
		for (int j = 0; j < tamanhoFase; j++) {
			if (matrizAreaQueijo[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizAreaQueijo[i][j];
			}
		}
		cout << endl;
	}
	//tirar----------------------

	for (int i = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase; j++){
			if (matrizAreaRato[i][j] != matrizAreaQueijo[i][j]){
				return false;
			}
		}
	}
	return true;
}




#endif  
