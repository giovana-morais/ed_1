#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void inicFila(fila *pf){
  pf->tam = 0;
  pf->inicio = 0;
  pf->fim = 0;
}
int filaVazia(fila f){
  if(f.tam == 0){
    return 1;
  }
  return 0;
}
void enqueue(fila *pf,int n){
  if(filaVazia(*pf)){
		pf->tam++;
		pf->vetor[pf->fim] = n;
	}
	else if(pf->tam != ALGUM_NUMERO_GRANDE){
		pf->fim = (pf->fim+1) % ALGUM_NUMERO_GRANDE;
		pf->tam++;
		pf->vetor[pf->fim] = n;
	}
}
int dequeue(fila *pf){
  int n;
	if(!filaVazia(*pf)){
		n = pf->vetor[pf->inicio];
		pf->inicio = (pf->inicio+1) % ALGUM_NUMERO_GRANDE;
		pf->tam--;
	}
	return n;
}
void liberaFila(fila *pf){
  if(filaVazia(*pf)){
    printf("Pilha Vazia!\n");
  }
  else{
    inicFila(pf);
    liberaFila(pf);
  }
}

void push(fila *pf, int e){
  enqueue(pf, e);
}

int pop(fila *pf){
  unsigned aux;
  int n;
  if(filaVazia(*pf))
	  return 0;
  aux = pf->inicio;
  pf->inicio = pf->fim;
  pf->fim = aux;
  n = dequeue(pf);
  aux = pf->inicio;
  pf->inicio = pf->fim;
  pf->fim = aux;

  return n;
}
