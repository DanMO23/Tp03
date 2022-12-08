#include <string.h>
#include <stdio.h>
#include <time.h>

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
