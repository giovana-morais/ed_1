// Irei tirar 10 em ED1...
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX 1001

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
					break;
				}
				desempilha(&pilha);
			}
			if(c == EOF){
				flag = 1;
				break;
			}
			c = fgetc(stdin);
		}
			
		if(c == EOF){
			flag = 1;
			break;
		}

		if(!pilha_vazia(&pilha) && flag == 0)
			fputs("incorrect\n", stdout);
		else if(pilha_vazia(&pilha) && flag == 0)
			fputs("correct\n", stdout);
			
		
		
	}
	

return 0;
}
