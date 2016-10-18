#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void inicLista(Lista *plista){
	*plista = NULL;
}

int listaVazia(Lista *plista){
	if(*plista == NULL)
		return 1;
	return 0;	
}
void imprimirNormal(ll *lista, ll *comeco){
	int flag;
	
	if(listaVazia(&lista))
		return;
	if(lista == comeco){
		printf("%d ", comeco->n);
	} else {
		printf("%d ", comeco->n);
		imprimirNormal(lista, comeco->prox);
	}

}

void imprimirReverso(ll *lista, ll *comeco){
	if(listaVazia(&lista))
		return;
	else if(lista == comeco)
		printf("%d ", comeco->n);
	else {
		imprimirReverso(lista, comeco->prox);
		printf("%d ", comeco->n);
	}
}

int tamanhodaLista(ll *lista, ll *comeco){
	if(listaVazia(&lista))
		return 0;
	else if(lista == comeco)
		return 1;
	else
		return tamanhodaLista(lista, comeco->prox) + 1;
}

void insereOrdenado(Lista *plista, ll *comeco, int num){
	ll *novo;

	if(listaVazia(plista)){
		printf("lista vazia\n");
		novo = (ll*) malloc(sizeof(novo));
		novo->prox = novo;
		novo->n = num;
		*plista = novo;
		comeco = novo;
		return;
	}

	if((*plista)->prox->n > num){
		novo = (ll*) malloc(sizeof(novo));
		novo->n = num;
		novo->prox = (*plista)->prox;
		(*plista)->prox = novo;
		return;
	} else if((*plista)->n < num){
		novo = (ll*) malloc(sizeof(novo));
		novo->n = num;
		novo->prox = comeco;
		(*plista)->prox = novo;
		*plista = novo;
		
	} else if(comeco->prox->n > num){
		novo = (ll*) malloc(sizeof(novo));
		novo->n = num;
		novo->prox = comeco->prox;
		comeco->prox = novo;	
	} else {
		insereOrdenado(plista, comeco->prox, num);
	}

//	printf("teste insereOrdenado\n");
}

