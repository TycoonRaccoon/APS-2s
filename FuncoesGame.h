#ifndef FUNCOESGAME_H
#define FUNCOESGAME_H

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;


const int tamanhoMatrizFase = 7, tamanhoVetorObjetos = (tamanhoMatrizFase - 2) * (tamanhoMatrizFase - 2);
char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase];
int vetorDosObjetos[tamanhoVetorObjetos];

int matrizArea[tamanhoMatrizFase][tamanhoMatrizFase], matrizAreaRato[tamanhoMatrizFase][tamanhoMatrizFase], matrizAreaQueijo[tamanhoMatrizFase][tamanhoMatrizFase];

int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase];
void transformarVetorObjetoEmMatriz(){
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




	

void exibeTabelaASCII(){
	for (int i = 32; i < 255; i++){
		cout << (char)i << "\t" << i << endl;
	}
}






void zerarMatrizAreaRato(){
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAreaRato[i][j] = 0;
		}
	}
}

void zerarMatrizAreaQueijo(){
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAreaQueijo[i][j] = 0;
		}
	}
}

void ZerarMatrizArea(){
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizArea[i][j] = 0;
		}
	}
}

void ZerarMatrizFase(){
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

void geraNumeroAleatorio(){
	int i, x ;
	i = x =0;

	memset(vetorDosObjetos, 0, sizeof(int) * tamanhoVetorObjetos);
	srand(time(NULL));
	while(true){
		if (i == tamanhoVetorObjetos) break;
		x = (1 + (rand() % tamanhoVetorObjetos));
		if(!teste(x, vetorDosObjetos, i)) vetorDosObjetos[i++] = x;
	}
}

void criacaoFase() {
	geraNumeroAleatorio();
	ZerarMatrizFase();

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

void exibeFase() {
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase * 2; j++) {
			cout << matrizFase[i][j];
		}
		cout << endl;
	}
}






void ateEncontrarParede(int posicaoLinhaRato, int posicaoColunaRato, int vetorInicioDireita[], int vetorInicioBaixo[], int vetorInicioCima[]){
	int j = 1;
	bool i = true;

	while (i == true){
		if (matrizObjetos[posicaoLinhaRato][posicaoColunaRato + j] >= 20 && matrizObjetos[posicaoLinhaRato][posicaoColunaRato + j] <= 25){
			vetorInicioDireita[0] = posicaoLinhaRato, vetorInicioDireita[1] = posicaoColunaRato + j - 1;
			break;
		} else {
			j++;
		}
	}
	j = 1;
	i = true;
	while (i == true){
		if (matrizObjetos[posicaoLinhaRato + j][posicaoColunaRato] >= 20 && matrizObjetos[posicaoLinhaRato + j][posicaoColunaRato] <= 25){
			vetorInicioBaixo[0] = posicaoLinhaRato + j - 1, vetorInicioBaixo[1] = posicaoColunaRato;
			break;
		} else {
			j++;
		}
	}
	j = 1;
	i = true;
	while (i == true){
		if (matrizObjetos[posicaoLinhaRato - j][posicaoColunaRato] >= 20 && matrizObjetos[posicaoLinhaRato + j][posicaoColunaRato] <= 25){
			vetorInicioCima[0] = posicaoLinhaRato - j + 1, vetorInicioCima[1] = posicaoColunaRato;
			break;
		} else {
			j++;
		}
	}
}

