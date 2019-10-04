#ifndef MOVIMENTACAORATO_H
#define MOVIMENTACAORATO_H

#include"ConstrucaoFase.h"
#include"ValidacaoFase.h"

void conversaoMatrizObjetosEmMatrizFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase ,int paredes , bool queijo, int i = 0, int j = 0, int k = 1){

    if (i == 0 || i == tamanhoFase - 1){
        matrizFase[i][j] = (char)219;
    }
    else if (j == 0 || j == 1 || j == tamanhoFase * 2 - 1 || j == tamanhoFase * 2 - 2){
        matrizFase[i][j] = (char)219;
    } else {
        if (matrizFase[i][j] == (char)219 || matrizFase[i][j] == (char)32 || matrizFase[i][j] == (char)176 || matrizFase[i][j] == (char)81){
        } else {
            if (matrizObjetos[i][k] > paredes){
                matrizFase[i][j] = (char)219;
                matrizFase[i][j + 1] = (char)219;
                k++;
            } else {	
                switch (matrizObjetos[i][k]){
                case -1:
                    matrizFase[i][j] = (char)176;
                    matrizFase[i][j + 1] = (char)176;
                    k++;
                    break;
                    
                case 1:
                    matrizFase[i][j] = (char)81;
                    matrizFase[i][j + 1] = (char)32;
                    k++;
                    break;
                
                case 2:
                    matrizFase[i][j] = (char)82;
                    if (queijo){
                        matrizFase[i][j + 1] = (char)81;
                    } else {
                        matrizFase[i][j + 1] = (char)32;
                    }
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

    if (j < tamanhoFase * 2 - 1){
        conversaoMatrizObjetosEmMatrizFase(matrizFase, matrizObjetos, tamanhoFase, paredes, queijo, i, j + 1, k);
    }
	
	else if (i < tamanhoFase - 1){
        j = 0;
        k = 1;
        conversaoMatrizObjetosEmMatrizFase(matrizFase, matrizObjetos, tamanhoFase, paredes, queijo, i + 1, j, k);
	} else {
        cout << "\n";
        return;
    }
}

void printMomentaneoFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase ,int paredes, int linhaAtualRato, int colunaAtualRato, bool queijo){
    cls();
    matrizObjetos[linhaAtualRato][colunaAtualRato] = 2;
    ZerarMatrizFase(matrizFase, tamanhoFase);
    conversaoMatrizObjetosEmMatrizFase( matrizFase, matrizObjetos, tamanhoFase,  paredes, queijo);
    exibeFase(matrizFase, tamanhoFase);
    matrizObjetos[linhaAtualRato][colunaAtualRato] = -1;
    Sleep(10);//*/
}

//      RANDOM      //
void movimentoAleatorioRato (int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int posicaoInicialLinhaRato, int posicaoInicialColunaRato, int posicaoLinhaQueijo, int posicaoColunaQueijo, int paredes, bool ultDireita = false, bool ultCima = false, bool ultEsquerda = false, bool ultBaixo = false){
    int DoisNumerosAleatorios[2], TresNumerosAleatorios[3], QuatroNumerosAleatorios[4];
    bool paredeDireita = (matrizObjetos[posicaoInicialLinhaRato][posicaoInicialColunaRato + 1] > paredes && matrizObjetos[posicaoInicialLinhaRato][posicaoInicialColunaRato + 1] <= tamanhoObjetos),
	paredeCima = (matrizObjetos[posicaoInicialLinhaRato - 1][posicaoInicialColunaRato] > paredes && matrizObjetos[posicaoInicialLinhaRato - 1][posicaoInicialColunaRato] <= tamanhoObjetos),
	paredeEsquerda = (matrizObjetos[posicaoInicialLinhaRato][posicaoInicialColunaRato - 1] > paredes && matrizObjetos[posicaoInicialLinhaRato][posicaoInicialColunaRato - 1] <= tamanhoObjetos),
	paredeBaixo = (matrizObjetos[posicaoInicialLinhaRato + 1][posicaoInicialColunaRato] > paredes && matrizObjetos[posicaoInicialLinhaRato + 1][posicaoInicialColunaRato] <= tamanhoObjetos);
    

    if (matrizObjetos[posicaoInicialLinhaRato][posicaoInicialColunaRato] == matrizObjetos[posicaoLinhaQueijo][posicaoColunaQueijo]){
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        return;
    }

    if (!paredeDireita && !ultEsquerda){
        if (!paredeCima && !ultBaixo){
            if (!paredeEsquerda && !ultDireita){
                if (!paredeBaixo && !ultCima){
                    geraNumeroAleatorio(QuatroNumerosAleatorios, 4);
                    printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                    switch (QuatroNumerosAleatorios[3])
                    {
                    case 3:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultDireita = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 2:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultCima = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 1:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultEsquerda = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 4:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultBaixo = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    }
                    printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
                } else {
                    geraNumeroAleatorio(TresNumerosAleatorios, 3);
                    printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                    switch (TresNumerosAleatorios[2])
                    {
                    case 2:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultDireita = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 3:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultCima = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 1:
                        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultEsquerda = true;
                        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    }
                    printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
                }
            }

            else if (!paredeBaixo && !ultCima){
                geraNumeroAleatorio(TresNumerosAleatorios, 3);
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                switch (TresNumerosAleatorios[0])
                {
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 2:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 3:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultBaixo = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
            } else {
                geraNumeroAleatorio(DoisNumerosAleatorios, 2);
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                switch (DoisNumerosAleatorios[1])
                {
                case 2:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
            }
        }
        else if (!paredeEsquerda && !ultDireita){
            if (!paredeBaixo && !ultCima){
                geraNumeroAleatorio(TresNumerosAleatorios, 3);
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                switch (TresNumerosAleatorios[1])
                {
                case 3:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 2:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultEsquerda = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultBaixo = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
            } else {
                geraNumeroAleatorio(DoisNumerosAleatorios, 2);
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                switch (DoisNumerosAleatorios[0])
                {
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 2:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultEsquerda = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
            }
        }
        else if (!paredeBaixo && !ultCima){
            geraNumeroAleatorio(DoisNumerosAleatorios, 2);
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
            switch (DoisNumerosAleatorios[0])
            {
            case 2:
                ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultDireita = true;
                movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            case 1:
                ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultBaixo = true;
                movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            }
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        } else {
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
            ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
            ultDireita = true;
            movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);  
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        }

    }
    else if (!paredeCima && !ultBaixo){
        if (!paredeEsquerda && !ultDireita){
            if (!paredeBaixo && !ultCima){
                geraNumeroAleatorio(TresNumerosAleatorios, 3);
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                switch (TresNumerosAleatorios[2])
                {
                case 2:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 3:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultEsquerda = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultBaixo = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
            } else {
                geraNumeroAleatorio(DoisNumerosAleatorios, 2);
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
                switch (DoisNumerosAleatorios[0])
                {
                case 2:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultEsquerda = true;
                    movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
            }
        }
        else if (!paredeBaixo && !ultCima){
            geraNumeroAleatorio(DoisNumerosAleatorios, 2);
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
            switch (DoisNumerosAleatorios[1])
            {
            case 2:
                ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultCima = true;
                movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            case 1:
                ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultBaixo = true;
                movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            }
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        } else {
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
            ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
            ultCima = true;
            movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        }

    }
    else if (!paredeEsquerda && !ultDireita){
        if (!paredeBaixo && !ultCima){
            geraNumeroAleatorio(DoisNumerosAleatorios, 2);
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
            switch (DoisNumerosAleatorios[1])
            {
            case 2:
                ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultEsquerda = true;
                movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            case 1:
                ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultBaixo = true;
                movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            }
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        } else {
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
            ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
            ultEsquerda = true;
            movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
            printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
        }

    }
    else if (!paredeBaixo && !ultCima){
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
        ultBaixo = true;
        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
    } else {
        if (ultDireita){
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
        ultEsquerda = true;
        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
    }
    else if (ultCima){
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
        ultBaixo = true;
        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato + 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
    }
    else if (ultEsquerda){
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
        ultDireita = true;
        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato, posicaoInicialColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);  
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
    }
    else if (ultBaixo){
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, false);
        ultDireita = false, ultCima = false, ultEsquerda = false, ultBaixo = false;
        ultCima = true;
        movimentoAleatorioRato(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoInicialLinhaRato - 1, posicaoInicialColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase( matrizFase,  matrizObjetos,  tamanhoFase , paredes, posicaoInicialLinhaRato, posicaoInicialColunaRato, true);
    }
    }

}



#endif