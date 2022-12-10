#include "../Headers/TAD_dicionario.h"

/*
!O modelo de lista encadeada escolhido para o TAD_dicionario foi o com cabeca
*/

//inicia o dicionario vazio. Da exit 1 para erros de alocacao
int Faz_Dicionario_Vazio(TDicionario* pDicionario){
    pDicionario->pPrimeira_Lista = (Apontador_Celula_Dicionario)malloc(sizeof(TCelulaDicionario));

    /*Caso o malloc nao seja efetuado:*/
    if(pDicionario->pPrimeira_Lista == NULL){
        printf("Problemas na alocacao de memoria: nao foi possivel realizar a alocacao \n");
        exit(1);
    }
    pDicionario->pUltima_Lista = pDicionario->pPrimeira_Lista;
    pDicionario->pUltima_Lista->Prox_celula_lista = NULL;

    return 0;
}

//Imprime as palavras de uma lista dada a letra chave da lista. Caso dicionario seja vazio ou uma dada lista e vazia, retorna 1
int Imprime_Lista_Letra_Especifica(TDicionario* pDicionario, char letra){
    Apontador_Celula_Dicionario pAux;
    int achou_lista = 0;

    /*Caso o dicionario esteja vazio*/
    if(Dicionario_e_vazio(pDicionario)){
        printf("Dicionario e vazio\n");
        return 1;
    }

    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista; /*endereco primeira celula*/

    while (pAux != NULL){
        /*o while vai parar ao achar a lista da letra 'letra' ou ao achar uma lista NULL*/
        if (pAux->letra_lista == letra){
            achou_lista = 1;
            break;
        }
        else{
            pAux = pAux->Prox_celula_lista;/*avanca uma lista*/
        }
    }
    if(achou_lista == 1){
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("Lista da letra %c:\n",pAux->letra_lista); //lista da letra 'letra_lista'
        //função TAD_lista
        imprimi_lista(&pAux->lista);
        printf("=-=-=-=-=-=-=-=-=-=\n\n");
        return 0;
    }
    else{
        printf("Nao ha palavras que comecam com a letra '%c' neste dicionario\n",letra);
        return 1;
    }
}

//Imprime diciionario todo. Caso dicionario e vazio, retorna 1
int Imprime_Dicionario(TDicionario* pDicionario){
    Apontador_Celula_Dicionario pAux;
    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista; //primeira lista
    printf("=-=-=-=-=-= DICIONARIO =-=-=-=-=-=\n");

    /*Testa se o dicionario é vazio*/
    if(Dicionario_e_vazio(pDicionario)){
        printf("O dicionario esta vazio\n");
        return 1;
    }
    while (pAux != NULL){ /*Para quando pAux é null, ou seja, no fim da lista*/
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("Lista da letra %c:\n",pAux->letra_lista); //lista da letra 'letra_lista'

        //funçao TAD_lista
        imprimi_lista(&pAux->lista);

        printf("=-=-=-=-=-=-=-=-=-=\n\n");
        pAux = pAux->Prox_celula_lista; //proxima lista
    }
    return 0;
}

//Retorna 1 para dicionario vazio e 0 caso contrario
int Dicionario_e_vazio(TDicionario* pDicionario){
    return (pDicionario->pPrimeira_Lista == pDicionario->pUltima_Lista);
    /*se ambos apontam pro mesmo, então ambos apontam para a celula cabeca e, consequentemente, o dicionario esta vazio*/
}

