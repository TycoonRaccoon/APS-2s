#ifndef MOVIMENTACAORATO_H
#define MOVIMENTACAORATO_H

#include"ConstrucaoFase.h"
#include"ValidacaoFase.h"

void conversaoMatrizObjetosEmMatrizFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase ,int paredes, int saida[], bool queijo, int i = 0, int j = 0, int k = 1){

    if (i == 0 || i == tamanhoFase - 1 || j == 0 || j == 1 || j == tamanhoFase * 2 - 1 || j == tamanhoFase * 2 - 2){
        matrizFase[i][j] = (char)219;
    } else {
        if (matrizFase[i][j] == (char)219 || matrizFase[i][j] == (char)32 || matrizFase[i][j] == (char)176 || matrizFase[i][j] == (char)81 || matrizFase[i][j] == (char)65){
        }
        else if (i == saida[0] && k == saida[1]){
            matrizFase[i][j] = (char)83;
            matrizFase[i][j + 1]= (char)65;
            k++;
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
        conversaoMatrizObjetosEmMatrizFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida, queijo, i, j + 1, k);
    }
	
	else if (i < tamanhoFase - 1){
        conversaoMatrizObjetosEmMatrizFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida, queijo, i + 1, 0, 1);
	} else {
        cout << "\n";
        return;
    }
}

void printMomentaneoFase(char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase ,int paredes, int linhaAtualRato, int colunaAtualRato, int saida[], bool queijo){
    system("cls");
    matrizObjetos[linhaAtualRato][colunaAtualRato] = 2;
    ZerarMatrizFase(matrizFase, tamanhoFase);
    conversaoMatrizObjetosEmMatrizFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida, queijo);
    exibeFase(matrizFase, tamanhoFase);
    matrizObjetos[linhaAtualRato][colunaAtualRato] = -1;
    Sleep(7);
}

//      RANDOM      //

