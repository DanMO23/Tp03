#include "../Headers/Heapsort.h"

void Refaz(int Esq, int Dir, Tlista *lista){
    int j = Esq * 2;
    TADPalavra aux = lista->Lista[Esq].palavra;
    while (j <= Dir){
        if ((j < Dir)&&(strcmp(lista->Lista[j].palavra.string_aloc,lista->Lista[j+1].palavra.string_aloc) < 0)) j++;
        if (strcmp(aux.string_aloc, lista->Lista[j].palavra.string_aloc) >= 0) break;
        lista->Lista[Esq] = lista->Lista[j];
        Esq = j; 
        j = Esq * 2 ;
        }
    lista->Lista[Esq].palavra = aux;
}

void Constroi(Tlista *lista, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 0){
        Esq--;
        Refaz(Esq, *n, lista);
    }
}

int Heapsort(Tlista lista, int n){   
    int Esq, Dir,k;
    TADPalavra aux;
    /*
    Constroi(&lista, &n); //constroi o heap 
    Esq = 0; Dir = (n)-1;
    while (Dir > 0)
    { //ordena o vetor 
        aux = lista.Lista[0].palavra;
        lista.Lista[0].palavra = lista.Lista[Dir].palavra;
        lista.Lista[Dir].palavra = aux;
        Dir--;
        Refaz(Esq, Dir, &lista);
    }
    */
   printf("entrou");
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nLista ordenada por Heapsort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< n; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
