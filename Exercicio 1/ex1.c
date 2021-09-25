#include <stdio.h>
//#include <locale.h>
#include "Biblioteca/Utils.h"
#include "Biblioteca/Fila.h"

pDLista NGE (pDFila fila){
	pDLista Lista = criarLista();
	void *info = desenfileirarInfo(fila);
	void *info2 = desenfileirarInfo(fila);

    while (filaVazia(fila)==0){

        if(info < info2){
    		incluirInfo(Lista, alocaInt(*((int*)info2)));
    		info = desenfileirarInfo(fila);
    	}
    	else{
    		info2 = desenfileirarInfo(fila);
			incluirInfo(Lista, alocaInt(*((int*)info2)));
		}

	}
	if(filaVazia(fila)!=0){
		incluirInfo(Lista, alocaInt(-1));
	}
    imprimirLista(Lista, imprimeInt);

}


int main(){
   // setlocale(LC_ALL,"");
    pDFila pFilaInt = criarFila();

    enfileirarInfo(pFilaInt, alocaInt(4));
    enfileirarInfo(pFilaInt, alocaInt(5));
    enfileirarInfo(pFilaInt, alocaInt(2));
    enfileirarInfo(pFilaInt, alocaInt(25));

    printf("O Next Greater Element eh:\n");
    printf("%d", NGE(pFilaInt));
    getch();
}
