/*
 * Legenda:
 * e - enqueue. - Enfileira o próximo inteiro lido da entrada padrão.
 * d - dequeue. - Desenfileira um elemento da fila e joga na saída padrão.
 * f - fim. - Libera memória (Se houver) e finaliza o programa.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	char op;
	int N;
	Pilha pilha, aux;
	inicia_pilha(&pilha);
	inicia_pilha(&aux);
	aloca_mem(&pilha, 20);
	aloca_mem(&aux, 20);

	do{
		__fpurge(stdin);
		scanf("%c", &op);
		switch(op){
			case 'e':
				scanf("%d", &N);
				enqueue(&pilha, N);
				break;
			case 'd':
				dequeue(&pilha, &aux);
				break;
			case 'f':
				break;
			default:
				printf("opção inválida\n");
		}
	} while(op != 'f');
	
}
