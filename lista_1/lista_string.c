/* biblioteca para implementação das funções listas com caracteres nos nós */
#include "lista_string.h"
#include <stdio.h>
#include <stdlib.h>

void inicStr(Str *lista){
	*lista = NULL;
}

int listaVazia(Str *lista){
	if(*lista == NULL) 
		return 1;
	return 0;
}


void insereInicio(Str *lista, char e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->info = e;

	novo_no->prox = *lista;
	*lista = novo_no;
}



void insereFim(Str *lista, char e){
	No_lista *novo, *aux;
	
	if(listaVazia(lista)){
		insereInicio(lista, e);
	} else {
		novo = malloc(sizeof(No_lista));
		novo->info = e;
		novo->prox = NULL;
		aux = *lista;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}

void exibe(Str *lista){
	No_lista *aux;
	aux = *lista;

	while(aux != NULL){
		printf("%c", aux->info);
		aux = aux->prox;
	}
	printf("\n");
}

/* retorna o tamanho das listas (strings)
 * 	se estiver vazia, o retorno é 0 */

int tamanho(Str *lista){
	int cont = 0;
	No_lista *aux;
	aux = *lista;
	if(listaVazia(lista))
		return 0;

	while(aux != NULL){
		cont += 1;
		aux = aux->prox;
	}

	return cont;
}


 
int compara(Str *lista_1, Str *lista_2){
	int cont = 0;
	No_lista *aux;
	
	aux = *lista_1;
	while(aux != NULL){
		cont -= aux->info;
		aux = aux->prox;
	}	

	aux = *lista_2;
	while(aux != NULL){
		cont += aux->info;
		aux = aux->prox;
	}
	
	return cont;	
}

void copia(Str *destino, Str *lista){
	No_lista *aux;

	aux = *lista;

	while(aux != NULL){
		insereFim(destino, aux->info);
		aux = aux->prox;
	}
}


/* concatena duas strings */
void concatena(Str *lista_1, Str *lista_2){
	No_lista *aux;

	aux = *lista_1;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = *lista_2;
}
