#include "../Files_h/Heapsort.h"

void Refaz(int Esq, int Dir, Tlista *lista,int *conta_comparacao,int *conta_movimentacao){
    int j = Esq * 2;
    TADPalavra aux = lista->palavra[Esq];
    *(conta_comparacao) += 1;
    while (j <= Dir){
        *(conta_comparacao) += 1;
        *(conta_comparacao) += 1;
        if ((j < Dir)&&(strcmp(lista->palavra[j].string_aloc,lista->palavra[j+1].string_aloc) < 0)){
             j++;
        }
        *(conta_comparacao) += 1;
        if (strcmp(aux.string_aloc, lista->palavra[j].string_aloc) >= 0){
            break;
        }
        //conta_comparacao++;
        lista->palavra[Esq] = lista->palavra[j];
        *(conta_movimentacao) += 1;
        Esq = j; 
        j = Esq * 2 ;
        }
    lista->palavra[Esq] = aux;
    *(conta_movimentacao) += 1;
}

void Constroi(Tlista *lista, int *n,int *conta_comparacao,int *conta_movimentacao){
    int Esq;
    Esq = *n / 2 + 1;
    *(conta_comparacao) += 1;
    while (Esq > 0){
        *(conta_comparacao) += 1;
        Esq--;
        Refaz(Esq, *n, lista, conta_comparacao, conta_movimentacao);
    }
}

int Heapsort(Tlista lista, int n){   
    clock_t t;
    t = clock();
    int conta_movimentacao = 0, conta_comparacao = 0;
    int Esq, Dir,k;
    TADPalavra aux;
    Constroi(&lista, &n,&conta_comparacao,&conta_movimentacao); //constroi o heap 
    Esq = 0; Dir = (n)-1;
    while (Dir > 0)
    { //ordena o vetor 
        aux = lista.palavra[0];
        lista.palavra[0] = lista.palavra[Dir];
        lista.palavra[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, &lista,&conta_comparacao,&conta_movimentacao);
    }
    
    t = clock() - t;
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nLista ordenada por Heapsort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
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
