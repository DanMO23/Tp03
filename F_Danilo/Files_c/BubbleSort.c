#include "../Files_h/BubbleSort.h"

void BubbleSort(Tlista lista, int tam){
    int i;     
    TADPalavra aux1,aux2;
        int trocou = 1;
        char temp[80]; // colocar constante no lugar

    while (trocou){
       trocou = 0;
        for (int i = 0; i < tam-1; i++){
        aux1 = lista.palavra[i];   
        aux2 = lista.palavra[i+1];   
            if (strcmp(aux1.string_aloc, aux2.string_aloc) > 0){
                /*Realiza a troca*/

                lista.palavra[i+1]= aux1;
               lista.palavra[i]= aux2;
                trocou = 1; 
            }
        }
    }
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Sequencia reordenada por Bubble:\n");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < tam; i++)
        printf("%s \n", lista.palavra[i].string_aloc);
    printf("\n");
}