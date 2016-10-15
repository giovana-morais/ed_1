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
/*
	if(lista == comeco)
		printf("lista == comeco\n");
	else
		printf("lista != comeco\n");

	if(flag == 0)
		printf("flag == 0\n");
	else
		printf("flag != 0\n");
*/
	if(lista == comeco && flag == 0){
		flag = 1;
		printf("%d ", lista->n);
		imprimirNormal(lista->prox, comeco);
	} else if(flag != 0 && lista != comeco) {
		printf("%d ", lista->n);
		imprimirNormal(lista->prox, comeco);
	} else {
		/*printf("socorro\n");
		printf("%d ", lista->n);*/
		return;
	}
	
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
	} else if((*plista)->prox == comeco && comeco->n < num){
		novo = (ll*) malloc(sizeof(novo));
		novo->n = num;
		novo->prox = comeco;
		(*plista)->prox = novo;
		
	} else {
		insereOrdenado(plista, comeco, num);
	}

//	printf("teste insereOrdenado\n");
}

