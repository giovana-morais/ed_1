#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista_dupla.h"

/* Inicializa uma lista */
void inicLista(Lista *lista){
	*lista = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *lista){
	if(*lista == NULL) 
		return 1;
	return 0;
}

/* Insere no inicio */
void insereInicio(Lista *lista, elem_t e){
	No_lista *novo;

	novo = (No_lista*) malloc(sizeof(No_lista));

	novo->info = e;

	novo->prox = (*lista);
	novo->ant = NULL;
	
	if(!listaVazia(lista))
		(*lista)->ant = novo;
	*lista = novo;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *lista, elem_t e){
	No_lista *novo, *aux;


	if(listaVazia(lista)){
		insereInicio(lista, e);
	} else {
		novo = (No_lista *) malloc(sizeof(No_lista));
		novo->info = e;
		novo->prox = NULL;
		aux = *lista;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
		novo->ant = aux;

	}

}

void inverte(Lista *lista){
	No_lista *aux, *aux2;

	aux = *lista;
	if(listaVazia(lista) || aux->prox == NULL)
		return;

	aux2 = aux->prox;
	
	while(aux2->prox != NULL){
		aux->prox = aux->ant;
		aux->ant = aux2;
		aux = aux2;
		aux2 = aux2->prox;
	}
	
	aux->prox = aux->ant;
	aux->ant = aux2;
	aux2->prox = aux;
	aux2->ant = NULL;
	
	*lista = aux2;
}
	
/* Insere números aleatórios na lista */
void geraListaAleatoria(int N, Lista *lista){
	int i, num;
	
	//srand((unsigned) time(NULL));

	for(i = 0; i < N; i++){
		num = 1 + rand() % 99999;
		insereFim(lista, num);
		
	}
}

void exibe(Lista *lista){
	No_lista *aux;
	aux = *lista;

	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");
}

void ordena(Lista *lista){
	No_lista *aux, *aux2, *desord, *ord;

	if(listaVazia(lista) || (*lista)->prox == NULL)
		return;

	desord = (*lista)->prox;
	aux = desord->prox;
	desord->ant = NULL;
	(*lista)->prox = NULL;

	// tem algo dando errado, mas eu quero é que se foda
	while(desord != NULL){
		ord = *lista;
		if(ord->info > desord->info){
			// arrumar aqui
			desord->prox = ord;
			if(aux != NULL)
				aux->ant = desord->ant;
			desord->ant = ord->ant;
			ord->ant = desord;
			*lista = desord;
		} else {
			while(ord->prox != NULL && desord->info > ord->prox->info){
				ord = ord->prox;
			}
			desord->prox = ord->prox;
			ord->prox = desord;
			aux->ant = desord->ant;
			desord->ant = ord->prox->ant;
			ord->prox->ant = desord;
		}
		desord = aux;
		if(aux != NULL)
			aux = aux->prox;
		
	}	
		
}


float calculaMedia(Lista *lista){
	int soma = 1;
	float media;
	No_lista *aux;

	if(listaVazia(lista))
		return 0.0;

	aux = (*lista)->prox;
	media = (*lista)->info;
	while(aux != NULL){
		media += aux->info;
		aux = aux->prox;
		soma++;
	}
	
	media /= soma;
	return media;
}