bool movimentoRandom (int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int posicaoLinhaRato, int posicaoColunaRato, int posicaoLinhaQueijo, int posicaoColunaQueijo, int paredes, int saida[], int DoisNumerosAleatorios[], int TresNumerosAleatorios[], int QuatroNumerosAleatorios[], bool ultDireita = false, bool ultCima = false, bool ultEsquerda = false, bool ultBaixo = false){
    bool paredeDireita = (matrizObjetos[posicaoLinhaRato][posicaoColunaRato + 1] > paredes && matrizObjetos[posicaoLinhaRato][posicaoColunaRato + 1] <= tamanhoObjetos),
	paredeCima = (matrizObjetos[posicaoLinhaRato - 1][posicaoColunaRato] > paredes && matrizObjetos[posicaoLinhaRato - 1][posicaoColunaRato] <= tamanhoObjetos),
	paredeEsquerda = (matrizObjetos[posicaoLinhaRato][posicaoColunaRato - 1] > paredes && matrizObjetos[posicaoLinhaRato][posicaoColunaRato - 1] <= tamanhoObjetos),
	paredeBaixo = (matrizObjetos[posicaoLinhaRato + 1][posicaoColunaRato] > paredes && matrizObjetos[posicaoLinhaRato + 1][posicaoColunaRato] <= tamanhoObjetos),
    result;
    

    if (matrizObjetos[posicaoLinhaRato][posicaoColunaRato] == matrizObjetos[posicaoLinhaQueijo][posicaoColunaQueijo]){
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        return false;
    }

    if (!paredeDireita && !ultEsquerda){
        if (!paredeCima && !ultBaixo){
            if (!paredeEsquerda && !ultDireita){
                if (!paredeBaixo && !ultCima){
                    geraNumeroAleatorio(QuatroNumerosAleatorios, 4);
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                    switch (QuatroNumerosAleatorios[3])
                    {
                    case 3:
                        ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultDireita = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 2:
                        ultDireita = false, ultEsquerda = false, ultBaixo = false;
                        ultCima = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 1:
                        ultDireita = false, ultCima = false, ultBaixo = false;
                        ultEsquerda = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 4:
                        ultDireita = false, ultCima = false, ultEsquerda = false;
                        ultBaixo = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    }
                    if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                        return true;
                    }
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
                } else {
                    geraNumeroAleatorio(TresNumerosAleatorios, 3);
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                    switch (TresNumerosAleatorios[2])
                    {
                    case 2:
                        ultCima = false, ultEsquerda = false, ultBaixo = false;
                        ultDireita = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 3:
                        ultDireita = false, ultEsquerda = false, ultBaixo = false;
                        ultCima = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    case 1:
                        ultDireita = false, ultCima = false, ultBaixo = false;
                        ultEsquerda = true;
                        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                        break;
                    }
                    if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                        return true;
                    }
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
                }
            }

            else if (!paredeBaixo && !ultCima){
                geraNumeroAleatorio(TresNumerosAleatorios, 3);
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                switch (TresNumerosAleatorios[0])
                {
                case 1:
                    ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 2:
                    ultDireita = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 3:
                    ultDireita = false, ultCima = false, ultEsquerda = false;
                    ultBaixo = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                    return true;
                }
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
            } else {
                geraNumeroAleatorio(DoisNumerosAleatorios, 2);
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                switch (DoisNumerosAleatorios[1])
                {
                case 2:
                    ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                    return true;
                }
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
            }
        }
        else if (!paredeEsquerda && !ultDireita){
            if (!paredeBaixo && !ultCima){
                geraNumeroAleatorio(TresNumerosAleatorios, 3);
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                switch (TresNumerosAleatorios[1])
                {
                case 3:
                    ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 2:
                    ultDireita = false, ultCima = false, ultBaixo = false;
                    ultEsquerda = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false;
                    ultBaixo = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                    return true;
                }
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
            } else {
                geraNumeroAleatorio(DoisNumerosAleatorios, 2);
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                switch (DoisNumerosAleatorios[0])
                {
                case 1:
                    ultCima = false, ultEsquerda = false, ultBaixo = false;
                    ultDireita = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 2:
                    ultDireita = false, ultCima = false, ultBaixo = false;
                    ultEsquerda = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                    return true;
                }
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
            }
        }
        else if (!paredeBaixo && !ultCima){
            geraNumeroAleatorio(DoisNumerosAleatorios, 2);
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            switch (DoisNumerosAleatorios[0])
            {
            case 2:
                ultCima = false, ultEsquerda = false, ultBaixo = false;
                ultDireita = true;
                result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            case 1:
                ultDireita = false, ultCima = false, ultEsquerda = false;
                ultBaixo = true;
                result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            }
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        } else {
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultCima = false, ultEsquerda = false, ultBaixo = false;
            ultDireita = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);  
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }

    }
    else if (!paredeCima && !ultBaixo){
        if (!paredeEsquerda && !ultDireita){
            if (!paredeBaixo && !ultCima){
                geraNumeroAleatorio(TresNumerosAleatorios, 3);
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                switch (TresNumerosAleatorios[2])
                {
                case 2:
                    ultDireita = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 3:
                    ultDireita = false, ultCima = false, ultBaixo = false;
                    ultEsquerda = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultEsquerda = false;
                    ultBaixo = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                    return true;
                }
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
            } else {
                geraNumeroAleatorio(DoisNumerosAleatorios, 2);
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
                switch (DoisNumerosAleatorios[0])
                {
                case 2:
                    ultDireita = false, ultEsquerda = false, ultBaixo = false;
                    ultCima = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                case 1:
                    ultDireita = false, ultCima = false, ultBaixo = false;
                    ultEsquerda = true;
                    result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                    break;
                }
                if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                    printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                    return true;
                }
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
            }
        }
        else if (!paredeBaixo && !ultCima){
            geraNumeroAleatorio(DoisNumerosAleatorios, 2);
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            switch (DoisNumerosAleatorios[1])
            {
            case 2:
                ultDireita = false, ultEsquerda = false, ultBaixo = false;
                ultCima = true;
                result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            case 1:
                ultDireita = false, ultCima = false, ultEsquerda = false;
                ultBaixo = true;
                result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            }
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        } else {
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultDireita = false, ultEsquerda = false, ultBaixo = false;
            ultCima = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }

    }
    else if (!paredeEsquerda && !ultDireita){
        if (!paredeBaixo && !ultCima){
            geraNumeroAleatorio(DoisNumerosAleatorios, 2);
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            switch (DoisNumerosAleatorios[1])
            {
            case 2:
                ultDireita = false, ultCima = false, ultBaixo = false;
                ultEsquerda = true;
                result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            case 1:
                ultDireita = false, ultCima = false, ultEsquerda = false;
                ultBaixo = true;
                result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
                break;
            }
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        } else {
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultDireita = false, ultCima = false, ultBaixo = false;
            ultEsquerda = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }

    }
    else if (!paredeBaixo && !ultCima){
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
        ultDireita = false, ultCima = false, ultEsquerda = false;
        ultBaixo = true;
        result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
        if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
            return true;
        }
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
    } else {
        if (ultDireita){
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultDireita = false, ultCima = false, ultBaixo = false;
            ultEsquerda = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato - 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }
        else if (ultCima){
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultDireita = false, ultCima = false, ultEsquerda = false;
            ultBaixo = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato + 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }
        else if (ultEsquerda){
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultCima = false, ultEsquerda = false, ultBaixo = false;
            ultDireita = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato, posicaoColunaRato + 1, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);  
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }
        else if (ultBaixo){
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, false);
            ultDireita = false, ultEsquerda = false, ultBaixo = false;
            ultCima = true;
            result = movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, posicaoLinhaRato - 1, posicaoColunaRato, posicaoLinhaQueijo, posicaoColunaQueijo, paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios, ultDireita, ultCima, ultEsquerda, ultBaixo);
            if ((posicaoLinhaRato == saida[0] && posicaoColunaRato == saida[1]) || result){
                printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, saida[0], saida[1], saida, true);
                return true;
            }
            printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, paredes, posicaoLinhaRato, posicaoColunaRato, saida, true);
        }
    }
}

