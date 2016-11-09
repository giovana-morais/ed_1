#ifndef HEADER_H
#define HEADER_H

#include "Arvore.h"

typedef struct {
	tree* nome_tree;
	tree* ra_tree;
} Arvore;
Aluno lerAluno();
void inicializa(Arvore *abb);
void cadastrar(Arvore *abb);
void buscar(Arvore abb);
void listar(tree *xmas_tree,int busca_suja);
void alterarIRA(Arvore abb);
void des_ativarAluno(Arvore abb, int novo_status);
void salvar(Arvore abb);
void carregar(Arvore *abb);
void liberar(Arvore *abb);
#endif
