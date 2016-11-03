#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *arv(elem_t c, No* esq, No* dir){
	No *novo;
	novo = malloc (sizeof(No));
	novo->info = c;
	novo->esq = esq;
	novo->dir = dir;
	return novo;
}

void preorder(No* p){
	if (p != NULL){
		printf("%c ", p->info);
		preorder(p->esq);
		preorder(p->dir);
	}
}

void inorder(No* p){
	if(p != NULL){
		inorder(p->esq);
		printf("%c ", p->info);	
		inorder(p->dir);	
	}
}

void postorder(No* p){
	if(p != NULL){
		postorder(p->esq);
		postorder(p->dir);
		printf("%c ", p->info);
	}
}

void largura(No* p){
	No* fila[50], *aux;
	int inic = 0, fim = 0;
	fila[fim++] = p;
	while (inic!= fim){
		aux = fila[inic++];
		printf("%c ", aux->info);
		if (aux->esq != NULL)
			fila[fim++] = aux->esq;
		if (aux->dir != NULL)
			fila[fim++] = aux->dir;
	}
}

void libera(Arvore* p){
}

No* copia(No* p){
}

int altura (No* p){
	if (p == NULL)
		return 0;
	
	int e, d;
	e = altura(p->esq);
	d = altura(p->dir);
	if (e > d)
		return (e+1);
	return (d+1);
}

int nNos (No* p){

}

int iguais(No* arv1, No* arv2){
	if (arv1 == NULL && arv2 == NULL)
		return 1;
	if (arv1 == NULL || arv2 == NULL)
		return 0;
	if (arv1->info != arv2->info)
		return 0;
	/*
	int e, d;
	e = iguais(arv1->esq, arv2->esq);
	d = iguais(arv1->dir, arv2->dir);
	if (e == 1 && d == 1)
		return 1;
	return 0;
	*/
	return iguais(arv1->esq, arv2->esq) && iguais(arv1->dir, arv2->dir);
}
		




