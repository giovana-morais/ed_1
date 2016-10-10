#include "header.h"
#include <stdio.h>


void inicLista(Lista *plista){
	*plista = NULL;
}

int listaVazia(Lista *plista){
	if(*plista == NULL)
		return 1;
	return 0;	
}
void imprimirNormal(ll *lista, ll *comeco){
	if(lista == comeco){
		printf("%d ", lista->n);
		return;	
	}
	imprimirNormal(lista->prox, comeco);
}

void insereOrdenado(Lista *plista, ll *comeco, int num){

	if(listaVazia(plista)){
	
	}	


}

