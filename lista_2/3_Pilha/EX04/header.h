#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *vetor;
	int topo;
} Pilha;

void inicia_pilha(Pilha *pilha);

int pilha_vazia(Pilha *pilha);

void aloca_mem(Pilha *pilha, char N);

void imprime_original(Pilha *pilha);

void imprime_reversa(Pilha *pilha);

void imprime_alternada(Pilha *pilha);

void imprime_original(Pilha *pilha);

void empilha(Pilha *pilha, char num);

void desempilha(Pilha *pilha);
