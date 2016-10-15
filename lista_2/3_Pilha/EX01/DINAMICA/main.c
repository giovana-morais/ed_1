#include <stdio.h>
#include "header.h"


int main(){
	Pilha pilha, par, impar;
	int N;

	inic_pilha(&pilha);
	inic_pilha(&par);
	inic_pilha(&impar);
	scanf("%d", &N);
	
	gera_sequencia(&pilha, N);
	//empilha(&pilha, 3);
	//empilha(&pilha, 2);
	//empilha(&pilha, 1);
	printf("sequencia original:\n");
	imprime_original(&pilha);
	printf("\n");
	printf("sequencia reversa:\n");
	imprime_reversa(&pilha);
}