//Funcao que le arquivo a monta o dicionario. Retorna 1 para erro de abertura do arquivo.
int Constroi_Dicionario (TDicionario* pDicionario, char* nome_arquivo_txt){
    FILE* arq;

    /*Variavel para armazenar temporariamente as palavras do documento*/
    char string[90];

    /*variavel para pegar os espacos e \n desconsiderados pelo fscanf*/
    char sep;

    /*conta quantas linhas ja foram lidas*/
    int linha = 1;

    /*Abre arquivo*/
    arq = fopen(nome_arquivo_txt,"r");

    /*Confere se o arquivo abriu corretamente*/
    if (arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return 1;
    }
    while(fscanf(arq,"%s",string) != EOF){
        /*A funcao Encadeia_Celula_Dicionario realiza a tarefa de encadear as celulas(explicacao mais
         * desenvolvida dentro da funcao. Ja a funcao Constroi_Dicionario é a responsavel por ler o arquivo
         * e passar os parametros corretos para a funcao Encadeia_Celula_Lista. O fluxo de funcionamento é o
         * seguinte:
         * (1) Recebe a palavra dentro do while e confere se não é fim de arquivo
         * (2) Passa a palavra e a linha como parametros para a funcao Encadeia_Celula_Dicionario
         * (3) sep recebe o caracter que vem logo apos a palavra. A funcao fscanf desconsidera os caracteres
         * como espaços e \n. Portanto, usa-se o fgetc para pegar o caracter que vem imediatamente apos o
         * fim de uma palavra (note que os comandos de leitura de arquivo continuam lendo os arquivos do mesmo
         * ponto onde a ultima leitura foi feita. Por isso o fscanf e o fgetc se complementam).
         * (4) Se o sep for espaço, nada ocorre. Caso seja um \n, significa que o proximo fscanf estara pegando
         * uma palavra da proxima linha. Então caso seja um \n, faz-se o incremento do numero de linhas
         * (5) Se sep == EOF, o arquivo acabou e se encerra o while. Note que tanto o fscanf quanto o sep tem
         * a condiçao de parada para EOF, pois se o arquivo estiver vazio, ou se ouver um caracter especial
         * antes do EOF, o fscanf vai idenficar primeiro, caso contraio, o fgetc identifica primeiro*/

        Encadeia_Celula_Dicionario(pDicionario, string, string[0], linha);
      
        sep = fgetc(arq);

        if(sep == '\n'){
            linha++;
        }
        if(sep == EOF){
            break;
        }
   
    }
    /*Fecha arquivo*/
    fclose(arq);
    return 0;
}

