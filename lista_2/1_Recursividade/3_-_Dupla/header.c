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
	if(listaVazia(&aux) || aux->prox == NULL || aux->prox->n > num){
		novo = (ll*) malloc(sizeof(ll));
		novo->n = num;
		if(listaVazia(&aux)){
			printf("lista vazia\n");
			*plista = novo;
			novo->prox = NULL;
			novo->ant = NULL;
			return;
		} else if(aux->ant == NULL){
			printf("insere no inicio\n");
			novo->ant = NULL;
			novo->prox = *plista;
			aux->ant = novo;
			*plista = novo;
			return;
		} else if(aux->prox == NULL){
			printf("insere no fim\n");
			novo->prox = aux->prox;
			aux->prox = novo;
			novo->ant = aux;
			return;
		} else {
			printf("qualquer outro caso\n");
			novo->prox = aux->prox;
			aux->prox->ant = novo;
			novo->ant = aux;
			aux->prox = novo;
		}
	} else {
		insereOrdenado(&aux->prox, num);	
	}	
}
void exibe(Lista *p_l){
	while((*p_l) != NULL){
		printf("%d ", (*p_l)->n);
		*p_l = (*p_l)->prox;
	}
	printf("\n");
}

