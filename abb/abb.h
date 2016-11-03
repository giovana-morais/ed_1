/*
 * Árvores binárias de busca.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info; /* chave */
  struct no *esq, *dir;
} No;

typedef No* Arvore;

void iniciaArvore(Arvore *p);

void inorder(Arvore p);

/* Retorna 1 se a chave for encontrada */
int busca (Arvore p, int chave);

/* Retorna 1 se a chave for encontrada */
int n_rec_busca(Arvore p, int chave);

/* Retorna 0 se a chave for repetida */
int  insere(Arvore *p, int chave);

/* Retorna 0 se a chave for repetida */
/* Versão não recursiva */
int  n_rec_insere(Arvore *p, int chave);

/* Retorna 0 se a chave não for encontrada */
int remove_arv(Arvore *p, int chave);

/* Verifica se p é uma árvore de busca */
int verifica_busca(Arvore p);

