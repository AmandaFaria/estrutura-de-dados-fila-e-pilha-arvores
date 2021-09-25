#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BibliotecaArvoreBinaria/Utils.h"
#include "BibliotecaArvoreBinaria/ArvoreBinaria.h"


int somaCaminho(pNohArvore arvore, int n){
	if(arvore == NULL){
		return 0;
	}
	printf("\n1. %d - %d", n, *((int *)arvore->info));
	if(arvore->direita == NULL && arvore->esquerda == NULL){
		printf("\n%d - %d", n, *((int *)arvore->info));
		if((n - *((int *)arvore->info)) == 0){
			printf("\n2. %d", n);
			return 1;
		}
		printf("\n3. %d", n);
		return 0;
	}
	else{
		int x, y;
		x = somaCaminho(arvore->direita, n - *((int *)arvore->info));
		y = somaCaminho(arvore->esquerda, n - *((int *)arvore->info));

		if(x == 1 || y == 1){
			printf("\n4. %d", n);
			return 1;
		}
		printf("\n5. %d", n);
		return 0;
	}
	printf("\n6. %d", n);
	return 0;
}


int main(){
	setlocale(LC_ALL, "");
    pDArvore pArvoreInt = criarArvore(2);

    incluirInfo(pArvoreInt, alocaInt(33), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(15), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(41), comparaInt);
	incluirInfo(pArvoreInt, alocaInt(38), comparaInt);
	incluirInfo(pArvoreInt, alocaInt(47), comparaInt);
	incluirInfo(pArvoreInt, alocaInt(34), comparaInt);
	incluirInfo(pArvoreInt, alocaInt(43), comparaInt);
	incluirInfo(pArvoreInt, alocaInt(49), comparaInt);

	printf("Pré ordem: ");
    preOrdem(pArvoreInt->raiz, imprimeInt);

	int t = somaCaminho(pArvoreInt->raiz, 146);

	if(t == 1){
		printf("\n\nN é igual à %d\n", t);
	}
	else
		printf("\n\nN é igual à %d\n", t);

	system("pause");
}