//Parte da funcao constroi_dicionario responsavel por encadear celulas
int Encadeia_Celula_Dicionario(TDicionario* pDicionario, char *string, char letra, int linha){
    Apontador_Celula_Dicionario pAux,pAux2,pGuardaEndereco;
    /*endereço celula cabeça*/
    pAux2 = pDicionario->pPrimeira_Lista;
    /*endereço da primeira celula valida*/
    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;

    /*Explicaçao do porque dois ponteiros:
     * Foi utilizado um sistema de comparação onde compara-se o caracter chave da celula com o caracter
     * passado como parametro (ao fazer comparaçoes entre caracteres, o numero correspondente na tabela
     * ascii  que é avaliado. Como é dito na descriçao do trabalho que as palavras serao todas em letras
     * minusculas, esse sistema de comparaçao funciona). Para cada comparação feita, caso a letra seja maior
     * que a da lista comparada, o ponteiro avança uma casa. Porem, caso chegue-se num caso onde a letra é menor
     * que a lista atual(ex.: o parametro passado é a letra 'c', a lista anterior era da letra 'a' e a proxima
     * lista é a da letra 'd'), é necessario criar uma celula_dicionario entre a celula da letra 'a' e a da letra 'd',
     * porem para realizar essa ligação, é necessario o endereço da celula anterior, que foi perdido. É ai que
     * entra o ponteiro pAux2. Ele é sempre movido em conjunto com o principal (pAux) e permanece sempre apontando
     * sempre para o anterior. Desta forma, é possivel realizar as alocaçoes entre celulas e manter o dicionario em ordem*/

    //Caso onde o dicionario esta vazio: basta criar a celula
    if (Dicionario_e_vazio(pDicionario)){

        pDicionario->pUltima_Lista->Prox_celula_lista = (Apontador_Celula_Dicionario)malloc(sizeof(TCelulaDicionario));
        if(pDicionario->pUltima_Lista->Prox_celula_lista == NULL){
            printf("Problemas na alocacao de memoria: nao foi possivel realizar a alocacao \n");
            exit(1);
        }
        pDicionario->pUltima_Lista = pDicionario->pUltima_Lista->Prox_celula_lista;
        pDicionario->pUltima_Lista->Prox_celula_lista = NULL;
        pDicionario->pUltima_Lista->letra_lista = letra;
        cria_lista(&pDicionario->pUltima_Lista->lista);
        insere_palavra_linha(&pDicionario->pUltima_Lista->lista, linha, string);
       

    }
    else{
        /*Caso o dicionario não seja vazio, tem-se os seguintes casos:*/

        while(pAux != NULL){

            /*CASO ONDE A LISTA PARA A LETRA 'letra' JA EXISTE:
             * basta adicionar os itens a lista*/
            if (letra == pAux->letra_lista){
                insere_palavra_linha(&pAux->lista, linha, string);
                break;
            }

            /*CASO ONDE A LETRA É MAIOR (VEM DEPOIS NO ALFABETO):
             * Neste caso, os ponteiros são avançados e o loop se repete para ver se uma das outras possibilidades
             * é satisfeita*/
            if(letra > pAux->letra_lista ){
                pAux = pAux->Prox_celula_lista;
                pAux2 = pAux2->Prox_celula_lista;
            }

           /*Caso pAux seja NULL, significa que chegou-se ao fim da lista. Portanto basta adicionar a celula ao fim*/
            if(pAux == NULL){
                pGuardaEndereco = (Apontador_Celula_Dicionario)malloc(sizeof(TCelulaDicionario));
                if(pGuardaEndereco == NULL){
                    printf("Problemas na alocacao de memoria: nao foi possivel realizar a alocacao \n");
                    exit(1);
                }
                pGuardaEndereco->Prox_celula_lista = pAux;
                pAux2->Prox_celula_lista = pGuardaEndereco;

                /*Como pAux é null, acabou a lista. Nesse caso, o pDicionario->pUltima_Lista precisa apontar
                 * para o ultimo, que agora é o pGuardaEndereco*/
                pDicionario->pUltima_Lista = pGuardaEndereco;
                pGuardaEndereco->letra_lista = letra;
                cria_lista(&pGuardaEndereco->lista);
                insere_palavra_linha(&pGuardaEndereco->lista, linha, string);
                
                break;
            }

            /*CASO ONDE A LETRA É MENOR QUE A ATUAL MAS MAIOR QUE A ANTERIOR (isso é garantido pois a letra ja
             * foi comparada no if de letra ser maior), OU SEJA, A CELULA NOVA DEVE SER INSERIDA ENTRE A ANTERIOR
             * E A ATUAL:*/
            if((letra < pAux->letra_lista)){
                pGuardaEndereco = (Apontador_Celula_Dicionario)malloc(sizeof(TCelulaDicionario));
                if(pGuardaEndereco == NULL){
                    printf("Problemas na alocacao de memoria: nao foi possivel realizar a alocacao \n");
                    exit(1);
                }
                pGuardaEndereco->Prox_celula_lista = pAux;
                pAux2->Prox_celula_lista = pGuardaEndereco;
                pGuardaEndereco->letra_lista = letra;
                cria_lista(&pGuardaEndereco->lista);
                insere_palavra_linha(&pGuardaEndereco->lista, linha,string);
                break;
            }
        }
    }
    //printf("passei");
    return 0;
}

//Remove uma dada palavra da lista. Caso a palavra nao exista, retorna 1.
int Remove_palavra_especifica(TDicionario* pDicionario, char* string){
    char letra_chave = string[0];
    Apontador_Celula_Dicionario pAux;
    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;
    while(pAux != NULL){
        if(pAux->letra_lista == letra_chave){
            remove_escolhida(&pAux->lista, string);
            if (leh_vazia(&pAux->lista)== 1){
                Remove_celula_dicionario(pDicionario);
            }
            return 0;
        }
        else{
            pAux = pAux->Prox_celula_lista;
        }
    }
    printf("Nao ha essa palavra em lista alguma!\n");
    return 1;
}

//remove palavra do final de uma lista especifica. Se a lista for vazia, retorna 1.
int Remove_ultima_palavra_lista(TDicionario* pDicionario, char letra_lista){
    Apontador_Celula_Dicionario pAux;
   
    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;
    while(pAux!= NULL){
        if (pAux->letra_lista == letra_lista){
            remove_final(&pAux->lista);
            if (leh_vazia(&pAux->lista)== 1){
                Remove_celula_dicionario(pDicionario);
            }
            return 0;
        }
        else{
            pAux = pAux->Prox_celula_lista;
        }
    }
    printf("Nao ha nenhuma palavra com essa letra no dicionario!\n");
    return 1;
}

