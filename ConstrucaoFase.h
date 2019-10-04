#ifndef CONSTRUCAOFASE_H
#define CONSTRUCAOFASE_H

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

const int tamanhoMatrizFase = 62, tamanhoVetorObjetos = (tamanhoMatrizFase - 2) * (tamanhoMatrizFase - 2);


void clearScreen(HANDLE hConsole){
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)){
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)){
		return;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);
}

void cls(){
	HANDLE hStdout;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	clearScreen(hStdout);
}

void ZerarMatrizFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int tamanhoFase, int i = 0, int j = 0){
		
		matrizFase[i][j] = 'a';
	if (j < tamanhoFase * 2 - 1){
		ZerarMatrizFase(matrizFase, tamanhoFase, i, j + 1);
	}
	else if (i < tamanhoFase - 1){
		ZerarMatrizFase(matrizFase, tamanhoFase, i + 1, 0);
	}
}

bool teste(int valor, int array[], int max){

		for(int i = 0; i <= max; i++) if(valor == array[i]) return true;
		return false;
}

void geraNumeroAleatorio(int array[], int tamanhoArray){
	int i = 0, x = 0;

	memset(array, 0, sizeof(int) * tamanhoArray);
	srand(time(NULL));
	while(true){
		if (i == tamanhoArray) break;
		x = (1 + (rand() % tamanhoArray));
		if(!teste(x, array, i)) array[i++] = x;
	}
}

void criacaoFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int vetorDosObjetos[], int tamanhoFase, int tamanhoObjetos, int quantParedes) {

	geraNumeroAleatorio(vetorDosObjetos, tamanhoObjetos);
	ZerarMatrizFase(matrizFase, tamanhoFase);

	for (int i = 0, k = 0; i < tamanhoFase; i++){
		for (int j = 0; j < tamanhoFase * 2; j++){
			if (i == 0 || i == tamanhoFase - 1){
				matrizFase[i][j] = (char)219;
			}
			else if (j == 0 || j == 1 || j == tamanhoFase * 2 - 1 || j == tamanhoFase * 2 - 2){
				matrizFase[i][j] = (char)219;
			} else {
				if (matrizFase[i][j] == (char)219 || matrizFase[i][j] == (char)32){
				}
				else if (matrizFase[i][j - 1] == (char)81 || matrizFase[i][j - 1] == (char)82){
					matrizFase[i][j] = (char)32;
				} else {
					if (vetorDosObjetos[k] > quantParedes){
						matrizFase[i][j] = (char)219;
						matrizFase[i][j + 1] = (char)219;
						k++;
					} else{	
						switch (vetorDosObjetos[k]){
						case 1:
							matrizFase[i][j] = (char)81;
							k++;
							break;
						
						case 2:
							matrizFase[i][j] = (char)82;
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
}

void exibeFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int tamanhoFase, int i = 0, int j = 0) {
	
		cout << matrizFase[i][j];
	if (j < tamanhoFase * 2 - 1){
		exibeFase(matrizFase, tamanhoFase, i, j + 1);
	}
	else if (i < tamanhoFase - 1){
		cout << endl;
		exibeFase(matrizFase, tamanhoFase, i + 1, 0);
	}
}


#endif
