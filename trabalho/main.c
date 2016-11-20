#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "Arvore.h"
#include "My_header.h"

int main(){
	int op, novo_status, busca_suja;
	Arvore abb;
	inicializa(&abb);
	do{
		printf(MENU);
		scanf("%d", &op);
		switch(op){
			case 1:
				//cadastrar
				cadastrar(&abb);
				break;
			case 2:
				//buscar
				buscar(abb);
				break;
			case 3:
				//alterar ira
				alterarIRA(abb);	
				break;
			case 4:
				//alterar status
				printf(STATUS);
				scanf("%d", &novo_status);
				des_ativarAluno(abb, novo_status);
				break;
			case 5:
				//listar
				scanf("%d", &busca_suja);
				listar(abb.nome_tree, busca_suja);
				break;
			case 6:
				//salvar em disco
				salvar(abb);
				break;
			case 7:
				//carregar do disco
				carregar(&abb);
				break;
			case 8:
				//liberar e sair
				liberar(&abb);
				break;
			default:
				printf(OPCAO_INVALIDA);
				break;
		}
	} while(op != 8);
}
