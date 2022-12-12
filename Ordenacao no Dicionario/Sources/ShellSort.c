#include "../Headers/ShellSort.h"

void ShellSort(Tlista lista, int tam, int *conta_movimentacao, int *conta_comparacao){
    
    int i,j;
    int h =1;
    TADPalavra aux;
    *(conta_movimentacao) = 0;
    *(conta_comparacao) = 0;
    do h = h*3 +1;while(h<tam);

        do
    {
        h = h/3;
        for( i = h ; i < tam ; i++ )
        {
            aux = lista.Lista[i].palavra; 
            *(conta_movimentacao)+= 1;
            j = i;
                *(conta_comparacao)+= 1;
            while (strcmp(lista.Lista[j - h].palavra.string_aloc, aux.string_aloc) > 0)
            {

                lista.Lista[j].palavra = lista.Lista[j - h].palavra; 
                *(conta_movimentacao)+= 1;
                j -= h;
                if (j < h) break;
            }
        lista.Lista[j].palavra = aux;
        *(conta_movimentacao)+= 1;
    }
    } while (h != 1);

    //Parte que printa resultado da ordenacao na tela:
    for (i = 0; i< tam; i++){
        printf("%s\n",lista.Lista[i].palavra.string_aloc);
    }
    

}
