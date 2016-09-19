#include <stdlib.h>
#include <stdio.h>
#include "lista_dupla.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	*p_l = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
	if(*p_l == NULL)
		return 1;
		
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo;
	
	novo = (No_lista *) malloc(sizeof(No_lista));
	novo->info = e;
	
	if(listaVazia(p_l)){
		novo->prox = novo;
		novo->ant = novo;
		*p_l = novo;
	} else {
		novo->prox = *p_l;
		novo->ant = (*p_l)->ant;
		(*p_l)->ant = novo;
		novo->ant->prox = novo;
		*p_l = novo;		
	}
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo;
	
	novo = (No_lista *) malloc(sizeof(No_lista));
	novo->info = e;
	
	if(listaVazia(p_l)){
		novo->prox = novo;
		novo->ant = novo;
		*p_l = novo;
	} else {
		novo->prox = *p_l;
		novo->ant = (*p_l)->ant;
		(*p_l)->ant = novo;
		novo->ant->prox = novo;
	}
}

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
		
	
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l);

/* Ordena a lista */
void ordena(Lista *p_l);

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;

	if(listaVazia(p_l))
		return 0;

	aux = *p_l;
	*p_e = aux->info;

	*p_l = (*p_l)->prox;
	(*p_l)->ant = aux->ant;
	aux->ant->prox = *p_l;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	
	if(listaVazia(p_l))
		return 0;
	else if((*p_l)->prox == *p_l){
		*p_e = (*p_l)->info;
		free(*p_l);
		*p_l = NULL;
	} else {
		printf("teste\n");
		aux = (*p_l)->ant;
		*p_e = aux->info;
		aux->ant->prox = *p_l;
		(*p_l)->ant = aux->ant;
		free(aux);
	}
	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e);

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l);

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	No_lista *aux;

	if(listaVazia(p_l))
		return;
	
	aux = (*p_l)->prox;;
	printf("%d ", (*p_l)->info);
	while(aux != *p_l){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");
}

/* Retorna o endereço do nó do meio da lista */
No_lista* meio(Lista *p_l){
	No_lista *esq, *dir;
	
	if(listaVazia(p_l))
		return NULL;
	esq = *p_l;
	dir = (*p_l)->ant;

	while(esq != dir || esq->prox != dir){
		esq = esq->prox;
		dir = dir->ant;
	}
	return esq;
}

/* Intercala 2 listas */
No_lista* intercalaListas(Lista *l1, Lista *l2){
	No_lista *l3, *novo;

	while(!listaVazia(l1) && !listaVazia(l2)){
		// remove de l1
		novo = *l1;
		*l1 = (*l1)->prox;
		(*l1)->ant = novo->ant;
		novo->ant->prox = *l1;
		// insere novo no fim de l3
		if(l3 == NULL){
			novo->prox = novo;
			novo->ant = novo;
			l3 = novo;	
		} else {
			novo->ant = l3->ant;
			novo->prox = l3;
			l3->ant->prox = novo;
			l3->ant = novo;

		}
		// remove de l2
		novo = *l2;
		*l2 = (*l2)->prox;
		(*l2)->ant = novo->ant;
		novo->ant->prox = *l2;
		// insere novo no fim de l3
		novo->ant = l3->ant;
		novo->prox = l3;
		l3->ant->prox = novo;
		l3->ant = novo;
	}

	while(!listaVazia(l1)){
		// remove de l1
		novo = *l1;
		*l1 = (*l1)->prox;
		(*l1)->ant = novo->ant;
		novo->ant->prox = *l1;
		// insere novo no fim de l3
		novo->ant = l3->ant;
		novo->prox = l3;
		l3->ant->prox = novo;
		l3->ant = novo;

	}

	while(!listaVazia(l2)){
		// remove de l2
		novo = *l2;
		*l2 = (*l2)->prox;
		(*l2)->ant = novo->ant;
		novo->ant->prox = *l2;
		// insere novo no fim de l3
		novo->ant = l3->ant;
		novo->prox = l3;
		l3->ant->prox = novo;
		l3->ant = novo;
	}
	return l3;
}

/* Intercala 2 listas ordenadas*/
No_lista* intercalaListasOrdenadas(Lista *l1, Lista *l2){
	No_lista *l3, *novo;

	while(!listaVazia(l1) && !listaVazia(l2)){
		// compara das listas qual o maior elemento
		if((*l1)->info > (*l2)->info){
			novo = *l2;
			*l2 = (*l2)->prox;
			(*l2)->ant = novo->ant;
			novo->ant->prox = *l2;
		} else {
			novo = *l1;
			*l1 = (*l1)->prox;
			(*l1)->ant = novo->ant;
			novo->ant->prox = *l1;
		}
		
		if(l3 == NULL){
			l3 = novo; 
			l3->prox = novo;
			l3->ant = novo;
		} else {
			novo->ant = l3->ant;
			novo->prox = l3;
			l3->ant->prox = novo;
			l3->ant = novo;
		}
	}
	while(!listaVazia(l1)){
		// remove de l1
		novo = *l1;
		*l1 = (*l1)->prox;
		(*l1)->ant = novo->ant;
		novo->ant->prox = *l1;
		// insere novo no fim de l3
		novo->ant = l3->ant;
		novo->prox = l3;
		l3->ant->prox = novo;
		l3->ant = novo;

	}

	while(!listaVazia(l2)){
		// remove de l2
		novo = *l2;
		*l2 = (*l2)->prox;
		(*l2)->ant = novo->ant;
		novo->ant->prox = *l2;
		// insere novo no fim de l3
		novo->ant = l3->ant;
		novo->prox = l3;
		l3->ant->prox = novo;
		l3->ant = novo;
	}
	return l3;
}
//#endif
