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
	No_lista *aux, *inverte;

	if(listaVazia(lista) || (*lista)->prox == NULL)
		return;
	if((*lista)->ant == NULL)	
		printf("oi\n");
	inverte = (*lista);
	aux = (*lista)->prox;

	// guarda o começo da lista pra exibição
	while(inverte->prox != NULL){
//		printf("antes da troca\n");
//		printf("*lista = %d\n", inverte->info);
//		printf("aux->info = %d\n", aux->info);
		inverte->prox = aux->prox;
		aux->prox = inverte;
		aux->ant = inverte->ant;
		inverte->ant = aux;
		if(inverte->prox != NULL)
			inverte->prox->ant = inverte;

		if(aux->ant == NULL){
			printf("o if tá certo\n");
			*lista = aux;			
		} else {
			printf("else\n");
			inverte->ant = aux;
			aux->ant->prox = aux;
		}
		if(inverte->prox != NULL)
			aux = inverte->prox;
//		printf("depois da troca\n");
//		printf("inverte = %d\n", inverte->info);
//		printf("lista = %d\n", (*lista)->info);
//		printf("aux->info = %d\n", aux->info);
		exibe(lista);
	}

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
