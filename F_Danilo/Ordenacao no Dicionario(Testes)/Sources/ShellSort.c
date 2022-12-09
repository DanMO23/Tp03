#include "../Headers/ShellSort.h"

void ShellSort(Tlista lista, int tam){
   clock_t t;
    t = clock();
    
    int i,j;
    int h =1;
    TADPalavra aux;
    int conta_movimentacao = 0, conta_comparacao = 0;
    do h = h*3 +1;while(h<tam);

        do
    {
        h = h/3;
        for( i = h ; i < tam ; i++ )
        {
            aux = lista.Lista[i].palavra; j = i;
            while (strcmp(lista.Lista[j - h].palavra.string_aloc, aux.string_aloc) > 0)
            {

                conta_comparacao++;
              lista.Lista[j].palavra = lista.Lista[j - h].palavra; 
               
              j -= h;
              if (j < h) break;
            }
        lista.Lista[j].palavra = aux;
        conta_movimentacao++;
    }
    } while (h != 1);

    t = clock() - t;
    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por shellsort\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (i = 0; i< tam; i++){
        printf("%s\n",lista.Lista[i].palavra.string_aloc);
    }
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    printf("Numero de Comparacoes: %d\n",conta_comparacao);
    printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

}
