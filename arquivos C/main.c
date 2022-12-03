#include "../arquivos H/TAD_dicionario.h"

//branch top
int main(){
    TDicionario Dicionario1;
    char nome_arquivo[400];
    char palavra_removida[80];
    int operacao;
    int testa_arquivo;
    char letra_da_lista, lixo;

    printf("Escreva o path do arquivo (ex.: 'texto.txt'):\n");
    scanf("%s", nome_arquivo);
    printf("Nome/endereco do arquivo: %s \n",nome_arquivo);

    /*funcoes que iniciam e preenchem o dicionario*/
    Faz_Dicionario_Vazio(&Dicionario1);

    testa_arquivo = Constroi_Dicionario(&Dicionario1, nome_arquivo);
  
    if (testa_arquivo==1){
        exit(1);
    }

    printf("\nQual operacao deseja efetuar:\n\n(1) = Imprime lista inteira;\n(2) = Imprime lista de uma letra especifica;\n(3) = Remove palavra especifica;\n(4) = Remove do final;\n(5) = Tamanho de lista especifica;\n(6) = Tamanho do dicionario;\n(7) = Sair;\n");
    scanf("%d", &operacao);
    do{    
        switch (operacao) {
            case 1: 
                Imprime_Dicionario(&Dicionario1); 
                break;
            case 2:
                printf("A lista a ser impressa sera de qual letra:\n");
                fflush(stdin);
                scanf("\n%c",&letra_da_lista);
                Imprime_Lista_Letra_Especifica(&Dicionario1,letra_da_lista);
                break;
            case 3:
                printf("Digite para a palavra a ser removida:\n");
                scanf("%s", palavra_removida);
                Remove_palavra_especifica(&Dicionario1, palavra_removida);
                break;
            case 4:
                printf("Digite para a letra chave da lista a ser removida:\n");
                scanf("\n%c", &letra_da_lista);
                Remove_ultima_palavra_lista(&Dicionario1, letra_da_lista);
                break;
            case 5:
                printf("Digite a letra chave da lista que deseja saber o tamanho:\n");
                scanf("\n%c", &letra_da_lista);
                Tamanho_lista_especifica(&Dicionario1, letra_da_lista);
                break;
            case 6:
                Tamanho_dicionario(&Dicionario1);
                break;
            case 7:
                exit(0);
            default:
                printf("Numero invalido. Favor inserir um numero valido!!! \n");
                break;
        }
        printf("\nQual operacao deseja efetuar:\n\n(1) = Imprime lista inteira;\n(2) = Imprime lista de uma letra especifica;\n(3) = Remove palavra especifica;\n(4) = Remove do final;\n(5) = Tamanho de lista especifica;\n(6) = Tamanho do dicionario;\n(7) = Sair;\n");
        operacao = 0;
        scanf("%c", &lixo);
        scanf("\n%d", &operacao);
    }while(operacao!=7);
    return 0;
}