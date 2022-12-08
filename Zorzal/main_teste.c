#include "./Files_h/Heapsort.h"
//#include "./Files_h/Ordenacao_simples.h"
//#include "./Files_h/Quicksort.h"

//gcc .\main_teste.c .\Files_h\Heapsort.h .\Files_c\Heapsort.c .\Files_c\Ordenacao_simples.c .\Files_c\Quicksort.c .\Files_h\Ordenacao_simples.h .\Files_h\Quicksort.h -o run_final   
//gcc .\main_teste.c .\Files_c\Heapsort.c .\Files_h\Heapsort.h -o .\run_final.exe
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
    //Selecao(lista, tam);
    //Insercao(lista, tam);
    //Quicksort(lista, tam);
    //Heapsort(lista,tam);
    
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
