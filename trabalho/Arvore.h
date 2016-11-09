#ifndef ARVORE_H
#define ARVORE_H
#include "defines.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* COMENTE SOBRE QUALQUER ALTERACAO NAS ESTRUTURAS DE DADOS ! */
typedef struct{
	int ra, ira;
	short ativo;
	char nome[64];
} Aluno;
typedef struct tree {
	Aluno aluno;
	struct tree *esq, *dir;
} tree;
FILE *arquivo;
void inicializaArvore(tree **xmas_tree);
int insereRA(tree **ra_tree, Aluno *aluno);
void insereNome(tree **nome_tree, Aluno *aluno);
tree* buscaRA(tree *ra_tree, int ra);
tree* buscaNome(tree *nome_tree, char *busca, int busca_suja);
// int listarNome(tree *nome_tree, char *nome_busca, int busca_suja); /* <-- imprimirAluno vai dentro*/
void liberaArvore(tree **xmas_tree);
void salvarArvore(tree *xmas_tree, FILE *arquivo);
void carregarArvore(tree **xmas_tree,FILE* arquivo);
void imprimirAluno(Aluno aluno);


#endif
