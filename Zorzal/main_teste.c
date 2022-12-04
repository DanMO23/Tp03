#include "funcoes_zorzal.h"
/*
#include "../arquivos H/TAD_lista.h"
#include "../arquivos H/TADPalavra.h"
*/

/* Um valor menor que zero significa que string1 é menor que string2. Um valor zero significa que ambas as strings são iguais. Um valor maior que zero significa que string1 é maior que string2.*/

int main(){
    Tlista lista;
    int i,k;
    for (i = 0; i< N; i++){
        scanf("%s",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    //funcoes :
    //selecao(lista, N);
    //insercao(lista, N);
    //QuickSort(lista,N);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Lista normal \n");
    printf("=-=-=-=-=-=-=-=-=-=\n");

 
    for (i = 0; i< N; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
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
carambola
dorgas
*/