//remove lista inteira. Se a lista nao for removida (por nao existir), retorna 1.
int Remove_celula_dicionario(TDicionario* pDicionario){
    Apontador_Celula_Dicionario pAux, removedor;
    int verificador;
    pAux = pDicionario->pPrimeira_Lista;
    while(pAux!= NULL){
        
        verificador = leh_vazia(&pAux->Prox_celula_lista->lista);
        if (verificador == 1){
            removedor = pAux->Prox_celula_lista;
            pAux->Prox_celula_lista = pAux->Prox_celula_lista->Prox_celula_lista;
            free(removedor);
            printf("Uma lista foi removida\n");
            if(pAux->Prox_celula_lista == NULL){
                pDicionario->pUltima_Lista = pAux;
            }
            return 0;
        }        
        else{
            pAux= pAux->Prox_celula_lista;
            if(pAux->Prox_celula_lista==NULL){
                printf("Nenhuma lista foi removida");
                return 1;
            }
        }
    }
    return 1;
}

//Função irá informar para o usuario a quantidade de palavras que tem em uma determinada lista
int Tamanho_lista_especifica(TDicionario* pDicionario, char letra_lista){
    Apontador_Celula_Dicionario pAux;
    
    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;
    while (pAux != NULL)
    {
        if(pAux->letra_lista == letra_lista){
            printf("A lista '%c' tem %d itens\n", letra_lista, numero_palavra(&pAux->lista));
            return 0;
        }
        else
            pAux = pAux->Prox_celula_lista;
    }
    printf("Nao ha nenhuma palavra com essa letra no dicionario\n");
    return 1;
}

//Função irá informar para o usuario a quantidade de palavras que tem no dicionario inteiro
int Tamanho_dicionario(TDicionario* pDicionario){
    Apontador_Celula_Dicionario pAux;
    int tamanho=0;
    pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;
    while(pAux != NULL){
        tamanho += pAux->lista.ultimo;
        pAux = pAux->Prox_celula_lista;
    }
    printf("O tamanho do dicionario = %d\n", tamanho);
    return 0;
}

