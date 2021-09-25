#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Biblioteca/Utils.h"
#include "Biblioteca/Fila.h"

pDFila fatoracaoPrima(int n){
    pDFila fatorFila = criarFila();
    int primo=2;

    while(n!=1){
        if(n%primo==0){
            enfileirarInfo(fatorFila,alocaInt(primo));
            n=n/primo;
        }
        else
            primo++;
    }

    int cont=1;
    while (filaVazia(fatorFila)==0){
        void *info = desenfileirarInfo(fatorFila);
        printf("O %dº divisor primo é: %d \n", cont, *((int*)info));
        cont++;
    }
}

int main(){
	setlocale(LC_ALL,"");
	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);

    fatoracaoPrima(num);
    getch();
}
