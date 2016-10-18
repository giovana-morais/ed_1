#include <stdio.h>
#include "header.h"
#include <time.h>

int main(){
	Pilha pilha, aux, pilha2;
	int N, seed, i;

	inic_pilha(&pilha);
	inic_pilha(&aux);
	inic_pilha(&pilha2);

	scanf("%d", &seed);
	srand(seed);
	for(i = 0; i < N; i++)
		empilha(&pilha, rand() % 3*N);
	// imprimir original
	/*empilha(&pilha, 1);
	empilha(&pilha, 2);
	empilha(&pilha, 3);
	empilha(&pilha, 4);
	empilha(&pilha, 5);
	*/ 
	muda_ordem(&pilha, &aux);
	exibe(&aux);
	printf("\n");

	// imprimir alternado 
	separa(&aux, &pilha, &pilha2);
	junta(&aux, &pilha, &pilha2);
	printf("\n");	

	// imprimir original de novo
	separa(&aux, &pilha, &pilha2);
	printf("p1 ");
	exibe(&pilha);
	printf("\n");	
	printf("p2 ");
	exibe(&pilha2);	
	printf("\n");	
	junta(&aux, &pilha, &pilha2);
	printf("\n");


}
