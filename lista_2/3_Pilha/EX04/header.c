#include <stdio.h>
#include "header.h"
#include <time.h>

int pilha_vazia(Pilha *pilha){
	if(pilha->topo == 0)
		return 1;
	return 0;
}

void inicia_pilha(Pilha *pilha){
	pilha->topo = 0;	
}

void aloca_mem(Pilha *pilha, char N){
	pilha->vetor = (char*) malloc(N * sizeof(char));
}


void imprime_original(Pilha *pilha){
	int i;

	for(i = 0; i < pilha->topo; i++)
		printf("%c ", pilha->vetor[i]);
	printf("\n");
}

void imprime_reversa(Pilha *pilha){
	int i;

	for(i = pilha->topo - 1; i >= 0; i--)
		printf("%d ", pilha->vetor[i]);
	printf("\n");

}

void empilha(Pilha *pilha, char c){
	pilha->vetor[pilha->topo] = c;
	pilha->topo++;
}

void desempilha(Pilha *pilha){
	if(pilha_vazia(pilha))
		return;
	pilha->topo -= 1;
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
