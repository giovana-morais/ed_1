#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int vetor[MAX];
	int topoA, topoB;
} Pilha;


void cria_pilhas(Pilha *pilha);

int vaziaA(Pilha *pilha);

int vaziaB(Pilha *pilha);

void imprimeA(Pilha *pilha);

void imprimeB(Pilha *pilha);

void imprime_alternada(Pilha *pilha);

void imprime_original(Pilha *pilha);

void empilhaA(Pilha *pilha, int num);

void empilhaB(Pilha *pilha, int num);

void desempilhaA(Pilha *pilha);

void desempilhaB(Pilha *pilha);

int cheia(Pilha *pilha);

