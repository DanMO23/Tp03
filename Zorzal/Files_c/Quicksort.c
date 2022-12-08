#include "../Files_h/Quicksort.h"

void Particao(int Esq, int Dir, int *i, int *j, Tlista *lista, int *conta_comparacao, int *conta_movimentacao){
    TADPalavra pivo, aux;
    *i = Esq; *j = Dir;
    pivo = lista->palavra[(*i + *j)/2]; // obtem o pivo x 
    do{
        *(conta_comparacao) += 1;
        while (strcmp(pivo.string_aloc, lista->palavra[*i].string_aloc) > 0){
            *(conta_comparacao) += 1;
            (*i)++;
        } 
        while (strcmp(pivo.string_aloc, lista->palavra[*j].string_aloc) < 0){
            (*j)--;
            *(conta_comparacao) += 1;
        }
        if (*i <= *j){
            *(conta_comparacao) += 1;
            aux = lista->palavra[*i]; 
            lista->palavra[*i] = lista->palavra[*j]; 
            lista->palavra[*j] = aux;
            *(conta_movimentacao) += 1;
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

int Quicksort(Tlista lista, int n){
    clock_t t;
    t = clock();
    int conta_movimentacao = 0, conta_comparacao = 0;
    int k;

    Ordena(0, n-1, &lista,&conta_comparacao,&conta_movimentacao);
    
    t = clock() - t;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por quicksort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< n; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("Numero de Movimentacoes: %d\n",conta_movimentacao);
    printf("Numero de Comparacoes: %d\n",conta_comparacao);
    printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
