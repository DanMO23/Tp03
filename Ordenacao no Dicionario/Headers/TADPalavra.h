#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*O TADItem, Tcelula_linha e o TADLinha fazem parte da lista encadeada
 que aloca dinamicamente as linhas que uma palavra pertence, formando uma lista encadeada*/
typedef struct CelulaLin *Apontador_LinhaPalavra;

typedef struct {
  int linha_Palavra;

} TADItem;

typedef struct CelulaLin {
  TADItem Item;
  struct CelulaLin *pProx;

} TCelula_linha;

typedef struct {
  Apontador_LinhaPalavra prim;
  Apontador_LinhaPalavra ult;
  
} TADLinha;

typedef struct {
  char *string_aloc; 
  TADLinha linha;  
} TADPalavra;
//Funcoes relativas a Palavra
void CriaPalavra(TADPalavra *Palavra_arq, char *string_recebida);
void PreenchePalavra(TADPalavra *Palavra_arq, char *string);
char* RetornaPalavra(TADPalavra *Palavra_arq);
void ImprimiPalavra(TADPalavra *Palavra_arq);
void ImprimiPalavra_Linha(TADPalavra *Palavra_arq);
//Funcoes Relativas as Linhas que a Palavra ocorre
int buscarLinhaPalavra(TADPalavra *palavra, int linha);
void InserelinhaPalavra(TADPalavra *palavra, int linha);
void PalavraLinhaVazia(TADLinha *Linha);
void ImprimiListaEncadea(TADLinha *Linha);