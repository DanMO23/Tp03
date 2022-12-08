#include "TADPalavra.h"
#define MaxTam 10
#define Inicio 0

typedef struct Celula
{
    TADPalavra palavra;
} Tcelula_lista;

typedef int Apontador;
typedef struct
{
    Tcelula_lista Lista[MaxTam];
    Apontador primeiro, ultimo;
} Tlista;

void cria_lista(Tlista *lista);
int leh_vazia(Tlista *lista);
int insere_palavra_linha(Tlista *lista, int linha, char *palavra);
int remove_escolhida(Tlista *lista, char *palavra);
int remove_final(Tlista *lista);
int verifica_palavra(Tlista *lista, char *palavra);
int numero_palavra(Tlista *lista);
void imprimi_lista(Tlista *lista);

