
//#include "../arquivos H/TAD_lista.h"
//#include "../arquivos H/TAD_dicionario.h"
//#include "../arquivos H/TADPalavra.h"

//=======================================
//Lembrar de remover :
#include "struct_aux.h"

void Particao(int Esq, int Dir, int *i, int *j, Tlista *lista,int *conta_comparacao, int *conta_movimentacao);
void Ordena(int Esq, int Dir, Tlista *lista,int *conta_comparacao, int *conta_movimentacao);
int Quicksort(Tlista lista, int n);
