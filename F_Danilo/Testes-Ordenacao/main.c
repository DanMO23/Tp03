#include "Headers/ShellSort.h"

/*
amostra
pera
jaca
arroz
milhas
carne
jiboia
zebra
shit
knee
*/

/* Um valor menor que zero significa que string1 é menor que string2. Um valor zero significa que ambas as strings são iguais. Um valor maior que zero significa que string1 é maior que string2.*/

int main(){
    Tlista lista;
    int i,k;
    int tam = 10;
    for (i = 0; i< tam; i++){
        scanf("%s",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    //funcoes :
    
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Lista normal \n");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    for (i = 0; i< tam; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    printf("=-=-=-=-=-=-=-=-=-=\n");

    BubbleSort(lista, tam);
    Insercao(lista, tam);
    Selecao(lista,tam);

    ShellSort(lista, tam);
    Quicksort(lista,tam);
    Heapsort(lista,tam);
    
    return 0;
}
