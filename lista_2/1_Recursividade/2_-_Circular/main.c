/*
 i - Insere um número inteiro de maneira ordenada na lista.
 p 1 - Imprime a lista de maneira normal.
 p 2 - Imprime a lista de maneira reversa.
 c - Imprime o tamanho da lista na saída padrão.
 s - Sai do programa (e libera memória).
 */


#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	Lista l;
	int N;
	char op;
	
	inicLista(&l);
	
	do{
		__fpurge(stdin);
		scanf("%c", &op);
		switch(op){
			case 'i':
			      	scanf("%d", &N);
				if(listaVazia(&l))
					insereOrdenado(&l, NULL, N);
				else
					insereOrdenado(&l, l->prox, N);	      
				break;
			case 'p':
				scanf("%d", &N);
				if(N == 1)
					imprimirNormal(l, l->prox);
				else
					imprimirReverso(l, l->prox);
				break;
			case 'c':
				tamanhodaLista(l, l->prox);
			      	break;
			case 'f':
			     	break;
			default:
			   	printf("tudo errado");
				break;
		}
	} while(op != 'f');

	return 0;	
}
