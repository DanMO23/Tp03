#include "Ordenacao_simples.h"

void Refaz(int Esq, int Dir, Tlista *lista,int *conta_comparacao,int *conta_movimentacao);
void Constroi(Tlista *lista, int *n,int *conta_comparacao,int *conta_movimentacao);
int Heapsort(Tlista lista, int n, int *conta_movimentacao, int *conta_comparacao);