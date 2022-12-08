#include "../Files_h/BubbleSort.h"

void BubbleSort(Tlista lista, int tam){
    clock_t t;
    t = clock();
    int conta_movimentacao = 0, conta_comparacao = 0;
    int i;     
    TADPalavra aux1,aux2;
        int trocou = 1;
        char temp[80]; // colocar constante no lugar

    while (trocou){
       trocou = 0;
        for (int i = 0; i < tam-1; i++){
        aux1 = lista.palavra[i];   
        aux2 = lista.palavra[i+1];  
        conta_comparacao++;
            if (strcmp(aux1.string_aloc, aux2.string_aloc) > 0){
                /*Realiza a troca*/
                 conta_movimentacao++;
                lista.palavra[i+1]= aux1;
                conta_movimentacao++;
               lista.palavra[i]= aux2;
                trocou = 1; 
            }
        }
    }
    t = clock() - t;
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Sequencia reordenada por Bubble:\n");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < tam; i++)
        printf("%s \n", lista.palavra[i].string_aloc);
    printf("\n");

      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    printf("Numero de Comparacoes: %d\n",conta_comparacao);
    printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
}