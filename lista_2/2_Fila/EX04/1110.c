// Irei tirar 10 em ED1...
#include <stdio.h>
#include "fila.h"

int main(){
	int n, aux, i;
	Fila fila;
	inicFila(&fila);


	do{	
		scanf("%d", &n);
		if(n == 0)
			break;

		for(i = 1; i <= n; i++)
			insereFila(&fila, i);
		printf("Discarded cards: ");	
		for(i = 0; i < n - 1; i++){
			if(i == n - 2)
				printf("%d\n", removeFila(&fila));
			else
				printf("%d, ", removeFila(&fila));	
			aux = removeFila(&fila);
			insereFila(&fila, aux);
		}

		printf("Remaining card: %d\n", removeFila(&fila));

	} while(n != 0);
}