void AreasAcessiveis(int posicaoInicialLinha, int posicaoInicialColuna, bool &validacao, bool seComecaEmCima){
	ZerarMatrizArea();

	matrizArea[posicaoInicialLinha][posicaoInicialColuna] = 1;
	int linha = posicaoInicialLinha, coluna = posicaoInicialColuna, contagem = 0;
	bool qubrarWhile = false, direita = false, cima = false, esquerda = seComecaEmCima, baixo = false;
	bool seNadaEmVolta = (!(matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25)) && (!(matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25)) && (!(matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25)) && (!(matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25));

	while (qubrarWhile == false){
		
		if (seNadaEmVolta){
			if (direita == true){
				matrizArea[linha + 1][coluna] = 1;
				linha += 1, baixo = true, direita = cima = esquerda = false;
			}
			else if (cima == true){
				matrizArea[linha][coluna + 1] = 1;
				coluna += 1, direita = true, baixo = cima = esquerda = false;
			} 
			else if (esquerda == true){
				matrizArea[linha - 1][coluna] = 1;
				linha -= 1, cima = true, direita = baixo = esquerda = false;
			}
			else if (baixo == true){
				matrizArea[linha][coluna - 1] = 1;
				coluna -= 1, esquerda = true, direita = cima = baixo = false;
			}
		} else {
			if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
				if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
					if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
						if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
							validacao = false;
						} else {
							if (cima == true){
								if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
									if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
										if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
											matrizArea[linha + 1][coluna] = 1;
											linha += 1, baixo = true, direita = cima = esquerda = false;
										} else {
											matrizArea[linha][coluna - 1] = 1;
											coluna -= 1, esquerda = true, direita = cima = baixo = false;
										}
									} else {
										matrizArea[linha - 1][coluna] = 1;
										linha -= 1, cima = true, direita = esquerda = baixo = false;
									}
								} else {
									matrizArea[linha][coluna + 1] = 1;
									coluna += 1, direita = true, cima = baixo = esquerda = false;
								}
							}
							else if (esquerda == true){
								if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
									if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
										if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
											matrizArea[linha][coluna + 1] = 1;
											coluna += 1, direita = true, baixo = cima = esquerda = false;
										} else {
											matrizArea[linha + 1][coluna] = 1;
											linha += 1, baixo = true, direita = cima = esquerda = false;
										}
									} else {
										matrizArea[linha][coluna - 1] = 1;
										coluna -= 1, esquerda = true, direita = cima = baixo = false;
									}
								} else {
									matrizArea[linha - 1][coluna] = 1;
									linha -= 1, cima = true, direita = baixo = esquerda = false;
								}
							}
							else if (baixo == true){
								if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
									if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
										if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
											matrizArea[linha - 1][coluna] = 1;
											linha -= 1, cima = true, direita = baixo = esquerda = false;
										} else {
											matrizArea[linha][coluna + 1] = 1;
											coluna += 1, direita = true, cima = baixo = esquerda = false;
										}
									} else {
										matrizArea[linha + 1][coluna] = 1;
										linha += 1, baixo = true, direita = esquerda = cima = false;
									}
								} else {
									matrizArea[linha][coluna - 1] = 1;
									coluna -= 1, esquerda = true, direita = cima = baixo = false;
								}
							}
							 else {
								matrizArea[linha + 1][coluna] = 1;
								linha += 1, baixo = true, direita = cima = esquerda = false;
							}
						}
					} else {
						if (direita == true){
							if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
								if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
									if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
										matrizArea[linha][coluna - 1] = 1;
										coluna -= 1, esquerda = true, direita = cima = baixo = false;
									} else {
										matrizArea[linha - 1][coluna] = 1;
										linha -= 1, cima = true, direita = baixo = esquerda = false;
									}
								} else {
									matrizArea[linha][coluna + 1] = 1;
									coluna += 1, direita = true, esquerda = cima = baixo = false;
								}
							} else {
								matrizArea[linha + 1][coluna] = 1;
								linha += 1, baixo = true, direita = cima = esquerda = false;
							}
						}
						else if (cima == true){
							if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
								if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
									if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
										matrizArea[linha + 1][coluna] = 1;
										linha += 1, baixo = true, direita = cima = esquerda = false;
									} else {
										matrizArea[linha][coluna - 1] = 1;
										coluna -= 1, esquerda = true, direita = cima = baixo = false;
									}
								} else {
									matrizArea[linha - 1][coluna] = 1;
									linha -= 1, cima = true, direita = esquerda = baixo = false;
								}
							} else {
								matrizArea[linha][coluna + 1] = 1;
								coluna += 1, direita = true, cima = baixo = esquerda = false;
							}
						}
						else if (esquerda == true){
							if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
								if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
									if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
										matrizArea[linha][coluna + 1] = 1;
										coluna += 1, direita = true, baixo = cima = esquerda = false;
									} else {
										matrizArea[linha + 1][coluna] = 1;
										linha += 1, baixo = true, direita = cima = esquerda = false;
									}
								} else {
									matrizArea[linha][coluna - 1] = 1;
									coluna -= 1, esquerda = true, direita = cima = baixo = false;
								}
							} else {
								matrizArea[linha - 1][coluna] = 1;
								linha -= 1, cima = true, direita = baixo = esquerda = false;
							}
						} else {
								matrizArea[linha][coluna - 1] = 1;
								coluna -= 1, esquerda = true, direita = cima = baixo = false;
						}
					}
				} else {
					if (baixo == true){
						if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
							if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
								if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
									matrizArea[linha - 1][coluna] = 1;
									linha -= 1, cima = true, direita = baixo = esquerda = false;
								} else {
									matrizArea[linha][coluna + 1] = 1;
									coluna += 1, direita = true, cima = baixo = esquerda = false;
								}
							} else {
								matrizArea[linha + 1][coluna] = 1;
								linha += 1, baixo = true, direita = esquerda = cima = false;
							}
						} else {
							matrizArea[linha][coluna - 1] = 1;
							coluna -= 1, esquerda = true, direita = cima = baixo = false;
						}
					}
					else if (direita == true){
						if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
							if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
								if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
									matrizArea[linha][coluna - 1] = 1;
									coluna -= 1, esquerda = true, direita = cima = baixo = false;
								} else {
									matrizArea[linha - 1][coluna] = 1;
									linha -= 1, cima = true, direita = baixo = esquerda = false;
								}
							} else {
								matrizArea[linha][coluna + 1] = 1;
								coluna += 1, direita = true, esquerda = cima = baixo = false;
							}
						} else {
							matrizArea[linha + 1][coluna] = 1;
							linha += 1, baixo = true, direita = cima = esquerda = false;
						}
					}
					else if (cima == true){
						if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
							if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
								if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
									matrizArea[linha + 1][coluna] = 1;
									linha += 1, baixo = true, direita = cima = esquerda = false;
								} else {
									matrizArea[linha][coluna - 1] = 1;
									coluna -= 1, esquerda = true, direita = cima = baixo = false;
								}
							} else {
								matrizArea[linha - 1][coluna] = 1;
								linha -= 1, cima = true, direita = esquerda = baixo = false;
							}
						} else {
							matrizArea[linha][coluna + 1] = 1;
							coluna += 1, direita = true, cima = baixo = esquerda = false;
						}
					} else {
						matrizArea[linha - 1][coluna] = 1;
						linha -= 1, cima = true, direita = baixo = esquerda = false;
					}
				}
			} else {
				if (esquerda == true){
					if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
						if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
							if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
								matrizArea[linha][coluna + 1] = 1;
								coluna += 1, direita = true, baixo = cima = esquerda = false;
							} else {
								matrizArea[linha + 1][coluna] = 1;
								linha += 1, baixo = true, direita = cima = esquerda = false;
							}
						} else {
							matrizArea[linha][coluna - 1] = 1;
							coluna -= 1, esquerda = true, direita = cima = baixo = false;
						}
					} else {
						matrizArea[linha - 1][coluna] = 1;
						linha -= 1, cima = true, direita = baixo = esquerda = false;
					}
				}
				else if (baixo == true){
					if (matrizObjetos[linha][coluna - 1] >= 20 && matrizObjetos[linha][coluna - 1] <= 25){
						if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
							if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
								matrizArea[linha - 1][coluna] = 1;
								linha -= 1, cima = true, direita = baixo = esquerda = false;
							} else {
								matrizArea[linha][coluna + 1] = 1;
								coluna += 1, direita = true, cima = baixo = esquerda = false;
							}
						} else {
							matrizArea[linha + 1][coluna] = 1;
							linha += 1, baixo = true, direita = esquerda = cima = false;
						}
					} else {
						matrizArea[linha][coluna - 1] = 1;
						coluna -= 1, esquerda = true, direita = cima = baixo = false;
					}
				}
				else if (direita == true){
					if (matrizObjetos[linha + 1][coluna] >= 20 && matrizObjetos[linha + 1][coluna] <= 25){
						if (matrizObjetos[linha][coluna + 1] >= 20 && matrizObjetos[linha][coluna + 1] <= 25){
							if (matrizObjetos[linha - 1][coluna] >= 20 && matrizObjetos[linha - 1][coluna] <= 25){
								matrizArea[linha][coluna - 1] = 1;
								coluna -= 1, esquerda = true, direita = cima = baixo = false;
							} else {
								matrizArea[linha - 1][coluna] = 1;
								linha -= 1, cima = true, direita = baixo = esquerda = false;
							}
						} else {
							matrizArea[linha][coluna + 1] = 1;
							coluna += 1, direita = true, esquerda = cima = baixo = false;
						}
					} else {
						matrizArea[linha + 1][coluna] = 1;
						linha += 1, baixo = true, direita = cima = esquerda = false;
					}
				} else {
					matrizArea[linha][coluna + 1] = 1;
					coluna += 1, direita = true, baixo = cima = esquerda = false;
				}
			}
		}

		if (posicaoInicialLinha == linha && posicaoInicialColuna == coluna){
			if (contagem != 3){
				contagem++;
			} else {
			qubrarWhile = true;
			}
		}
	}
}

