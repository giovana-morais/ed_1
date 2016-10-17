/* duas pilhas A e B podem compartilhar o mesmo vetor. faça as declarações de constantes e tipos necessários e escreva as seguintes rotinas:
 * 	o procedimento criaPilhas que inicia os valores de topoA e topoB
 * 	as funções vaziaA e vaziaB
 * 	os procedimentos empilhaA, empilhaB, desempilhaA, desempilhaB
 *
 * 	só deve ser emitida uma mensagem de pilha cheia se todas as posições do vetorestiverem ocupadas 
 * 	sobre o menu de entrada desse programa considere as seguintes opcões:
 * 	a - Insere elemento em a.
 * 	b - Insere elemento em b.
 * 	c - Remove um elemento de a.
 * 	d - Remove um elemento de b.
 * 	p - imprime as 2 pilhas
 * 	f - Encerra o programa e libera memória se houver
*/

#include <stdio.h>
#include "header.h"

int main(){
	Pilha pilha;
	char op;
	int num;

	cria_pilhas(&pilha);	
	do{
		__fpurge(stdin);
		scanf("%c", &op);
		switch(op){
			case 'a':
				scanf("%d", &num);
				empilhaA(&pilha, num);
				break;
			case 'b':
				scanf("%d", &num);
				empilhaB(&pilha, num);
				break;
			case 'c':
				desempilhaA(&pilha);
				break;
			case 'd':
				desempilhaB(&pilha);
				break;
			case 'p':
				imprimeA(&pilha);
				imprimeB(&pilha);
				break;
			case 'f':
				break;
			default:
				printf("opção incorreta\n");
				break;
		}

	} while(op != 'f');
return 0;
}