//Ordena o dicionario todo dada uma operacao
int Ordena_dicionario(TDicionario *pDicionario, int operacao, char letra_da_lista,int *conta_movimentacao, int *conta_comparacao, double *conta_tempo){
    Apontador_Celula_Dicionario pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;
    *(conta_movimentacao) = 0;
    *(conta_comparacao) = 0;
    *(conta_tempo) = 0;
    double conta_tempo_aux = 0;
    int conta_comparacao_aux = 0;
    int conta_movimentacao_aux = 0;
    /*
    (1) = Ordenar por BubbleSort;
    (2) = Ordenar por Selecao;
    (3) = Ordenar por Insercao;
    (4) = Ordenar por ShellSort;
    (5) = Ordenar por QuickSort;
    (6) = Ordenar por HeapSort;
    (7) = Voltar ao menu principal;
    */
   
    while (pAux != NULL){
        //Confere se a lista e vazia. Se sim, passa para proxima lista
        if (leh_vazia(&pAux->lista)){ 
            printf("A lista da letra %c e vazia \n",pAux->letra_lista);
            continue;
        }
        Chama_ordena(&pAux->lista, operacao, numero_palavra(&pAux->lista), &conta_movimentacao_aux, &conta_comparacao_aux, &conta_tempo_aux);
        //!Observacao: Como a funcao ordena_lista_especifica ja ordena a lista, basta reutiliza-la para cada lista individualmente
        *(conta_movimentacao) += conta_movimentacao_aux;
        *(conta_comparacao) += conta_comparacao_aux;
        *(conta_tempo) += conta_tempo_aux;
        pAux = pAux->Prox_celula_lista; //avanca para proxima lista
    }
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Numero de Movimentacoes: %d\n",*(conta_movimentacao));
    printf("Numero de Comparacoes: %d\n",*(conta_comparacao));
    printf("Tempo de execucao do insercao: %lfms\n",((double)*(conta_tempo))/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}

//Ordena uma lista dada o tipo da ordenacao e a letra da lista a ser ordenada. retorna 1 para lista vazia ou dicionario vazio
int Ordena_lista_especifica(TDicionario *pDicionario, int operacao, char letra_da_lista,int *conta_movimentacao, int *conta_comparacao, double *conta_tempo){
    Apontador_Celula_Dicionario pAux = pDicionario->pPrimeira_Lista->Prox_celula_lista;
    *(conta_movimentacao) = 0; 
    *(conta_comparacao) = 0;
    *(conta_tempo) = 0;
    //confere se dicionario e vazio:
    if (Dicionario_e_vazio(pDicionario)) {
        printf("Dicionario vazio\n");
        return 1;
    }
    //avanca pelo dicionario procurando a lista especificada:
    while (pAux != NULL){
        if (pAux->letra_lista == letra_da_lista) break;
        else pAux = pAux->Prox_celula_lista;
    } 
    //confere se a lista a ser ordenada e vazia: 
    if (leh_vazia(&pAux->lista)){ 
        printf("A lista da letra %c e vazia \n",pAux->letra_lista);
        return 1;
    }
    /*
    (1) = Ordenar por BubbleSort;
    (2) = Ordenar por Selecao;
    (3) = Ordenar por Insercao;
    (4) = Ordenar por ShellSort;
    (5) = Ordenar por QuickSort;
    (6) = Ordenar por HeapSort;
    (7) = Voltar ao menu principal;
    */

    //Switch para escolher a operacao correta:
    Chama_ordena(&pAux->lista, operacao, numero_palavra(&pAux->lista),conta_movimentacao, conta_comparacao, conta_tempo);

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Numero de Movimentacoes: %d\n",*(conta_movimentacao));
    printf("Numero de Comparacoes: %d\n",*(conta_comparacao));
    printf("Tempo de execucao do insercao: %lfms\n",((double)*(conta_tempo))/((CLOCKS_PER_SEC/1000)));
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    return 0;
}

int Chama_ordena(Tlista *lista, int operacao, int tam, int *conta_movimentacao, int *conta_comparacao, double *conta_tempo){

    clock_t t;
    t = clock();
    /*
    (1) = Ordenar por BubbleSort;
    (2) = Ordenar por Selecao;
    (3) = Ordenar por Insercao;
    (4) = Ordenar por ShellSort;
    (5) = Ordenar por QuickSort;
    (6) = Ordenar por HeapSort;
    (7) = Voltar ao menu principal;
    */
    switch (operacao){
        case 1:
            printf("=-=-=-=-=-=-=-=-=-=\n");
            printf("Sequencia reordenada por Bubble:\n");
            printf("=-=-=-=-=-=-=-=-=-=\n");
            BubbleSort(*(lista),tam, conta_movimentacao, conta_comparacao);
            break;
        case 2:
            printf("=-=-=-=-=-=-=-=-=-=\n");
            printf("Sequencia reordenada por Selecao:\n");
            printf("=-=-=-=-=-=-=-=-=-=\n");
            Selecao(*(lista),tam, conta_movimentacao, conta_comparacao);
            break;
        case 3:
            printf("=-=-=-=-=-=-=-=-=-=\n");
            printf("Sequencia reordenada por Insercao:\n");
            printf("=-=-=-=-=-=-=-=-=-=\n");
            Insercao(*(lista),tam, conta_movimentacao, conta_comparacao);
            break;
        case 4:
            printf("=-=-=-=-=-=-=-=-=-=\n");
            printf("Sequencia reordenada por Shellsort:\n");
            printf("=-=-=-=-=-=-=-=-=-=\n");
            ShellSort(*(lista),tam);
            break;
        case 5:
            printf("=-=-=-=-=-=-=-=-=-=\n");
            printf("Sequencia reordenada por Quicksort:\n");
            printf("=-=-=-=-=-=-=-=-=-=\n");
            Quicksort(*(lista),tam);
            break;
        case 6:
            printf("=-=-=-=-=-=-=-=-=-=\n");
            printf("Sequencia reordenada por Heapsort:\n");
            printf("=-=-=-=-=-=-=-=-=-=\n");
            Heapsort(*(lista),tam);
            break;
        case 7:
            return 0;
            break;
        default:
            printf("\nNumero de operacao invalido!!!");
            break;
    }
    t = clock() - t;
    *(conta_tempo) = t;
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    //printf("Numero de Movimentacoes: %d\n",*(conta_movimentacao));
    //printf("Numero de Comparacoes: %d\n",*(conta_comparacao));
    //printf("Tempo de execucao do insercao: %lfms\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    //printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
