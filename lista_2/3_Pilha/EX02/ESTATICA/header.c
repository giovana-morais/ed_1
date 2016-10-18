#include <stdio.h>
#include "header.h"
#include <time.h>

void inicia_pilha(Pilha *pilha){
	pilha->topo = 0;	
}

void aloca_mem(Pilha *pilha, int N){
	pilha->vetor = (int*) malloc(N * sizeof(int));
}

int pilha_vazia(Pilha *pilha){
	if(pilha->topo == 0)
		return 1;
	return 0;
}

void imprime_original(Pilha *pilha){
	int i;

	for(i = 0; i < pilha->topo; i++)
		printf("%d ", pilha->vetor[i]);
	printf("\n");
}

void empilha(Pilha *pilha, int num){
	pilha->vetor[pilha->topo] = num;
	pilha->topo++;
}

int desempilha(Pilha *pilha){
	int top;
	if(pilha_vazia(pilha))
		return 0;
	top = pilha->vetor[pilha->topo];
	pilha->topo--;
	return top;
}

void enqueue(Pilha *pilha, int num){
	empilha(pilha, num);
}

int dequeue(Pilha *pilha, Pilha *aux){
	int retorno;
	while(!pilha_vazia(pilha))
		empilha(aux, desempilha(pilha));
	
	retorno = desempilha(aux);
	while(!pilha_vazia(aux))
		empilha(pilha, desempilha(aux));

	return retorno;
}
