#include "../Headers/Ordenacao_simples.h"
/*
Para realizar as comparacoes usa-se a funcao strcmp da biblioteca <string.h>. Se ela retornar:
Um valor menor que zero: a primeira string é menor que a segunda
Um valor maior que zero: a primeira string é maior que a segunda
Retorna 0: as duas strings sao iguais
*/

//Ordena lista pelo metodo selecao
int Selecao(Tlista lista, int tam,int *conta_movimentacao, int *conta_comparacao){
    
    *(conta_comparacao) = 0;
    *(conta_movimentacao) = 0;
    int i, j, Min,k;
    TADPalavra aux;
    for (i = 0; i < (tam-1); i++ ){
        Min = i;
        for (j = i + 1; j < tam; j++){
            *(conta_comparacao) += 1;
            if (strcmp(lista.Lista[j].palavra.string_aloc, lista.Lista[Min].palavra.string_aloc) < 0){
            Min = j;
            } 
        }
        aux = lista.Lista[Min].palavra;
        lista.Lista[Min].palavra = lista.Lista[i].palavra;
        lista.Lista[i].palavra = aux;
        *(conta_movimentacao) += 1;
    }

    //Parte que printa resultado da ordenacao na tela:
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }

    return 0;
}

//Ordena lista pelo metodo insercao
int Insercao(Tlista lista, int tam, int *conta_movimentacao, int *conta_comparacao){

    *(conta_movimentacao) = 0;
    *(conta_comparacao) = 0;
    int i, j,k;
    TADPalavra aux;
    
    for (i = 1; i < tam; i++){
        aux = lista.Lista[i].palavra;
        j = i - 1;
        *(conta_comparacao) += 1;
        while((j >= 0) && ((strcmp(aux.string_aloc,lista.Lista[j].palavra.string_aloc)) < 0 )){
            lista.Lista[j + 1].palavra = lista.Lista[j].palavra;
            j--;
            *(conta_comparacao) += 1;
            *(conta_movimentacao) += 1;
        }
        lista.Lista[j+1].palavra = aux;
        *(conta_movimentacao) += 1;
    }

    //Parte que printa resultado da ordenacao na tela:
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    return 0;
}

void BubbleSort(Tlista lista, int tam, int *conta_movimentacao, int *conta_comparacao){

    *(conta_movimentacao) = 0; 
    *(conta_comparacao) = 0;
    int i;     
    TADPalavra aux1,aux2;
        int trocou = 1;
        char temp[80]; // colocar constante no lugar

    while (trocou){
       trocou = 0;
        for (int i = 0; i < tam-1; i++){
        aux1 = lista.Lista[i].palavra;   
        aux2 = lista.Lista[i+1].palavra;  
        *(conta_comparacao) += 1;
            if (strcmp(aux1.string_aloc, aux2.string_aloc) > 0){
                /*Realiza a troca*/
                *(conta_movimentacao) +=1;
                lista.Lista[i+1].palavra= aux1;
                *(conta_movimentacao) +=1;
                lista.Lista[i].palavra= aux2;
                trocou = 1; 
            }
        }
    }
    //parte que printa resultado da ordencacao na tela
    for (int i = 0; i < tam; i++)
        printf("%s \n", lista.Lista[i].palavra.string_aloc);
    printf("\n");
}
