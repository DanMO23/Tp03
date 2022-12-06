#include "../Files_h/Ordenacao_simples.h"
/*
Feito pra trazer os itens do tad dicionario da forma correta
*/
/*
Para realizar as comparacoes usa-se a funcao strcmp da biblioteca <string.h>. Se ela retornar:
Um valor menor que zero: a primeira string é menor que a segunda
Um valor maior que zero: a primeira string é maior que a segunda
Retorna 0: as duas strings sao iguais
*/

/*
  clock_t t;
  t = clock();
  t = clock() - t;
  printf("\nPara Entradas = %i\nTempo de execucao: %lfms\n",N, ((double)t)/((CLOCKS_PER_SEC/1000)));
  */

int Selecao(Tlista lista, int tam){
    
    clock_t t;
    t = clock();
    int conta_movimentacao = 0, conta_comparacao = 0;
    int i, j, Min,k;
    TADPalavra aux;
    for (i = 0; i < (tam-1); i++ ){
        Min = i;
        for (j = i + 1; j < tam; j++){
            conta_comparacao++;
            if (strcmp(lista.palavra[j].string_aloc, lista.palavra[Min].string_aloc) < 0){
            Min = j;
            } 
        }
        aux = lista.palavra[Min];
        lista.palavra[Min] = lista.palavra[i];
        lista.palavra[i] = aux;
        conta_movimentacao++;
    }
    
    t = clock() - t;
    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por selecao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    printf("Numero de Comparacoes: %d\n",conta_comparacao);
    printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    return 0;

}

int Insercao(Tlista lista, int tam){
    clock_t t;
    t = clock();
    int conta_movimentacao = 0, conta_comparacao = 0;
    int i, j,k;
    TADPalavra aux;
    
    for (i = 1; i < tam; i++){
        aux = lista.palavra[i];
        j = i - 1;
        conta_comparacao++;
        while((j >= 0) && ((strcmp(aux.string_aloc,lista.palavra[j].string_aloc)) < 0 )){
            lista.palavra[j + 1] = lista.palavra[j];
            j--;
            conta_comparacao++;
            conta_movimentacao++;
        }
        lista.palavra[j+1] = aux;
        conta_movimentacao++;
    }
    t = clock() - t;

    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por insercao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    printf("Numero de Comparacoes: %d\n",conta_comparacao);
    printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}