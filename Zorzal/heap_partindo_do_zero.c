
/*
amostra
pera
jaca
arroz
milhas
carne
jiboia
zebra
shit
knee
*/
#include <stdio.h>
#include <string.h>


#define N 30
//tad provisorios para teste
typedef struct {
  char string_aloc[20]; 
  int linha;  
} TADPalavra;

typedef struct
{   
    TADPalavra palavra[N];
    int tam;
} Tlista;

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

// -- Entra aqui a função Refaz -- 
// -- Entra aqui a função Constroi -- 
void Heapsort(Tlista *lista, int *n)
{ int Esq, Dir;
    TADPalavra aux;
    Constroi(lista, n); //constroi o heap 
    Esq = 0; Dir = *(n)-1;
    while (Dir > 0)
    { //ordena o vetor 
        aux = lista->palavra[0];
        lista->palavra[0] = lista->palavra[Dir];
        lista->palavra[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, lista);
    }
}
int Chama_heap(Tlista lista_aux, int n){
    Tlista lista;
    int i= 0,k;
    lista = lista_aux;
    Heapsort(&lista,&n);
    printf("ordenado\n");
    for ( i = 0; i < n; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
    }
}

int main(){
    Tlista lista;
    int i,k;
    int tam = 10;
    for (i = 0; i< tam; i++){
        scanf("%s",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    //funcoes :
    //selecao(lista, tam);
    //insercao(lista, tam);
    //QuickSort(lista, tam);
    Chama_heap(lista,tam);
    
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Lista normal \n");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    for (i = 0; i< tam; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    printf("=-=-=-=-=-=-=-=-=-=\n");
    return 0;
}
