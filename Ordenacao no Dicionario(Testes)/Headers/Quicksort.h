#include "TAD_lista.h"

void Particao(int Esq, int Dir, int *i, int *j, Tlista *lista,int *conta_comparacao, int *conta_movimentacao);
void Ordena(int Esq, int Dir, Tlista *lista,int *conta_comparacao, int *conta_movimentacao);
int Quicksort(Tlista lista, int n, int *conta_movimentacao, int *conta_comparacao);
