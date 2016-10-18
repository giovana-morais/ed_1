#include <stdio.h>
#include "header.h"

void cria_pilhas(Pilha *pilha){
	pilha->topoA = 0;	
	pilha->topoB = MAX - 1;
}

void imprimeA(Pilha *pilha){
	int i;

	for(i = 0; i < pilha->topoA; i++)
		printf("%d ", pilha->vetor[i]);
	printf("\n");
}

void imprimeB(Pilha *pilha){
	int i;

	for(i = MAX - 1; i >= pilha->topoB; i--)
		printf("%d ", pilha->vetor[i]);
	printf("\n");

}

void empilhaA(Pilha *pilha, int num){
	if(cheia(pilha)){
		printf("pilha cheia\n");
		return;
	}
	pilha->vetor[pilha->topoA] = num;
	pilha->topoA++;
}

int cheia(Pilha *pilha){
	if(pilha->topoA == pilha->topoB)
		return 1;
	return 0;
}	

void desempilhaA(Pilha *pilha){
	if(vaziaA(pilha)){
		printf("pilha vazia\n");
		return;
	}
	pilha->topoA--;
}

void empilhaB(Pilha *pilha, int num){
	if(cheia(pilha)){
		printf("pilha cheia\n");
		return;
	}
	pilha->vetor[pilha->topoB] = num;
	pilha->topoB--;
}

void desempilhaB(Pilha *pilha){
	if(vaziaB(pilha)){
		printf("pilha vazia\n");
		return;
	}
	pilha->topoB++;
}

int vaziaA(Pilha *pilha){
	if(pilha->topoA == 0)
		return 1;
	return 0;
}

int vaziaB(Pilha *pilha){
	if(pilha->topoB == MAX - 1)
		return 1;
	return 0;
}
