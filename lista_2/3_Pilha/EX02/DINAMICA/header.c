#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void inicPilha(Pilha *pilha){
	pilha->prox = NULL;
}

int PilhaVazia(Pilha *pilha){
	if (pilha->prox == NULL)
		return 1;
	return 0;
}


void push(Pilha *pilha, elem_t e){
	Pilha *novo;
	novo = malloc(sizeof(Pilha));
	novo->num = e;
	novo->prox = pilha->prox;
	pilha->prox = novo;
}

elem_t pop(Pilha *pilha){
	Pilha *topo;
	elem_t ret;

	if (PilhaVazia(pilha))
		return '\0';
	topo = pilha->prox;
	pilha->prox = topo->prox;
	ret = topo->num;
	free (topo);
	return ret;
}

void libera(Pilha *pilha){
	Pilha *aux;
	aux = pilha->prox;
	while(aux != NULL){
		pilha->prox = aux->prox;
		free(aux);
		aux = pilha->prox;
	}
}

void enqueue(Pilha *pilha, elem_t e){
  push(pilha, e);
}

elem_t dequeue(Pilha *pilha){
  Pilha aux;
  elem_t n;
  inicPilha(&aux);

  while(!PilhaVazia(pilha)){
    push(&aux, pop(pilha));
  }
  n = pop(&aux);
  while(!PilhaVazia(&aux)){
    push(pilha, pop(&aux));
  }
  return n;
}
