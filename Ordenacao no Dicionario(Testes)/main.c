#include "Headers/TAD_dicionario.h"
#ifdef __linux__ 
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#else

#endif
//branch top
/*
gcc .\main.c .\Headers\Heapsort.h .\Headers\Ordenacao_simples.h .\Headers\Quicksort.h .\Headers\ShellSort.h .\Headers\TAD_dicionario.h .\Headers\TAD_lista.h .\Headers\TADPalavra.h .\Sources\Heapsort.c .\Sources\Ordenacao_simples.c .\Sources\Quicksort.c .\Sources\ShellSort.c .\Sources\TAD_dicionario.c .\Sources\TADPalavra.c .\Sources\TAD_lista.c -o run
*/
int main(){
    TDicionario Dicionario1;
    char nome_arquivo[400];
    char palavra_removida[80];
    int operacao, tipo_da_ordenacao,conta_movimentacao = 0,conta_comparacao = 0;
    double conta_tempo = 0;
    int testa_arquivo;
    char letra_da_lista, lixo;

    printf("Escreva o path do arquivo (ex.: 'texto.txt'):\n");
    //scanf("%s", nome_arquivo);

    strcpy(nome_arquivo, "texto.txt");

    printf("Nome/endereco do arquivo: %s \n",nome_arquivo);
    /*
    /*funcoes que iniciam e preenchem o dicionario*/
    
    Faz_Dicionario_Vazio(&Dicionario1);
   

    testa_arquivo = Constroi_Dicionario(&Dicionario1, nome_arquivo);
  
    if (testa_arquivo==1){
        exit(1);
    }
    printf("\nQual operacao deseja efetuar:\n\n(1) = Imprime lista inteira;\n(2) = Imprime lista de uma letra especifica;\n(3) = Remove palavra especifica;\n(4) = Remove do final;\n(5) = Tamanho de lista especifica;\n(6) = Tamanho do dicionario;\n(7) = Ordenar lista especifica;\n(8) = Ordenar dicionario todo;\n(9) = Clear console;\n(10) = Sair;\n");
    scanf("%d", &operacao);
    do{ 
        conta_movimentacao = 0;
        conta_comparacao = 0;   
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
                printf("Digite a letra chave da lista que deseja ordenar:\n");
                scanf("\n%c", &letra_da_lista);
                printf("\nDigite o numero da operacao:\n(1) = Ordenar por BubbleSort;\n(2) = Ordenar por Selecao;\n(3) = Ordenar por Insercao;\n(4) = Ordenar por ShellSort;\n(5) = Ordenar por QuickSort;\n(6) = Ordenar por HeapSort;\n(7) = Voltar ao menu principal;\n");
                scanf("\n%d", &tipo_da_ordenacao);
                Ordena_lista_especifica(&Dicionario1, tipo_da_ordenacao,letra_da_lista,&conta_comparacao,&conta_movimentacao,&conta_tempo);
                break;
            case 8:
                printf("Digite o numero da operacao:\n(1) = Ordenar por BubbleSort;\n(2) = Ordenar por Selecao;\n(3) = Ordenar por Insercao;\n(4) = Ordenar por ShellSort;\n(5) = Ordenar por QuickSort;\n(6) = Ordenar por HeapSort;\n(7) = Voltar ao menu principal;\n");
                scanf("\n%d", &tipo_da_ordenacao);
                Ordena_dicionario(&Dicionario1, tipo_da_ordenacao, letra_da_lista, &conta_movimentacao, &conta_comparacao, &conta_tempo);
                break;
            case 9:
                #ifdef __linux__
                    system("clear");
                #elif _WIN32
                    system("cls");
                #else

                #endif
                break;
            case 10:
                exit(0);
            default:
                printf("Numero invalido. Favor inserir um numero valido!!! \n");
                break;
        }
        printf("\nQual operacao deseja efetuar:\n\n(1) = Imprime lista inteira;\n(2) = Imprime lista de uma letra especifica;\n(3) = Remove palavra especifica;\n(4) = Remove do final;\n(5) = Tamanho de lista especifica;\n(6) = Tamanho do dicionario;\n(7) = Ordenar lista especifica;\n(8) = Ordenar dicionario todo;\n(9) = Clear console;\n(10) = Sair;\n");
        operacao = 0;
        scanf("%c", &lixo);
        scanf("\n%d", &operacao);
    }while(operacao!=10);
    
    return 0;
}

/*
gcc .\main.c .\Sources\Heapsort.c .\Sources\Ordenacao_simples.c .\Sources\Quicksort.c .\Sources\ShellSort.c .\Sources\TAD_dicionario.c .\Sources\TAD_lista.c .\Sources\TADPalavra.c .\Headers\Heapsort.h .\Headers\Ordenacao_simples.h .\Headers\Quicksort.h .\Headers\ShellSort.h .\Headers\TAD_dicionario.h .\Headers\TAD_lista.h .\Headers\TADPalavra.h -o run
*/