void movimentoAleatorioRato(int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int valorPosicaoRato[], int valorPosicaoQueijo[], int paredes){
    int saida[2] = {valorPosicaoRato[0], valorPosicaoRato[1]}, DoisNumerosAleatorios[2], TresNumerosAleatorios[3], QuatroNumerosAleatorios[4];

    movimentoRandom(matrizObjetos, matrizFase, tamanhoFase, tamanhoObjetos, valorPosicaoRato[0], valorPosicaoRato[1], valorPosicaoQueijo[0], valorPosicaoQueijo[1], paredes, saida, DoisNumerosAleatorios, TresNumerosAleatorios, QuatroNumerosAleatorios);
}
//-----------------//



void gerarCaminho(int posicoesMarcadas[], int matriz[tamanhoMatrizFase][tamanhoMatrizFase],int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int matrizAuxiliar[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int inicioParedes, int index, int limite[], int i = 0){
    if (posicoesMarcadas[i] == limite[0] && posicoesMarcadas[i + 1] == limite[1]){
        matriz[posicoesMarcadas[i]][posicoesMarcadas[i + 1]] = 1;
        return;
	}
    marcaERetornaPosicoes(posicoesMarcadas[i], posicoesMarcadas[i + 1], matrizObjetos, matrizAuxiliar, posicoesMarcadas, index, tamanhoObjetos, inicioParedes);
    gerarCaminho(posicoesMarcadas, matriz, matrizObjetos, matrizAuxiliar, tamanhoFase, tamanhoObjetos, inicioParedes, index, limite, i + 2);
    if (posicoesMarcadas[i + 1] == limite[1] + 1 && posicoesMarcadas[i] == limite[0]){
        matriz[posicoesMarcadas[i]][posicoesMarcadas[i + 1]] = 1;
        limite[1] += 1;
    }
    else if (posicoesMarcadas[i] == limite[0] - 1 && posicoesMarcadas[i + 1] == limite[1]){
        matriz[posicoesMarcadas[i]][posicoesMarcadas[i + 1]] = 1;
        limite[0] -= 1;
    }
    else if (posicoesMarcadas[i + 1] == limite[1] - 1 && posicoesMarcadas[i] == limite[0]){
        matriz[posicoesMarcadas[i]][posicoesMarcadas[i + 1]] = 1;
        limite[1] -= 1;
    }
    else if (posicoesMarcadas[i] == limite[0] + 1 && posicoesMarcadas[i + 1] == limite[1]){
        matriz[posicoesMarcadas[i]][posicoesMarcadas[i + 1]] = 1;
        limite[0] += 1;
    }
}

void iniciarGeracaoDoCaminho(int posicaoInicial[], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int matriz[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int inicioParedes, int limite[]){
	int index = 0,
	posicoesMarcadas[2 * tamanhoVetorObjetos],
    limiteMutavel[2] = {limite[0], limite[1]},
    matrizAuxiliar[tamanhoMatrizFase][tamanhoMatrizFase];

	zerarMatrizDeArea(matriz, tamanhoFase);
	matriz[posicaoInicial[0]][posicaoInicial[1]] = 1;
    for (int i = 0; i < 2 * tamanhoObjetos; i++){
		posicoesMarcadas[i] = -1;
	}
	
    marcaERetornaPosicoes(posicaoInicial[0], posicaoInicial[1], matrizObjetos, matrizAuxiliar, posicoesMarcadas, index, tamanhoObjetos, inicioParedes);
	gerarCaminho(posicoesMarcadas, matriz, matrizObjetos, matrizAuxiliar, tamanhoFase, tamanhoObjetos, inicioParedes, index, limiteMutavel);

	/*//PRINT DADOS
	for (int i = 0, j = 0; i < 2 * tamanhoObjetos - (tamanhoObjetos - inicioParedes + 1); i++, j++){
		cout << posicoesMarcadas[i];
		if (j % 2 == 1){
			cout << "\t";
		}
	}
	cout << endl;//*/
}

void encontrarMenorCaminho(int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int matrizCaminho[tamanhoMatrizFase][tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int inicioParedes, int valorPosicaoRato[], int valorPosicaoQueijo[]) {
	int doisNumerosAletorios[2];
    geraNumeroAleatorio(doisNumerosAletorios, 2);
    zerarMatrizDeArea(matrizCaminho, tamanhoFase);
	
    (doisNumerosAletorios[0] == 1)?
	iniciarGeracaoDoCaminho(valorPosicaoRato, matrizObjetos, matrizCaminho, tamanhoFase, tamanhoObjetos, inicioParedes, valorPosicaoQueijo):
	iniciarGeracaoDoCaminho(valorPosicaoQueijo, matrizObjetos, matrizCaminho, tamanhoFase, tamanhoObjetos, inicioParedes, valorPosicaoRato);
    /*// PRINT DADOS
    for (int i = 0; i < tamanhoFase; i++){
        for (int j = 0; j < tamanhoFase; j++){
            if (matrizCaminho[i][j] == 1){
                cout << (char)219;
            } else {
            cout << matrizCaminho[i][j];
            }
        }
    cout << endl;
    }
	//*/
}


//      SMART      //

void movimentoSmart(int matrizCaminho[tamanhoMatrizFase][tamanhoMatrizFase], char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], int valorPosicaoQueijo[], int linhaInicial, int colunaInicial, int inicioParedes, int tamanhoFase, int saida[], bool ultDireita = false, bool ultCima = false, bool ultEsquerda = false, bool ultBaixo = false){

    if (linhaInicial == valorPosicaoQueijo[0] && colunaInicial == valorPosicaoQueijo[1]){
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, true);
        return;
    }

    if (matrizCaminho[linhaInicial][colunaInicial + 1] == 1 && !ultEsquerda){
        ultCima = false, ultEsquerda = false, ultBaixo = false;
        ultDireita = true;
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, false);
        movimentoSmart(matrizCaminho, matrizFase, matrizObjetos, valorPosicaoQueijo, linhaInicial, colunaInicial + 1, inicioParedes, tamanhoFase, saida, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, true);
    }
    else if (matrizCaminho[linhaInicial - 1][colunaInicial] == 1 && !ultBaixo){
        ultDireita = false, ultEsquerda = false, ultBaixo = false;
        ultCima = true;
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, false);
        movimentoSmart(matrizCaminho, matrizFase, matrizObjetos, valorPosicaoQueijo, linhaInicial - 1, colunaInicial, inicioParedes, tamanhoFase, saida, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, true);
    }
    else if (matrizCaminho[linhaInicial][colunaInicial - 1] == 1 && !ultDireita){
        ultDireita = false, ultCima = false, ultBaixo = false;
        ultEsquerda = true;
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, false);
        movimentoSmart(matrizCaminho, matrizFase, matrizObjetos, valorPosicaoQueijo, linhaInicial, colunaInicial - 1, inicioParedes, tamanhoFase, saida, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, true);
    }
    else if (matrizCaminho[linhaInicial + 1][colunaInicial] == 1 && !ultCima){
        ultDireita = false, ultCima = false, ultEsquerda = false;
        ultBaixo = true;
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, false);
        movimentoSmart(matrizCaminho, matrizFase, matrizObjetos, valorPosicaoQueijo, linhaInicial + 1, colunaInicial, inicioParedes, tamanhoFase, saida, ultDireita, ultCima, ultEsquerda, ultBaixo);
        printMomentaneoFase(matrizFase, matrizObjetos, tamanhoFase, inicioParedes, linhaInicial, colunaInicial, saida, true);
    }
}

void movimentoInteligenteRato(int matrizObjetos[tamanhoMatrizFase][tamanhoMatrizFase], char matrizFase[tamanhoMatrizFase][2 * tamanhoMatrizFase], int tamanhoFase, int tamanhoObjetos, int valorPosicaoRato[], int valorPosicaoQueijo[], int paredes){
    int matrizCaminho[tamanhoMatrizFase][tamanhoMatrizFase];
    int saida[2] = {valorPosicaoRato[0], valorPosicaoRato[1]};
    zerarMatrizDeArea(matrizCaminho, tamanhoFase);
    encontrarMenorCaminho(matrizObjetos, matrizCaminho, tamanhoFase, tamanhoObjetos, paredes, valorPosicaoRato, valorPosicaoQueijo);

    movimentoSmart(matrizCaminho, matrizFase, matrizObjetos, valorPosicaoQueijo, valorPosicaoRato[0], valorPosicaoRato[1], paredes, tamanhoFase, saida);
}

#endif