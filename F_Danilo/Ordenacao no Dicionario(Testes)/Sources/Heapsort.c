#include "../Headers/Heapsort.h"

//funcao responsavel por refazer o heap
void Refaz(int Esq, int Dir, Tlista *lista,int *conta_comparacao,int *conta_movimentacao){
    int j = Esq * 2;
    TADPalavra aux = lista->Lista[Esq].palavra;
    *(conta_comparacao) += 1;
    while (j <= Dir){
        *(conta_comparacao) += 1;
        *(conta_comparacao) += 1;
        if ((j < Dir)&&(strcmp(lista->Lista[j].palavra.string_aloc,lista->Lista[j+1].palavra.string_aloc) < 0)){
             j++;
        }
        *(conta_comparacao) += 1;
    
        if (strcmp(aux.string_aloc, lista->Lista[j].palavra.string_aloc) >= 0){
            break;
        }
        //conta_comparacao++;
        lista->Lista[Esq].palavra = lista->Lista[j].palavra;
        *(conta_movimentacao) += 1;
        Esq = j; 
        j = Esq * 2 ;
        }
    lista->Lista[Esq].palavra = aux;
    *(conta_movimentacao) += 1;
}

//funcao responsavel por construir o heap
void Constroi(Tlista *lista, int *n,int *conta_comparacao,int *conta_movimentacao){
    int Esq;
    Esq = *n / 2 + 1;
    *(conta_comparacao) += 1;
    while (Esq > 1){
        *(conta_comparacao) += 1;
        Esq--;
        Refaz(Esq, *n, lista, conta_comparacao, conta_movimentacao);
    }
}

//Ordena uma lista usando heapsort. Como o metodo heap parte do 1, retorna 1 para uma lista >= maxtam-1
int Heapsort(Tlista lista_aux, int n, int *conta_movimentacao, int *conta_comparacao){   
    *(conta_movimentacao) = 0;
    *(conta_comparacao) = 0;
    int Esq, Dir,k;
    Tlista lista;
    if (numero_palavra(&lista_aux) == MaxTam-1){
        printf("Lista muito grande\n");
        return 1;
    }
    for (k = 0; k < MaxTam-1; k++){
        lista.Lista[k+1].palavra = lista_aux.Lista[k].palavra;
    }
    TADPalavra aux;
    Constroi(&lista, &n,conta_comparacao,conta_movimentacao); //constroi o heap 
    Esq = 1; Dir = (n);
    while (Dir > 1)
    { //ordena o vetor 
        aux = lista.Lista[1].palavra;
        lista.Lista[1].palavra = lista.Lista[Dir].palavra;
        lista.Lista[Dir].palavra = aux;
        Dir--;
        Refaz(Esq, Dir, &lista,conta_comparacao,conta_movimentacao);
    }
    
    //printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nLista ordenada por Heapsort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 1; k<= n; k++){
        printf("%s\n",lista.Lista[k].palavra.string_aloc);
    }
    return 0;
}
