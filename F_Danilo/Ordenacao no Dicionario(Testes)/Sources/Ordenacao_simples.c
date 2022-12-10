#include "../Headers/Ordenacao_simples.h"
/*
Para realizar as comparacoes usa-se a funcao strcmp da biblioteca <string.h>. Se ela retornar:
Um valor menor que zero: a primeira string é menor que a segunda
Um valor maior que zero: a primeira string é maior que a segunda
Retorna 0: as duas strings sao iguais
*/

//Ordena lista pelo metodo selecao
int Selecao(Tlista lista, int tam,int *conta_movimentacao, int *conta_comparacao){
    
    clock_t t;
    t = clock();
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
    
    t = clock() - t;
    //Parte que printa resultado da ordenacao na tela:
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por selecao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    //printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    //printf("Numero de Comparacoes: %d\n",conta_comparacao);
    //printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    return 0;
}

//Ordena lista pelo metodo insercao
int Insercao(Tlista lista, int tam, int *conta_movimentacao, int *conta_comparacao){

    clock_t t;
    t = clock();
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
    t = clock() - t;

    //Parte que printa resultado da ordenacao na tela:
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por insercao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    //printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    //printf("Numero de Comparacoes: %d\n",conta_comparacao);
    //printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
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
    //printf("=-=-=-=-=-=-=-=-=-=\n");
    //printf("Sequencia reordenada por Bubble:\n");
    //printf("=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < tam; i++)
        printf("%s \n", lista.Lista[i].palavra.string_aloc);
    printf("\n");
}
