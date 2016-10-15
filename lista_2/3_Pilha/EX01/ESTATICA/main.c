#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, *vetor, i;
	Pilha pilha;
	scanf("%d", &N);
	inicia_pilha(&pilha);

	aloca_mem(&pilha, N);

	for(i = 0; i < N; i++)
		empilha(&pilha, i);
	imprime_original(&pilha);
	imprime_reversa(&pilha);
	imprime_alternada(&pilha);
	imprime_original(&pilha);
}
