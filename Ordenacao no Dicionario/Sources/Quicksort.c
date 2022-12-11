#include "../Headers/Quicksort.h"

void Particao(int Esq, int Dir, int *i, int *j, Tlista *lista, int *conta_comparacao, int *conta_movimentacao){
    TADPalavra pivo, aux;
    *i = Esq; *j = Dir;
    pivo = lista->Lista[(*i + *j)/2].palavra; // obtem o pivo x 
    do{
        *(conta_comparacao) += 1;
        while (strcmp(pivo.string_aloc, lista->Lista[*i].palavra.string_aloc) > 0){
            (*i)++;
        } 
        *(conta_comparacao) += 1;
        while (strcmp(pivo.string_aloc, lista->Lista[*j].palavra.string_aloc) < 0){
            (*j)--;
        }
        if (*i <= *j){
            *(conta_comparacao) += 1;
            aux = lista->Lista[*i].palavra; 
            lista->Lista[*i].palavra =  lista->Lista[*j].palavra;
            lista->Lista[*j].palavra = aux;
            *(conta_movimentacao) += 3;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Tlista *lista,int *conta_comparacao, int *conta_movimentacao){
    int i,j;
    Particao(Esq, Dir, &i, &j, lista,conta_comparacao,conta_movimentacao);
    if (Esq < j) Ordena(Esq, j, lista,conta_comparacao,conta_movimentacao);
    if (i < Dir) Ordena(i, Dir, lista,conta_comparacao,conta_movimentacao);
}

//Ordena lista via quicksort. 
int Quicksort(Tlista lista, int n, int *conta_movimentacao, int *conta_comparacao){

    *(conta_comparacao) = 0;
    *(conta_movimentacao) = 0;
    int k;

    Ordena(0, n-1, &lista,conta_comparacao,conta_movimentacao);
    
    //Parte que printa resultado da ordenacao na tela:
    for (k = 0; k< n; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    return 0;
}
