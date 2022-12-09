#include "../Headers/Quicksort.h"

void Particao(int Esq, int Dir, int *i, int *j, Tlista *lista){
    TADPalavra pivo, aux;
    *i = Esq; *j = Dir;
    pivo = lista->palavra[(*i + *j)/2]; // obtem o pivo x 
    do{
        while (strcmp(pivo.string_aloc, lista->palavra[*i].string_aloc) > 0) (*i)++;
        while (strcmp(pivo.string_aloc, lista->palavra[*j].string_aloc) < 0) (*j)--;
        if (*i <= *j){
            aux = lista->palavra[*i]; lista->palavra[*i] = lista->palavra[*j]; lista->palavra[*j] = aux;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Tlista *lista){
    int i,j;
    Particao(Esq, Dir, &i, &j, lista);
    if (Esq < j) Ordena(Esq, j, lista);
    if (i < Dir) Ordena(i, Dir, lista);
}

int Quicksort(Tlista lista, int n){
    
    int k;
    Ordena(0, n-1, &lista);
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por quicksort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< n; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
