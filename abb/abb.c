/*
 * Arvores binarias de busca.
 */


#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void iniciaArvore(Arvore *p){
	*p = NULL;
}

void inorder(Arvore p) {
	if (p != NULL) {
		inorder (p->esq);
		printf("%d ", p->info);    
		inorder (p->dir);    
	}
}

/* Retorna 1 se a chave for encontrada */
int busca(Arvore p, int chave){
	if(p == NULL)
		return 0;
	if((p->info == chave))
		return 1;
	else if(chave > p->info)
		return busca(p->dir, chave);
	else if(chave < p->info)
		return busca(p->esq, chave);
}

/* Retorna 1 se a chave for encontrada */
// versao nao recursiva
int n_rec_busca(Arvore p, int chave){
	while(p != NULL){
		if(chave > p->info)
			p = p->dir;
		else if(chave < p->info)
			p = p->esq;
		else if(chave == p->info)
			return 1;
	}	
	return 0;
}

/* Retorna 0 se a chave for repetida */
int insere(Arvore *p, int chave){
	No *novo;
	if(*p == NULL){
		novo = malloc(sizeof(No));
		novo->info = chave;
		novo->esq = NULL;
		novo->dir = NULL;
		*p = novo;
		return 1;
	}

	if(chave > (*p)->info)
		return insere(&(*p)->dir, chave);
	else if(chave < (*p)->info)
		return insere(&(*p)->esq, chave);
	else
		return 0;
}

/* Retorna 0 se a chave for repetida */
/* Vers�o n�o recursiva */
int  n_rec_insere(Arvore *p, int chave){
	No *novo;
	while(*p != NULL){
		if(chave > (*p)->info)
			p = &(*p)->dir;
		else if(chave < (*p)->info)
			p = &(*p)->esq;
		else 
			return 0;
	}
	novo = malloc(sizeof(No));
	novo->info = chave;
	novo->dir = NULL;
	novo->esq = NULL;
	*p = novo;
	return 1;
}


/* Retorna 0 se a chave nao for encontrada */
int remove_arv(Arvore * p, int chave) {
	No **aux, **sub, *auxsub, *rem;
	aux = p;
	
	while(*aux != NULL && (*aux)->info != chave){
		if(chave > (*aux)->info)
			aux = &((*aux)->dir);
		else
			aux = &((*aux)->esq);
	}
	
	if(*aux == NULL)
		return 0;

	rem = *aux;
//FOLHA:
	if((*aux)->esq == NULL && (*aux)->dir == NULL){
		*aux = NULL;
	}
//UNICO FILHO:
	else if((*aux)->esq == NULL && (*aux)->dir != NULL){
		*aux = rem->dir;
	} else if((*aux)->esq != NULL && (*aux)->dir == NULL){
		*aux = rem->esq;
	}
//DOIS FILHOS:
	else {
		sub = &((*aux)->dir);
		
		while((*sub)->esq != NULL)
			sub = &((*sub)->esq);
			
		auxsub = *sub;		
		*sub = auxsub->dir;
		auxsub->esq = rem->esq;
		auxsub->dir = rem->dir;
		*aux = auxsub;
	}	
	free(rem);
}

/* Verifica se p e uma arvore de busca */
int verifica_busca(Arvore p){
	
	return 0;
}



