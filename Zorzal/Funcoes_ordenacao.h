/*
Feito pra trazer os itens do tad dicionario da forma correta
*/
#include <string.h>
#include <stdio.h>
#include "../arquivos H/TAD_lista.h"
#include "../arquivos H/TAD_dicionario.h"
#include "../arquivos H/TADPalavra.h"

int selecao(Tlista lista, int tam);
int insercao(Tlista lista, int tam);
void Particao(int Esq, int Dir, int *i, int *j, Tlista *A);
void Ordena(int Esq, int Dir, Tlista *A);
void Quick(Tlista* A, int n);
int QuickSort(Tlista lista, int tam);
void Refaz(int Esq, int Dir, Tlista *lista);
void Constroi(Tlista *lista, int *n);
void Heapsort(Tlista *lista, int *n);
int Chama_heapsort(Tlista lista_aux, int n);
