/* utilizando apenas as fçes disponibilizadas no header (não tem nenhuma lá) e pilhas auxiliares, faça um programa que, ao receber um inteiro N, gere uma sequência entre 1 e 3N e imprima:
 *	a seq em sua forma original
 *	a seq reversa
 *	a seq alternada entre paridade (n1, n3, n5... n2, n4, n6)
 *	a seq original de novo
 *	NÃO É PERMITIDO SALVAR UMA CÓPIA DA SEQ ORIGINAL 
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>

void gera_sequencia(Pilha *pilha, int N){
	int i;
	srand((unsigned) time(NULL));
	for(i = 0; i < N; i++){
		empilha(pilha, (1 + rand() % 3*N));		
	}
}

void inic_pilha(Pilha *pilha){
	pilha->prox = NULL;
}

int pilha_vazia(Pilha *pilha){
	if(pilha->prox == NULL)
		return 1;
	return 0;
}


/* insere no topo (começo) da pilha */
void empilha(Pilha *pilha, int num){
	No_pilha *novo;

	novo = (No_pilha*) malloc(sizeof(No_pilha));
	novo->num = num;
	novo->prox = pilha->prox;
	pilha->prox = novo;
}

int desempilha(Pilha *pilha){
	No_pilha *topo;
	int aux;
	if(pilha_vazia(pilha))
		return 0;
	topo = pilha->prox;       
	aux = topo->num;
	pilha->prox = topo->prox;
	free(topo);
	return aux;
}

void imprime_original(Pilha *pilha){
	if(pilha_vazia(pilha))
		return;
	if(pilha->prox != NULL){
		imprime_original(pilha->prox);
		printf("%d ", pilha->num);
	} else
		printf("%d ", pilha->num);
}

void imprime_reversa(Pilha *pilha){
	while(pilha != NULL){
		printf("%d ", pilha->num);
		pilha = pilha->prox;
	}
	printf("\n");
}

void muda_ordem(Pilha *pilha, Pilha *aux){
		
	while(pilha->prox != NULL){
		empilha(aux, desempilha(pilha));
	}
}

/* Exibe o conteudo da lista */
void exibe(Pilha *pilha){
	while(pilha->prox != NULL){
		printf("%d ", pilha->prox->num);
		pilha = pilha->prox;
	}
}

void separa(Pilha *pilha, Pilha *p1, Pilha *p2){
	while(pilha->prox != NULL){
		empilha(p1, desempilha(pilha));
		if(!pilha_vazia(pilha))
			empilha(p2, desempilha(pilha));
	}
}

void junta(Pilha *pilha, Pilha *p1, Pilha *p2){
	int aux;
	while(p1->prox != NULL){
		aux = desempilha(p1);
		printf("%d ", aux);
		empilha(pilha, aux);
	}
	while(p2->prox != NULL){
		aux = desempilha(p2);
		printf("%d ", aux);
		empilha(pilha, aux);
	}
}
