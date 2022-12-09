#include "TAD_lista.h"

//lembrar de modificar o include:


typedef struct CelulaDicionario* Apontador_Celula_Dicionario; //Ponteiro pra TCelula
//Apontador_Celula_Lista

typedef struct CelulaDicionario {
    char letra_lista; //Mostra a letra que a lista atual comporta;
    Tlista lista; //conferir *
    struct CelulaDicionario* Prox_celula_lista; // Apontador pProx; (prÃ³ximo item) 
} TCelulaDicionario;

typedef struct {
    Apontador_Celula_Dicionario pPrimeira_Lista;
    Apontador_Celula_Dicionario pUltima_Lista;
} TDicionario;

int Faz_Dicionario_Vazio(TDicionario* pDicionario);
int Imprime_Lista_Letra_Especifica(TDicionario* pDicionario, char letra);
int Imprime_Dicionario(TDicionario* pDicionario);
int Dicionario_e_vazio(TDicionario* pDicionario);
int Constroi_Dicionario (TDicionario* pDicionario, char* nome_arquivo_txt);
int Encadeia_Celula_Dicionario(TDicionario* pDicionario, char* string, char letra, int linha);
int Remove_ultima_palavra_lista(TDicionario* pDicionario, char letra_lista);
int Remove_palavra_especifica(TDicionario* pDicionario, char* string);
int Remove_celula_dicionario(TDicionario* pDicionario);
int Tamanho_lista_especifica(TDicionario* pDicionario, char letra_lista);
int Tamanho_dicionario(TDicionario* pDicionario);
int Ordena_dicionario(TDicionario* pDicionario, int operacao);
int Ordenada_lista_especifica(TDicionario *pDicionario, int operacao, char letra_da_lista);
