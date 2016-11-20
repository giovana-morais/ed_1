#include <stdio.h>
#include "Arvore.h"
#include "defines.h"
#include "My_header.h"
#include <string.h>
#include <ctype.h>

Aluno lerAluno(){
	Aluno novo;
	int i = 0;
	char c, nome[64];

	printf(RA);
	scanf("%d%*c", &novo.ra);
	printf(NOME);
	scanf("%[^\n]s", nome);

	for(i = 0; i < 64; i++){
		c = toupper(nome[i]);
		novo.nome[i] = c;
		if(c == -1 || nome[i] == '\0')
			break;
	}

	printf(IRA);
	scanf("%d", &novo.ira);
	
	printf(STATUS);
	scanf("%hu", &novo.ativo);
	return novo;
}

void inicializa(Arvore *abb){
	inicializaArvore(&abb->nome_tree);
	inicializaArvore(&abb->ra_tree);
}

void cadastrar(Arvore *abb){
	//printf("lendo aluno\n");
	Aluno novo;
	novo = lerAluno();
//	printf("testando dados:\nnome = %s, ra = %d, ira = %d, status = %hu", novo.nome, novo.ra, novo.ira, novo.ativo);
	//printf("inserindo na arvore de ra\n");
	insereRA(&abb->ra_tree, &novo);
	//printf("inserindo na arvore de nome\n");
	insereNome(&abb->nome_tree, &novo);
}

void buscar(Arvore abb){
	int op, ra;
	char nome[32];
	tree *retorno;
	printf(BUSCAR);
	scanf("%d", &op);	
	switch(op){
		case 1:
			// busca por ra
			printf(RA);
			scanf("%d", &ra);
			retorno = buscaRA(abb.ra_tree, ra);
			printf("teste retorno: %d\n", retorno->aluno.ra); 
			if(retorno == NULL)
				printf(ALUNO_NAO_ENCONTRADO);
			else
				// retorno aqui
				printf(ALUNO, retorno->aluno.nome, retorno->aluno.ra, retorno->aluno.ira);
				
			break;
		case 2:
			// busca limpa por nome
			printf(NOME);
			scanf("%s", nome);
			retorno = buscaNome(abb.nome_tree, nome, 0);
			if(retorno == NULL)
				printf(ALUNO_NAO_ENCONTRADO);
			else
				// printar o retorno aqui
				printf(ALUNO, retorno->aluno.nome, retorno->aluno.ra, retorno->aluno.ira);
			
			break;
		case 3:
			// busca suja por nome
			printf(NOME);
		        scanf("%s", nome);
			retorno = buscaNome(abb.nome_tree, nome, 1);
			if(retorno == NULL)
				printf(ALUNO_NAO_ENCONTRADO);
			else 
				printf(ALUNO, retorno->aluno.nome, retorno->aluno.ra, retorno->aluno.ira);
			break;
		default:
			printf(OPCAO_INVALIDA);
			break;
	}
}

/* lista todos os alunos em ordem alfabética */
void listar(tree *xmas_tree, int busca_suja){
	// arrumar aqui pra tratar a busca suja
	if(xmas_tree != NULL){
		if(busca_suja || xmas_tree->aluno.ativo == 1){
			listar(xmas_tree->esq, busca_suja);
			printf(ALUNO, xmas_tree->aluno.nome, xmas_tree->aluno.ra, xmas_tree->aluno.ira);
			listar(xmas_tree->dir, busca_suja);
		}
	}
}

/* altera ira do aluno 
 * 	faz a busca
 * 	caso encontrado, altera ira e printa mensagem de sucesso
 * 	caso contrário, printa mensagem de erro */
void alterarIRA(Arvore abb){	
	int ra, novo_ira;
	tree *retorno;

	printf(RA);
	scanf("%d", &ra);
	// alterando a árvore de ra:
	retorno = buscaRA(abb.ra_tree, ra);
	if(retorno == NULL){
		//msg erro
		printf(ALUNO_NAO_ENCONTRADO);
		return;
	}
	printf(IRA);
	scanf("%d", &novo_ira);

	retorno->aluno.ira = novo_ira;
	printf(ALTERADO_COM_SUCESSO);
	
	// alterando a árvore de nome:
	retorno = buscaNome(abb.nome_tree, retorno->aluno.nome, 1);

	retorno->aluno.ira = novo_ira;
	printf(ALTERADO_COM_SUCESSO);
}

/* altera status do aluno 
 * 	faz a busca
 * 	caso encontrado, altera status e printa mensagem de sucesso
 * 	caso contrário printa mensagem de erro */
void des_ativarAluno(Arvore abb, int novo_status){
	tree *retorno;	
	int ra;

	printf(RA);
	scanf("%d", &ra);
	// alterando a árvore de ra:
	retorno = buscaRA(abb.ra_tree, ra);
	if(retorno == NULL){
		//msg erro
		printf(ALUNO_NAO_ENCONTRADO);
		return;
	}
	retorno->aluno.ativo = novo_status;
	printf(ALTERADO_COM_SUCESSO);
	
	// alterando a árvore de nome:
	retorno = buscaNome(abb.nome_tree, retorno->aluno.nome, 1);

	retorno->aluno.ativo = novo_status;
	printf(ALTERADO_COM_SUCESSO);
}

/* salva dados em arquivo.
 * 	arvore de nome: salvar em nome.dat
 * 	arvore de ra: salvar em ra.dat */
void salvar(Arvore abb){
	FILE *arquivo_ra, *arquivo_nome;
	
	arquivo_ra = fopen("ra.dat", "w");
	salvarArvore(abb.ra_tree, arquivo_ra);
	arquivo_nome = fopen("nome.dat", "w");
	salvarArvore(abb.nome_tree, arquivo_nome);

	fclose(arquivo_ra);
	fclose(arquivo_nome);
}

/* carrega dados do disco.
 * 	primeiro verifica se existem. 
 * 	se sim, carrega pra memória */
void carregar(Arvore *abb){
	FILE *arquivo_nome, *arquivo_ra;
	arquivo_nome = fopen("nome.dat", "r");
	arquivo_ra = fopen("ra.dat", "r");
	if(arquivo_nome == NULL || arquivo_ra == NULL){
		printf(ERRO_ABRIR_ARQUIVOS);
		return;
	}

	carregarArvore(&abb->ra_tree, arquivo_ra);
	carregarArvore(&abb->nome_tree, arquivo_nome);
	// preciso fechar aqui?
	fclose(arquivo_ra);
	fclose(arquivo_nome);
}

/* libera a memória antes de encerrar o programa */
void liberar(Arvore *abb){
	liberaArvore(&abb->ra_tree);
	liberaArvore(&abb->nome_tree);
//	free(abb);
}
