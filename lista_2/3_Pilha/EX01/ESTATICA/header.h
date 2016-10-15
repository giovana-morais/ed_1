#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *vetor;
	int topo;
} Pilha;

void inicia_pilha(Pilha *pilha);

void aloca_mem(Pilha *pilha, int N);

void imprime_original(Pilha *pilha);

void imprime_reversa(Pilha *pilha);

void imprime_alternada(Pilha *pilha);

void imprime_original(Pilha *pilha);

void gera_sequencia(int N, int *vetor);

void empilha(Pilha *pilha, int num);

void desempilha(Pilha *pilha);

/*void imprime_original(int *vetor);

void imprime_reversa(int *vetor);

void imprime_alternada(int *vetor);

void imprime_original(int *vetor);

void gera_sequencia(int N, int *vetor);
*/
