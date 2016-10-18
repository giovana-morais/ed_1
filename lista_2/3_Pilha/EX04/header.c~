#include <stdio.h>
#include "header.h"
#include <time.h>

void gera_sequencia(int N, int *vetor){
	int i;

//	for(i = 0; i < N; i++)
//		vetor[i] = srand();

}

void inicia_pilha(Pilha *pilha){
	pilha->topo = 0;	
}

void aloca_mem(Pilha *pilha, int N){
	pilha->vetor = (int*) malloc(N * sizeof(int));
}


void imprime_original(Pilha *pilha){
	int i;

	for(i = 0; i < pilha->topo; i++)
		printf("%d ", pilha->vetor[i]);
	printf("\n");
}

void imprime_reversa(Pilha *pilha){
	int i;

	for(i = pilha->topo - 1; i >= 0; i--)
		printf("%d ", pilha->vetor[i]);
	printf("\n");

}

void empilha(Pilha *pilha, int num){
	pilha->vetor[pilha->topo] = num;
	pilha->topo++;
}

void desempilha(Pilha *pilha){
	pilha->topo--;
}


void imprime_alternada(Pilha *pilha){
	int i;

	for(i = 0; i < pilha->topo; i++){
		if(i % 2 == 0)
			printf("%d ", pilha->vetor[i]);
	}
	for(i = 0; i < pilha->topo; i++){
		if(i % 2 == 1)
			printf("%d ", pilha->vetor[i]);
	}
	printf("\n");	
}
