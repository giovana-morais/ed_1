#include"header.h"
#include<stdio.h>
#include<stdlib.h>

void inicLista(ll **plista){
	*plista = NULL;
}
// Todas recursivas:
void imprimirNormal(ll *lista){
	printf("%d ", lista->n);
	if(lista->prox == NULL){
		printf("\n");
	}
	else{
		imprimirNormal(lista->prox);
	}
}
void imprimirReverso(ll *lista){
	ll *aux;
	aux = lista;
	if(aux->prox != NULL){
		imprimirReverso(aux->prox);
	}
	printf("%d ", aux->n);
}
void insereOrdenado(ll **plista, int e){
	ll *aux, *novo;
	aux = *plista;
	if(*plista == NULL){                      //lista vazia (só insere)
		novo = (ll *) malloc(sizeof(ll));
		novo->prox = NULL;
		novo->n  = e;
		*plista = novo;
	}
	else if(aux->prox == NULL){ 						//lista com unico elemento                   || aux->prox->n > e
		if(aux->n < e){														//verifica se e é maior que aux n
			novo = (ll *) malloc(sizeof(ll));
			novo->n  = e;
			novo->prox = NULL;
			aux->prox = novo;
		}
		else{
			novo = (ll *) malloc(sizeof(ll));
			novo->n  = e;
			novo->prox = aux;
			*plista = novo;
		}
	}
	else if(aux->n < e && aux->prox->n > e){
		novo = (ll *) malloc(sizeof(ll));
		novo->n = e;
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	else if(aux->n > e){
		novo = (ll *) malloc(sizeof(ll));
		novo->n  = e;
		novo->prox = aux;
		*plista = novo;
	}
	else{
		insereOrdenado(&aux->prox, e);
	}
}


int tamanhodaLista(ll *lista){
	int tam;
	ll *aux;

	aux = lista;
	if(aux != NULL){
		if(aux == lista){
			tam = 0;
		}
		tam = tamanhodaLista(aux->prox) + 1;
		return tam;
	}
	return 0;


}
//Bonus opcional:
void liberaRecursivo(ll **plista){
	ll *aux = *plista;

	if(aux->prox != NULL){
		liberaRecursivo(&aux->prox);
	}
	free(aux);
}
