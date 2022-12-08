#include "../Headers/Heapsort.h"

void Refaz(int Esq, int Dir, Tlista *lista){
    int j = Esq * 2;
    TADPalavra aux = lista->palavra[Esq];
    while (j <= Dir){
        if ((j < Dir)&&(strcmp(lista->palavra[j].string_aloc,lista->palavra[j+1].string_aloc) < 0)) j++;
        if (strcmp(aux.string_aloc, lista->palavra[j].string_aloc) >= 0) break;
        lista->palavra[Esq] = lista->palavra[j];
        Esq = j; 
        j = Esq * 2 ;
        }
    lista->palavra[Esq] = aux;
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
    Constroi(&lista, &n); //constroi o heap 
    Esq = 0; Dir = (n)-1;
    while (Dir > 0)
    { //ordena o vetor 
        aux = lista.palavra[0];
        lista.palavra[0] = lista.palavra[Dir];
        lista.palavra[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, &lista);
    }
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nLista ordenada por Heapsort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< n; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
