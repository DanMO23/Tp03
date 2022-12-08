#include "../arquivos H/TAD_lista.h"

//Fução cria da início dinamicamente a uma lista encadeada com celula cabeça, todos apontando para nulo
void cria_lista(Tlista *lista)
{
    lista->primeiro = Inicio;
    lista->ultimo = lista->primeiro;
}
//Verifica se a lista esta vazia ou não, retornando um inteiro para a verificação
int leh_vazia(Tlista *lista)
{
    return lista->primeiro == lista->ultimo;
}
//Função irá colocar uma palavra dentro de uma nova celula na lista
int insere_palavra_linha(Tlista *lista, int linha, char *palavra)
{
    if(lista->ultimo == MaxTam)
        return 0;
    int aux; //Verificar se a palavra ja existe ou não;   
    aux = verifica_palavra(lista, palavra);
    if(aux < 0){
        CriaPalavra(&lista->Lista[lista->ultimo].palavra, palavra); //Criará um novo espaço de memória para a palavra caso não exista dentro do dicionario
        PalavraLinhaVazia(&lista->Lista[lista->ultimo].palavra.linha); // Novo espaço na memória para a linha
        InserelinhaPalavra(&lista->Lista[lista->ultimo].palavra, linha); 
        lista->ultimo++;
    }
    else{
        InserelinhaPalavra(&lista->Lista[lista->ultimo].palavra, linha); //Irá preencher novamente um novo espaço para mostrar a linha em que a palavra aparece
        lista->ultimo++;
    }
    return 1;
}

//Função irá remover da lista uma palavra que foi escolhida pelo usuário, tendo como parametro o endereço da lista correta e a palavra em questão
int remove_escolhida(Tlista *lista, char *palavra)
{
    if(leh_vazia(lista)){
        printf("A lista esta vazia\n");
        return 0;
    }
    int i, aux;
    aux = verifica_palavra(lista, palavra); // Retorna a posição da palavra que irá ser removida
    if(aux >= 0){
        for(i = aux; i < lista->ultimo; i++){
            lista->Lista[i] = lista->Lista[i+1];  // Desloca todas as palavras para uma posição a atras no vetor
        }
        lista->ultimo--;
        printf("Palavra removida com sucesso\n");
    }
    else
        printf("Palavra nao existente no dicionario\n");
    return 1;
}

//Função irá remover uma palavra do final de uma lista. A lista da qual será removida será recebida o endereço como parametro
int remove_final(Tlista *lista)
{
    if(leh_vazia(lista)){
        printf("A lista esta vazia\n");
        return 0;
    }
    int i;
    for(i = lista->primeiro; i < lista->ultimo; i++){
        lista->Lista[i] = lista->Lista[i+1]; // Arrasta uma posição pra tras todos os itens
    }
    lista->ultimo--;
    printf("Palavra removida com sucesso\n");
    return 1;
}

/*Função irá verificar se uma palavra existe dentro da lista.
 O grande diferencial dessa é que ela já irá retornar a posição, 
caso a palavra ja exista, de onde ela armazenada no vetor. 
O intuito é fornecer para outras funções o indice e não ter que percorrer 
a lista inteira de novo.*/
int verifica_palavra(Tlista *lista, char *palavra)
{
    if(leh_vazia(lista))
        return -1;
    int i = lista->primeiro;
    while(i < lista->ultimo){
        if(strcmp(lista->Lista[i].palavra.string_aloc, palavra) == 0) // irá procurar se existe a palavra dentro do vetor
            return i;
        i++;
    }
    return -1;
}
//Função retornar o tamanho da lista
int numero_palavra(Tlista *lista)
{
    return lista->ultimo;
}
//Função irá imprimir todos os elementos de uma determinada lista
void imprimi_lista(Tlista *lista)
{
    int i;
    for(i = lista->primeiro; i < lista->ultimo; i++){
        ImprimiPalavra_Linha(&lista->Lista[i].palavra);
    }
}