#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct arvore
{
    int info;
    struct arvore *esquerda,*direita;
}Arvore;

void alocaInt(struct arvore **inicio, int info);
void preOrdem(struct arvore *inicio);

int eh_Perfeita(struct arvore *inicio){
    if (inicio) {
        if(((!inicio ->direita)&&(inicio ->esquerda)) || (inicio ->direita)&&(!inicio ->esquerda))
	    return 0;
	else
	    return eh_Perfeita(inicio ->esquerda) && eh_Perfeita(inicio ->direita);
    }
    return 1;
}

int main(){
	setlocale(LC_ALL, "");

    struct arvore *arvoreB = NULL;

    alocaInt(&arvoreB, 4);
    alocaInt(&arvoreB, 2);
    alocaInt(&arvoreB, 3);
	alocaInt(&arvoreB, 1);
	alocaInt(&arvoreB, 7);
	alocaInt(&arvoreB, 5);
	alocaInt(&arvoreB, 9);

	preOrdem(arvoreB);

	if(eh_Perfeita(arvoreB) == 1){
    	printf("\nA Árvore Binária é perfeita!\n");
	}
	else
		printf("\nA Árvore Binária não é perfeita!\n");

    system("pause");
}

void preOrdem(struct arvore *inicio){
    if (inicio){
	printf("%d ", inicio->info);
        preOrdem(inicio->esquerda);
        preOrdem(inicio->direita);
    }
}

void alocaInt(struct arvore **inicio, int info){
    struct arvore *aux;
    if (!*inicio){
        if((aux = (struct arvore*) malloc(sizeof(struct arvore))) != NULL)
        {
            aux -> info = info;
	    aux -> direita = NULL;
	    aux -> esquerda = NULL;
	    *inicio = aux;
        }
        else
            printf("Não foi possível realizar o alocamento de memória");
    }
    else{
        if ((*inicio)->info > info)
	    alocaInt(&((*inicio)->esquerda), info);
	else
	    if((*inicio)->info < info)
	        alocaInt(&((*inicio)->direita), info);
	    else
		printf("%d já está na ÁrvoreBinária!\n", info);
    }
}
