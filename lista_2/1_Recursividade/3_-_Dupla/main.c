/*
 *
 * As funções devem ser implementadas no mesmo header do respectivo tipo de lista.
 * Uma main simples deve ser levada em conta para testar seguindo o seguinte critério:
 *
 * opções de entrada:
 * i - Insere um número inteiro de maneira ordenada na lista.
 * p 1 - Imprime a lista de maneira normal.
 * p 2 - Imprime a lista de maneira reversa.
 * c - Imprime o tamanho da lista na saída padrão.
 * s - Sai do programa (e libera memória).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	Lista lista;
	inicLista(&lista);
	char op;
	int num;

	do{
		__fpurge(stdin);
		scanf("%c", &op);
		switch(op){
			case 'i':
				scanf("%d", &num);
				insereOrdenado(&lista, num);
				break;
			case 'p':
				scanf("%d", &num);
				if(num == 1)
					imprimirNormal(lista);
				else if(num == 2)
					imprimirReverso(lista);
				else
					printf("opção inválida\n");
				break;
			case 'c':
			       printf("tamanho da lista: %d\n", tamanhodaLista(lista));
			       break;
			case 's':
			       break;
			default:
			       printf("opção inválida\n");
			       break;
		}
	} while(op != 's');
	liberaRecursivo(&lista);
}
