#include "funcoes_zorzal.h"

/* Um valor menor que zero significa que string1 é menor que string2. Um valor zero significa que ambas as strings são iguais. Um valor maior que zero significa que string1 é maior que string2.*/

/*  algoritmo seleçao
int i, j, Min;
    Titem aux;
    for (i = 0; i < N - 1; i++){ 
        Min = i;
        for (j = i + 1 ; j < N; j++)
            if ( lista[j].num < lista[Min].num) Min = j;
        aux = lista[Min];
        lista[Min] = lista[i];
        lista[i] = aux;
    }
    printf("\n");*/

int selecao(Tlista lista, int tam){
    int i, j, Min,k;
    TADPalavra aux;
    for (i = 0; i < (tam-1); i++ ){
        Min = i;
        for (j = i + 1; j < tam; j++)
            if (strcmp(lista.palavra[j].string_aloc, lista.palavra[Min].string_aloc) < 0){
            Min = j;
            } 
        strcpy(aux.string_aloc,lista.palavra[Min].string_aloc);
        strcpy(lista.palavra[Min].string_aloc, lista.palavra[i].string_aloc);
        strcpy(lista.palavra[i].string_aloc,aux.string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    for (k = 0; k< tam-1; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;

}
int insercao(Tlista lista, int tam);
/*   int i, j;
    Titem aux;
    for (i = 1; i < N; i++)    {
        aux = lista[i];
        j = i-1;
        while((j>=0) && (aux.num < lista[j].num)){
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = aux;
    }*/
int quicksort(Tlista lista, int tam);
int heapsort(Tlista lista, int tam);
