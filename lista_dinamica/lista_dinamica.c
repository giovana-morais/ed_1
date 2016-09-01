#include "lista_dinamica.h"
#include <stdlib.h>
#include <stdio.h>

void inicLista(Lista *p_l){
		p_l->prox = NULL;
}

int listaVazia(Lista *p_l){
	if(p_l->prox==NULL) 
		return 1;
	return 0;				
}

void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
		
	novo_no->info = e;
	novo_no->prox = p_l->prox;
	p_l->prox = novo_no;
}

void insereFim(Lista *p_l, elem_t e){
	No_lista *novo_no, *aux;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
		
	if(listaVazia(p_l)){
		insereInicio(p_l, e);
	} else {
		aux = p_l;
		novo_no->info = e;
		while(aux->prox != NULL){
			//caminhar na lista
			aux = aux->prox;
		}
		novo_no->prox = NULL;
		aux->prox = novo_no;
	}
}	

/* Insere um elemento na lista de maneira ordenada.
 *    Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *aux, *novo_no;
	
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	novo_no->info = e;	
	if(listaVazia(p_l))
		insereInicio(p_l, e);
	else if(ordenada(p_l))
		ordena(p_l);

	aux = p_l->prox;
	while(aux != NULL){
		if(e <= aux->info){
			novo_no->prox = aux;
			p_l->prox = novo_no;
			break;
		}	
		p_l = p_l->prox;
		aux = aux->prox;
	}
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	No_lista *aux;
	p_l = p_l->prox;
	aux = p_l->prox;
	while(aux->prox != NULL){
		if(p_l->info > aux->info){
			return 0;
			break;
		}
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	int maximo = 0;
	Lista *lista_ordenada;
	inicLista(lista_ordenada);
	
	while(!listaVazia(p_l)){
	// 1- procurando o máximo
		acha_max(p_l, &maximo);
	// 2- removendo os elementos e inserindo na lista nova
		removeValor(p_l, maximo);
		insereInicio(lista_ordenada, maximo);	
	}	
	// 3- p_l passa a ser a lista ordenada
	// (esse passo é necessário?)
	p_l = lista_ordenada;	
}

void acha_max(Lista *p_l, int *maximo){
	No_lista *aux;
	while(aux->prox != NULL){
		if(aux->info > *maximo)
			*maximo = aux->info;
	}
}
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	
	if(listaVazia(p_l))
		return 0;
	aux = p_l->prox;
	*p_e = aux->info;
	p_l->prox = aux->prox;
	//p_l->prox = p_l->prox->prox;
	free(aux);
	return 1;
}

int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	
	if(listaVazia(p_l))
		return 0;
	aux = p_l->prox;
	while(aux->prox != NULL){
		p_l = p_l->prox;
		aux = aux->prox;
	}
/*
	while(p_l->prox->prox != NULL){
	 	p_l = p_l->prox;
	}
	aux = p_l->prox;
 */
	*p_e = aux->info;
	p_l->prox == NULL;
	free(aux);

	return 1;
}

/* Remove o numero de valor e.
 *    Retorna 0 caso este numero não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	No_lista *aux;
	int removeu = 0;
	aux = p_l->prox;
	while(aux != NULL){
		if(aux->info == e){
			p_l->prox = aux->prox;
			free(aux);
			removeu = 1;
			aux = p_l->prox;
		} else {
			p_l = p_l->prox;
			aux = p_l->prox;
		}
	}

	return removeu;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	Lista *nova_lista;
	No_lista *novo_no, *aux;
	int elemento;

	novo_no = (No_lista*) malloc(sizeof(No_lista));
	inicLista(nova_lista);

	aux = p_l->prox;
	while(aux->prox != NULL){
		removeFim(p_l, &elemento);
		insereInicio(nova_lista, elemento);
		aux = aux->prox;
	}
		
}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	/*
	 * // opção 1
	 *	p_l->prox = NULL;
	 */

	// opção 2:
	No_lista *aux;
	aux = p_l->prox;
	while(aux->prox != NULL){
		free(aux);
		aux = p_l->prox;
	}
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	while(p_l->prox != NULL){
		printf("%d ", p_l->prox->info);
		p_l = p_l->prox;
	}
}
