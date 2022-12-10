#include "../Headers/TADPalavra.h"

/*Cria o espaco de memoria dinamicamente alocado para cada string recebida pela funcao*/
void CriaPalavra(TADPalavra *Palavra_arq, char *string_recebida) {

  int tam_alocado;
  
  tam_alocado = strlen(string_recebida);
  Palavra_arq->string_aloc =
      (char *)malloc(tam_alocado * sizeof(char));

      //Retorna NULL caso haja problemas na criacao do espaco alocado
  if (Palavra_arq->string_aloc == NULL) {
    printf("Problemas na alocacao de memoria\n");
    exit(0);
  }
  PreenchePalavra(Palavra_arq, string_recebida);
  PalavraLinhaVazia(&Palavra_arq->linha);

 
}
//Roda dentro da funcao CriaPalavra e copia a string recebida para o espaço dinamicamente alocado
void PreenchePalavra(TADPalavra *Palavra_arq, char *string) {
  strcpy(Palavra_arq->string_aloc, string);
}

//Retorna a palavra que esta dinamicamente alocada dentro do TAD
 char *RetornaPalavra(TADPalavra *Palavra_arq) {
   
   return Palavra_arq->string_aloc;
 }


//Imprimi a palavra que esta alocada dentro do TAD
void ImprimiPalavra(TADPalavra *Palavra_arq) {
  
  printf("\nPalavra: %s\n", RetornaPalavra(Palavra_arq));
}


/* Recebe como parametro o TADPAlavrra e a linha a qual esta palavra aparece, e aloca a linha dentro de uma lista encadeada */
void InserelinhaPalavra(TADPalavra *palavra, int linha) {
  //A funcao buscaLinhaPalavra verifica se aquela linha especifica ja esta dentro da lista encadeada, caso não haja, a funcao adiciona a nova linha na lista encadeada
  if (buscarLinhaPalavra(palavra, linha) == 1 && linha != 0) {
     //Retorna NULL caso haja problemas na criacao do espaco alocado
    palavra->linha.ult->pProx= (Apontador_LinhaPalavra) malloc(sizeof(TCelula_linha));
    palavra->linha.ult = palavra->linha.ult->pProx;
    palavra->linha.ult->Item.linha_Palavra = linha;
    palavra->linha.ult->pProx= NULL;
    } 
  else {
    return;
  }
}


//Recebe como parametro o TADPalavra e a linha e verifica se aquela linha ja está na lista encadeada
int buscarLinhaPalavra(TADPalavra *palavra, int linha) {
  Apontador_LinhaPalavra pLinha;

  int resultado = 1;

  pLinha = palavra->linha.prim;

  while (pLinha != NULL) {
    if (pLinha->Item.linha_Palavra == linha) {
      resultado = 0;
      return resultado;
    }
    pLinha = pLinha->pProx;
  }
  //Retorna um valor como int que será usado em uma condicional if
  return resultado;
}


//Imprimi a lista encadeada que esta alocada dentro de um TADPalavra
void ImprimiPalavraListaEncadea(TADLinha *Linha) {
  
  Apontador_LinhaPalavra pLinha;

  pLinha = Linha->prim->pProx;
  printf("\nLinhas: ");
  while (pLinha != NULL) {
    printf("|%d", pLinha->Item.linha_Palavra);
    pLinha = pLinha->pProx;
  }
  printf("|\n");
}

//Imprimi tanto a palavra do TADPalavra quanto a lista encadeada que esta alocada dentro dela
void ImprimiPalavra_Linha(TADPalavra *Palavra_arq) {
  printf("\n-----------------------\n");
  ImprimiPalavra(Palavra_arq);
  ImprimiPalavraListaEncadea(&Palavra_arq->linha);
   printf("\n-----------------------\n");

}

//Inicializa uma Linha vazia dentro do TADPalavra
void PalavraLinhaVazia(TADLinha *Linha){

  Linha->prim = (Apontador_LinhaPalavra) malloc(sizeof(TCelula_linha));
  Linha->ult = Linha->prim;
  Linha->ult->pProx = NULL;


}
