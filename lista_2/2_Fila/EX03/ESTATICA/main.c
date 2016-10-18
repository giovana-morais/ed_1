#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	char opc;
	int n;
	fila pilha;

 	do{
    		scanf("%c", &opc);
		switch(opc){
      			case 'u': 
				scanf("%d", &n);
                		push(&pilha, n);
				break;
			case 'p': 
				printf("%d\n", pop(&pilha));
				break;
			case 'f': 
				liberaFila(&pilha);
				break;
			}
	} while(opc != 'f');
	return 0;
}
