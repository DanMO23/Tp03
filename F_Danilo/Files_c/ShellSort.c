#include "../Files_h/ShellSort.h"

void ShellSort(Tlista lista, int tam){
   
    
    int i,j;
    int h =1;
    TADPalavra aux;
    
    do h = h*3 +1;while(h<tam);

        do
    {
        h = h/3;
        for( i = h ; i < tam ; i++ )
        {
            aux = lista.palavra[i]; j = i;
            while (strcmp(lista.palavra[j - h].string_aloc, aux.string_aloc) > 0)
            {
              lista.palavra[j] = lista.palavra[j - h]; 
              j -= h;
              if (j < h) break;
            }
        lista.palavra[j] = aux;
    }
    } while (h != 1);
    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por shellsort\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (i = 0; i< tam; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
    }
    
    
}