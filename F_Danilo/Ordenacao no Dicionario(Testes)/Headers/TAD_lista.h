#include "TADPalavra.h"

typedef struct Celula *Apontador_celula_lista;
typedef struct Celula
{
    TADPalavra palavra;
    struct Celula *proximo; // Apontador_celula_lista para o prox
} Tcelula_lista;

typedef struct
{
    Apontador_celula_lista primeiro;
    Apontador_celula_lista ultimo;
    int tam;
} Tlista;

void cria_lista(Tlista *lista);
int leh_vazia(Tlista *lista);
void insere_palavra_linha(Tlista *lista, int linha, char *palavra);
void remove_escolhida(Tlista *lista, char *palavra);
void remove_final(Tlista *lista);
Apontador_celula_lista verifica_palavra(Tlista *lista, char *palavra);
int numero_palavra(Tlista *lista);
void imprimi_lista(Tlista *lista);