void gerarAreasAcessiveisRatoEQueijo(int posicaoLinhaInicialRato, int posicaoColunaInicialRato, int posicaoLinhaInicialQueijo, int posicaoColunaInicialQueijo,bool &validacao){
	int posicaoInicialDireita[2], posicaoInicialBaixo[2], posicaoInicialCima[2], matrizAuxiliar[tamanhoMatrizFase][tamanhoMatrizFase];
	bool compararAreaComAuxiliar = true, compararAreaComRato = true, compararAuxiliarComRato = true, compararAreaComQueijo = true, compararAuxiliarComQueijo = true;



	ateEncontrarParede(posicaoLinhaInicialRato, posicaoColunaInicialRato, posicaoInicialDireita, posicaoInicialBaixo, posicaoInicialCima);


	AreasAcessiveis(posicaoInicialDireita[0], posicaoInicialDireita[1], validacao, false);
	zerarMatrizAreaRato();
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAreaRato[i][j] = matrizArea[i][j];
		}
	}
	AreasAcessiveis(posicaoInicialBaixo[0], posicaoInicialBaixo[1], validacao, false);
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAuxiliar[i][j] = 0;
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAuxiliar[i][j] = matrizArea[i][j];
		}
	}
	AreasAcessiveis(posicaoInicialCima[0], posicaoInicialCima[1], validacao, true);

	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizArea[i][j] != matrizAreaRato[i][j]){
				compararAreaComRato = false;
			}
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizAuxiliar[i][j] != matrizAreaRato[i][j]){
				compararAuxiliarComRato = false;
			}
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizArea[i][j] != matrizAuxiliar[i][j]){
				compararAreaComAuxiliar = false;
			}
		}
	}
	//	DADOS==tirardepois
	cout << "mapas rato:\n";
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
	cout << endl;
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			if (matrizAuxiliar[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizAuxiliar[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			if (matrizArea[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizArea[i][j];
			}
		}
		cout << endl;
	}
	cout << "\ncomparacao dos mapas:\t" << compararAreaComRato << "\t" << compararAuxiliarComRato << "\t" << compararAreaComAuxiliar << endl << "mapas Queijo:\n";
	//tirar

	if (!(compararAreaComRato == true && compararAuxiliarComRato == true && compararAreaComAuxiliar == true)){
		if (compararAreaComRato == false){
			for (int i = 0; i < tamanhoMatrizFase; i++){
				for (int j = 0; j < tamanhoMatrizFase; j++){
					matrizAreaRato[i][j] = matrizAuxiliar[i][j];
				}
			}
		}
		else if (compararAuxiliarComRato == false){
			for (int i = 0; i < tamanhoMatrizFase; i++){
				for (int j = 0; j < tamanhoMatrizFase; j++){
					matrizAreaRato[i][j] = matrizArea[i][j];
				}
			}
		}
	}

	


	ateEncontrarParede(posicaoLinhaInicialQueijo, posicaoColunaInicialQueijo, posicaoInicialDireita, posicaoInicialBaixo, posicaoInicialCima);


	AreasAcessiveis(posicaoInicialDireita[0], posicaoInicialDireita[1], validacao, false);
	zerarMatrizAreaQueijo();
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAreaQueijo[i][j] = matrizArea[i][j];
		}
	}
	AreasAcessiveis(posicaoInicialBaixo[0], posicaoInicialBaixo[1], validacao, false);
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAuxiliar[i][j] = 0;
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			matrizAuxiliar[i][j] = matrizArea[i][j];
		}
	}
	AreasAcessiveis(posicaoInicialCima[0], posicaoInicialCima[1], validacao, true);

	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizArea[i][j] != matrizAreaQueijo[i][j]){
				compararAreaComQueijo = false;
			}
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizAuxiliar[i][j] != matrizAreaQueijo[i][j]){
				compararAuxiliarComQueijo = false;
			}
		}
	}
	for (int i = 0; i < tamanhoMatrizFase; i++){
		for (int j = 0; j < tamanhoMatrizFase; j++){
			if (matrizArea[i][j] != matrizAuxiliar[i][j]){
				compararAreaComAuxiliar = false;
			}
		}
	}
	//	DADOS==tirardepois
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
	cout << endl;
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			if (matrizAuxiliar[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizAuxiliar[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < tamanhoMatrizFase; i++) {
		for (int j = 0; j < tamanhoMatrizFase; j++) {
			if (matrizArea[i][j] == 1){
				cout << (char) 219;
			} else {
				cout << matrizArea[i][j];
			}
		}
		cout << endl;
	}
	cout << "\ncomparacao dos mapas:\t" << compararAreaComQueijo << "\t" << compararAuxiliarComQueijo << "\t" << compararAreaComAuxiliar << endl;
	//tirar----------------------

	if (!(compararAreaComQueijo == true && compararAuxiliarComQueijo == true && compararAreaComAuxiliar == true)){
		if (compararAreaComQueijo == false){
			for (int i = 0; i < tamanhoMatrizFase; i++){
				for (int j = 0; j < tamanhoMatrizFase; j++){
					matrizAreaQueijo[i][j] = matrizAuxiliar[i][j];
				}
			}
		}
		else if (compararAuxiliarComQueijo == false){
			for (int i = 0; i < tamanhoMatrizFase; i++){
				for (int j = 0; j < tamanhoMatrizFase; j++){
					matrizAreaQueijo[i][j] = matrizArea[i][j];
				}
			}
		}
	}
}

bool validacaoDaFase() {
	transformarVetorObjetoEmMatriz();
	
	bool validacao;
	int valorPosicaoRato[2], valorPosicaoQueijo[2];
	
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

	gerarAreasAcessiveisRatoEQueijo(valorPosicaoRato[0], valorPosicaoRato[1], valorPosicaoQueijo[0], valorPosicaoQueijo[1], validacao);
	
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
