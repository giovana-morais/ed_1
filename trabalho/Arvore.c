#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include "defines.h"

void inicializaArvore(tree **xmas_tree){
	*xmas_tree = NULL;
}

/* insere o nó na árvore de RA */
int insereRA(tree **ra_tree, Aluno *aluno){
	tree *novo_no;
	
	if(*ra_tree == NULL){
		novo_no = malloc(sizeof(tree));
		novo_no->dir = NULL;
		novo_no->esq = NULL;
		novo_no->aluno = *aluno;
		*ra_tree = novo_no;
		return 1;
	}

	if(aluno->ra > (*ra_tree)->aluno.ra)
		return insereRA(&(*ra_tree)->dir, aluno);
	else if(aluno->ra < (*ra_tree)->aluno.ra)
		return insereRA(&(*ra_tree)->esq, aluno);
	else
		return 0;
}

int insereNome(tree **nome_tree, Aluno *aluno){
	tree *novo_no;
	
	if(*nome_tree == NULL){
		novo_no = malloc(sizeof(tree));
		novo_no->dir = NULL;
		novo_no->esq = NULL;
		novo_no->aluno = *aluno;
		*nome_tree = novo_no;
		return 1;
	}
	// fazer a comparação com o strcmp
	if(strcmp((*nome_tree)->aluno.nome, aluno->nome) < 0)
		return insereNome(&(*nome_tree)->dir, aluno);
	else if(strcmp((*nome_tree)->aluno.nome, aluno->nome) > 0)
		return insereNome(&(*nome_tree)->esq, aluno);
	else
		return 0;
}

void liberaArvore(tree **xmas_tree){
	if(*xmas_tree != NULL){
		liberaArvore(&(*xmas_tree)->esq);
		liberaArvore(&(*xmas_tree)->dir);
	} else {
		free(*xmas_tree);
	}
}

void salvarArvore(tree *xmas_tree, FILE *arquivo){
	if(xmas_tree != NULL){
		fprintf(arquivo, "%d#%d#%hu#%s\n", xmas_tree->aluno.ra, xmas_tree->aluno.ira, xmas_tree->aluno.ativo, xmas_tree->aluno.nome);
		salvarArvore(xmas_tree->esq, arquivo);
		salvarArvore(xmas_tree->dir, arquivo);
	} else 
		fprintf(arquivo, "#\n");
}

void carregarArvore(tree **xmas_tree, FILE *arquivo){
	char buffer[128];
	fgets(buffer, 128, arquivo);
	if(buffer[0] != '#'){
		tree *novo_no;
		novo_no = malloc(sizeof(tree));
		fscanf(arquivo, "%d#%d#%hu#%s", &novo_no->aluno.ra, &novo_no->aluno.ira, &novo_no->aluno.ativo, novo_no->aluno.nome);
		// atualiza a "raiz"
		*xmas_tree = novo_no;
		carregarArvore(&(*xmas_tree)->esq, arquivo);
		carregarArvore(&(*xmas_tree)->dir, arquivo);
	}
}

int listarNome(tree *nome_tree, char *nome_busca, int busca_suja){
	tree *retorno;
	
	retorno = buscaNome(nome_tree, nome_busca, busca_suja);	
	
	if(retorno == NULL)
		return 0;

	imprimirAluno(retorno->aluno);
	return 1;
}


void imprimirAluno(Aluno aluno){
	printf(ALUNO, aluno.nome, aluno.ra, aluno.ira);
}

tree* buscaRA(tree *ra_tree, int ra){
	if(ra_tree == NULL)
		return NULL;
	if(ra_tree->aluno.ra == ra)
		return ra_tree;
	else if(ra_tree->aluno.ra > ra)
		return buscaRA(ra_tree->dir, ra);
	else if(ra_tree->aluno.ra < ra)
		return buscaRA(ra_tree->esq, ra);
	else
		return NULL;
}


tree* buscaNome(tree *nome_tree, char *busca, int busca_suja){
	if(nome_tree == NULL)
		return NULL;
	if(busca_suja || nome_tree->aluno.ativo){
		if(strncmp(nome_tree->aluno.nome, busca, strlen(busca)) == 0)
			return nome_tree;
		else if(strncmp(nome_tree->aluno.nome, busca, strlen(busca)) < 0) 
			return buscaNome(nome_tree->dir, busca, busca_suja);
		else if(strncmp(nome_tree->aluno.nome, busca, strlen(busca)) > 0)
			return buscaNome(nome_tree->esq, busca, busca_suja);
	} 
	
	return NULL;
}

//remover essa fc depois
void inorder(tree **p){
	if(*p != NULL){
		inorder(&(*p)->esq);
		printf("%d#%d#%hu#%s", (*p)->aluno.ra,(*p)->aluno.ira,(*p)->aluno.ativo, (*p)->aluno.nome);
		inorder(&(*p)->dir);
	}
}

