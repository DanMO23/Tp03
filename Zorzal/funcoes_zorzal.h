/*
#include "../arquivos H/TADPalavra.h"
#include "../arquivos H/TAD_lista.h"
*/
#include <stdio.h>
#include <string.h>

#define N 10
//tad provisorios para teste
typedef struct {
  char string_aloc[10]; 
  int linha;  
} TADPalavra;

typedef struct
{   
    TADPalavra palavra[N];
    int tam;
} Tlista;

/* Implementar seleção, inserção, quicksort, heapsort*/

int selecao(Tlista lista, int tam);
int insercao(Tlista lista, int tam);
int heapsort(Tlista lista, int tam);
void Ordena(int Esq, int Dir, Tlista *A);
int QuickSort(Tlista A, int n);
void Quick(Tlista *lista, int tam);
void Particao(int Esq, int Dir, int *i, int *j, Tlista *A);