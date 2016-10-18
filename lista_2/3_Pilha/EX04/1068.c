#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	char c;
	int i, flag;
	Pilha pilha;
	
	inicia_pilha(&pilha);
	aloca_mem(&pilha, 10);
	while(1){
		inicia_pilha(&pilha);
		c = getc(stdin);
		flag = 0;
		while(c != '\n'){
			if(c == '('){
				empilha(&pilha, c);
			} else if(c == ')'){
				if(pilha_vazia(&pilha)){
					fputs("incorrect\n", stdout);
					flag = 1;
				} else 
					desempilha(&pilha);
			}
			if(c == EOF){
				flag = 1;
				break;
			}
			c = fgetc(stdin);
		}
			
		if(c == EOF){
			break;
		}

		if(!pilha_vazia(&pilha) && flag == 0)
			fputs("incorrect\n", stdout);
		else if(pilha_vazia(&pilha) && flag == 0)
			fputs("correct\n", stdout);
	}
	

return 0;
}
