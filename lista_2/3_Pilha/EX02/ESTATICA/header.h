#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *vetor;
	int topo;
} Pilha;

void inicia_pilha(Pilha *pilha);

void aloca_mem(Pilha *pilha, int N);

void imprime_original(Pilha *pilha);

void empilha(Pilha *pilha, int num);

int desempilha(Pilha *pilha);

int pilha_vazia(Pilha *pilha);

void enqueue(Pilha *pilha, int num);

int dequeue(Pilha *pilha, Pilha *aux);
