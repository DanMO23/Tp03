#include "funcoes_zorzal.h"
/*
#include "../arquivos H/TAD_lista.h"
#include "../arquivos H/TADPalavra.h"
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
    selecao(lista, tam);
    insercao(lista, tam);
    QuickSort(lista, tam);
    Chama_heapsort(lista,tam);
    
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Lista normal \n");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    for (i = 0; i< tam; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    printf("=-=-=-=-=-=-=-=-=-=\n");
    return 0;
}

/*
abacate
pera
flor
jiboia
ameba
coxinha
pao
caximbo
caramba
dorgas
*/
