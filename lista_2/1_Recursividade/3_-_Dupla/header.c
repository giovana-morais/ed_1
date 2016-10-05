#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void inicLista(Lista *plista){
	*plista = NULL;
}

int listaVazia(Lista *plista){
	if(*plista == NULL)
		return 1;
	return 0;
}

void imprimirNormal(ll *lista){
	if(lista->ant == lista->prox)
		printf("%d ", lista->n);
	else
		imprimirNormal(lista->ant);
}

void insereOrdenado(Lista *plista, int num){
	ll *novo, *aux;
	aux = *plista;
	if(listaVazia(plista) || aux->n > num){
		novo = (ll*) malloc(sizeof(ll));
		novo->n  = num;
		novo->ant = NULL;
		novo->prox = aux;
		*plista = novo;
	} else if (aux->prox == NULL || aux->prox->n > num) {
		novo = (ll*) malloc(sizeof(ll));
		novo->n  = num;
		novo->prox = aux->prox;
		novo->ant = aux;
		if(aux->prox != NULL)
			novo->prox->ant = novo;
		aux->prox = novo;
	} else 
		insereOrdenado(&aux->prox, num);

}
void exibe(Lista *p_l){
	while((*p_l) != NULL){
		printf("%d ", (*p_l)->n);
		*p_l = (*p_l)->prox;
	}
	printf("\n");
}

