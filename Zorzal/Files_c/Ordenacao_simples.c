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

int Selecao(Tlista lista, int tam){
    
    int i, j, Min,k;
    TADPalavra aux;
    
    for (i = 0; i < (tam-1); i++ ){
        Min = i;
        for (j = i + 1; j < tam; j++)
            if (strcmp(lista.palavra[j].string_aloc, lista.palavra[Min].string_aloc) < 0){
            Min = j;
            } 
        aux = lista.palavra[Min];
        lista.palavra[Min] = lista.palavra[i];
        lista.palavra[i] = aux;
    }
    
    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por selecao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;

}

int Insercao(Tlista lista, int tam){
  
    int i, j,k;
    TADPalavra aux;
    
    for (i = 1; i < tam; i++){
        aux = lista.palavra[i];
        j = i - 1;
        while((j >= 0) && ((strcmp(aux.string_aloc,lista.palavra[j].string_aloc)) < 0 )){
            lista.palavra[j + 1] = lista.palavra[j];
            j--;
        }
        lista.palavra[j+1] = aux;
    }

    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por insercao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}