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
int quicksort(Tlista lista, int tam);
int heapsort(Tlista lista, int tam);
