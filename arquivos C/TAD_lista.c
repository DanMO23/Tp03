#include "../arquivos H/TAD_lista.h"

//Fução cria da início dinamicamente a uma lista encadeada com celula cabeça, todos apontando para nulo
void cria_lista(Tlista *lista)
{
    lista->primeiro = (Apontador_celula_lista)malloc(sizeof(Tcelula_lista));
    if (lista->primeiro)
    {
        lista->ultimo = lista->primeiro;
        lista->ultimo->proximo = NULL;
        lista->tam = 0;
    }
}
//Verifica se a lista esta vazia ou não, retornando um inteiro para a verificação
int leh_vazia(Tlista *lista)
{
    return lista->primeiro == lista->ultimo;
}
//Função irá colocar uma palavra dentro de uma nova celula na lista
void insere_palavra_linha(Tlista *lista, int linha, char *palavra)
{
    Apontador_celula_lista aux;
    aux = verifica_palavra(lista, palavra);

    if(aux == NULL){
        lista->ultimo->proximo = (Apontador_celula_lista)malloc(sizeof(Tcelula_lista));
        if (lista->ultimo->proximo)
        {
            lista->ultimo = lista->ultimo->proximo;
            lista->ultimo->proximo = NULL;
            lista->tam++;
            CriaPalavra(&lista->ultimo->palavra, palavra); //Irá dimensionar o tamanho correto da palavra e preencher o item da palavra reservado
            PalavraLinhaVazia(&lista->ultimo->palavra.linha); //Irá dar inicio a lista encadeada para as linhas em que a palavra aparece, apontando para nulo
            InserelinhaPalavra(&lista->ultimo->palavra, linha); //Irá inserir o valor da linha em que ela ocorre a primeira vez
           
        }
        else
            exit(1);
    }
    else
        InserelinhaPalavra(&aux->palavra, linha); //Irá preencher novamente um novo espaço para mostrar a linha em que a palavra aparece
}

//Função irá remover da lista uma palavra que foi escolhida pelo usuário, tendo como parametro o endereço da lista correta e a palavra em questão
void remove_escolhida(Tlista *lista, char *palavra)
{
    Apontador_celula_lista aux, remove;
        if (leh_vazia(lista))
            return;
        aux = lista->primeiro;
        if(verifica_palavra(lista, palavra) != NULL){
            while (aux->proximo && strcmp(aux->proximo->palavra.string_aloc, palavra) != 0)
                { 
                    aux = aux->proximo;
                }
            remove = aux->proximo;
            aux->proximo = remove->proximo;
            free(remove);
            lista->tam--;
            if(aux->proximo == NULL){
                lista->ultimo = aux;
            }
            printf("Palavra removida com sucesso\n");
            }
            else{
                printf("Palavra nao existente no dicionario\n");
            }
}

//Função irá remover uma palavra do final de uma lista. A lista da qual será removida será recebida o endereço como parametro
void remove_final(Tlista *lista)
{
    Apontador_celula_lista aux, penultimo;
   
    aux = lista->primeiro->proximo;
    penultimo = lista->primeiro;
    if (leh_vazia(lista)){
        printf("A lista esta vazia\n");
        
        return ;
    }
        while(aux->proximo != NULL){
            aux = aux->proximo;
            penultimo = penultimo->proximo;
        }
        penultimo->proximo = aux->proximo;
        lista->ultimo = penultimo;
        lista->tam--;
        free(aux);
    
    printf("Palavra removida com sucesso\n");
}

/*Função irá verificar se uma palavra existe dentro da lista.
 O grande diferencial dessa é que ela já irá retornar o endereço, 
caso a palavra ja exista, de onde ela esta alocada na memória. 
O intuito é fornecer para outras funções o endereço e não ter que percorrer 
a lista inteira de novo.*/
Apontador_celula_lista verifica_palavra(Tlista *lista, char *palavra)
{
    Apontador_celula_lista aux;
    if (leh_vazia(lista))
        return NULL;
    aux = lista->primeiro->proximo;
    while (aux && strcmp(aux->palavra.string_aloc, palavra) != 0)
    {
        aux = aux->proximo;
        if(aux == NULL)
            return NULL;
    }
    if (strcmp(aux->palavra.string_aloc, palavra) == 0)
        return aux;
}
//Função retornar o tamanho da lista
int numero_palavra(Tlista *lista)
{
    return lista->tam;
}
//Função irá imprimir todos os elementos de uma determinada lista
void imprimi_lista(Tlista *lista)
{
    Apontador_celula_lista aux;
    aux = lista->primeiro->proximo;
    while (aux)
    {
        ImprimiPalavra_Linha(&aux->palavra); //Chama outras funções que de fato terá as funções de printar na tela
        aux = aux->proximo;
    }
}