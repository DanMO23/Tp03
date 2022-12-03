#include "funcoes_zorzal.h"
/*
#include "../arquivos H/TAD_lista.h"
#include "../arquivos H/TADPalavra.h"
*/

/* Um valor menor que zero significa que string1 é menor que string2. Um valor zero significa que ambas as strings são iguais. Um valor maior que zero significa que string1 é maior que string2.*/

int main(){
    Tlista lista;
    int i;
    for (i = 0; i< N; i++){
        scanf("%s",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    printf("============\n");
    selecao(lista, N);
    insercao(lista, N);
    /*
    for (i = 0; i< N; i++){
        printf("%s\n",lista.palavra[i].string_aloc);
        lista.palavra[i].linha = i;
    }
    */
    return 0;
}

/*
abacate
pera
flor
jiboia
ameba
coxinha
pao
caximbo
carambola
dorgas
*/





/*int main(){
	char nome1[10] = "aznha";//7
	char nome2[10] = "ameba";//5
	int i;
	char aux[10];
	i = strcmp(nome1,nome2);
	if (i > 0){//
        printf("%s ",nome1);
	    printf("%s",nome2);
	} 
    else {
        printf("%s ",nome2);
        printf("%s",nome1);
    }
	return 0;
}
*/