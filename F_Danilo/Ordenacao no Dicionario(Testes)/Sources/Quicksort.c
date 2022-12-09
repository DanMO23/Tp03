#include "../Headers/Quicksort.h"

void Particao(int Esq, int Dir, int *i, int *j, Tlista *lista){
    TADPalavra pivo, aux;
    *i = Esq; *j = Dir;
    pivo = lista->Lista[(*i + *j)/2].palavra; // obtem o pivo x 
    do{
        while (strcmp(pivo.string_aloc, lista->Lista[*i].palavra.string_aloc) > 0) (*i)++;
        while (strcmp(pivo.string_aloc, lista->Lista[*j].palavra.string_aloc) < 0) (*j)--;
        if (*i <= *j){
            aux = lista->Lista[*i].palavra; lista->Lista[*i].palavra = lista->Lista[*j].palavra; lista->Lista[*j].palavra = aux;
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
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
