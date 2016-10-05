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
// montar o switch depois	
	insereOrdenado(&lista, 7);
	insereOrdenado(&lista, 3);
	insereOrdenado(&lista, 5);	
	insereOrdenado(&lista, 1);
	insereOrdenado(&lista, 2);
	exibe(&lista);
//	imprimirNormal(lista);
}
