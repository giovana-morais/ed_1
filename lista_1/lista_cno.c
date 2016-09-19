#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista_cno.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l)
{
	p_l->prox = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l)
{
	if(p_l->prox==NULL) return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->info = e;
	novo_no->prox = p_l->prox;
	p_l->prox = novo_no;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo;
	
	novo = malloc(sizeof(No_lista));
	novo->info = e;
	novo->prox = NULL;
	
	while(p_l->prox != NULL)
		p_l = p_l->prox;
	p_l->prox = novo;

}


/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo;
	
	if (!ordenada(p_l))
		ordena (p_l);
	
	novo = (No_lista *)malloc (sizeof(No_lista));
	novo->info = e;
	
	while (p_l->prox != NULL && p_l->prox->info < novo->info){
		p_l = p_l->prox;
	}
	novo->prox = p_l->prox;
	p_l->prox = novo;
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	if (listaVazia(p_l))
		return 1;
		
	while (p_l->prox->prox != NULL){
		if (p_l->prox->info > p_l->prox->prox->info)
			return 0;
		p_l = p_l->prox;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	No_lista *desord, *aux, *novo;
	
	desord = p_l->prox;
	p_l->prox = NULL;
	while (desord != NULL){
		novo = desord;
		desord = desord->prox;
		aux = p_l;
		
		while (aux->prox != NULL && aux->prox->info < novo->info){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	
	if (listaVazia(p_l))
		return 0;

	aux = p_l->prox;
	*p_e = aux->info;
	//p_l->prox = aux->prox;
	p_l->prox = p_l->prox->prox;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	if (listaVazia(p_l))
		return 0;
	
//	while (p_l->prox->prox != NULL)
	while ((*(*p_l).prox).prox != NULL)
		p_l = p_l->prox;
		
	aux = p_l->prox;
	
	/*
	aux = p_l->prox;
	while(aux->prox != NULL){
		p_l = aux;
		aux = aux->prox;
	}
	*/
	
	p_l->prox = aux->prox;
	*p_e = aux->info;
	free(aux);

	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	No_lista *aux;
	int removeu = 0;
	
	if (listaVazia(p_l))
		return 0;

	aux = p_l->prox;
	while(aux != NULL){
		if (aux->info == e){
			p_l->prox = aux->prox;
			free(aux);
			removeu = 1;	
			aux = p_l->prox;
		}	
		else {
			p_l = p_l->prox;
			aux = p_l->prox;
		}
	}	
	
	return removeu; 
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *desord, *novo;
	
	desord = p_l->prox;
	p_l->prox = NULL;
	while (desord != NULL){
		novo = desord;
		desord = desord->prox;
		
		novo->prox = p_l->prox;
		p_l->prox = novo;
	}
	
}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	No_lista *aux;
	
	while (p_l->prox != NULL){
		aux = p_l->prox;
		p_l->prox = aux->prox;
		free (aux);
	}
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	while(p_l->prox != NULL){
		printf("%d ", p_l->prox->info);
		p_l = p_l->prox;
	}
}

/* Insere números aleatórios na lista */
void geraListaAleatoria(int N, Lista *p_l){
	int i, num;
	
	srand((unsigned) time(NULL));

	for(i = 0; i < N; i++){
		num = 1 + rand() % 99999;
		insereFim(p_l, num);
		
	}
}

/* Calcula média das infos de cada nó da lista
 *	 Retorna 0 se a lista estiver vazia */

float calculaMedia(Lista *p_l){
	int soma = 0;
	float media = 0.00;	
	No_lista *aux;

	aux = p_l->prox;
	if(listaVazia(p_l)){
		return 0;
	} 
	media = aux->info;
	if(aux->prox == NULL){
		return media;
	} else {
		while(aux->prox != NULL){
			soma++;
			media += aux->prox->info;
			aux = aux->prox;
		}
		soma++;	
		media = media / soma;
		return media;
	}
}

void mesclaListas(Lista *lista_1, Lista *lista_2){
	No_lista *aux, *aux2, *aux3, *aux4;;

/*	if(listaVazia(lista_1)){
		lista_1 = lista_2;
	} else if(listaVazia(lista_2)){
		lista_2	= lista_1;
	} else {
		return;
	}
*/
	aux = lista_1->prox;
	aux2 = lista_2->prox;

	if(aux2->prox != NULL)
		aux3 = aux2->prox;
	if(aux->prox != NULL)
		aux4 = aux->prox;
	
	if(aux->info >= aux2->info){
		lista_1->prox = aux2;
	} 
// arrumar pra quando
// 	a) a primeira lista for maior que a primeira
// 	b) o primeiro elemento da primeira lista for maior que da segunda
// 	c) sei lá, pensar em outros casos
//
	while(aux != NULL && aux3 != NULL ){
		if(aux->info >= aux2->info && aux->info <= aux3->info){
			aux2->prox = aux;
			aux2 = aux2->prox;
			aux = aux->prox;
			if(aux2->prox != NULL)
				aux2->prox = aux3;
			if(aux->prox != NULL)
				aux4 = aux->prox;
		} else if(aux->info < aux2->info){
			aux->prox = aux2;
			aux = aux4;
			if(aux->prox != NULL)
				aux4 = aux4->prox;
		} else if(aux->info > aux2->info && aux->info > aux3->info ){ 
			aux3->prox = aux;
			aux = aux->prox;
			aux2 = aux3;
			aux3 = aux3->prox;	
		} else {
			aux2 = aux3;
			aux3 = aux3->prox;
		}
		exibe(lista_1);	
		printf("\n");
	}
	if(aux2 == NULL && aux != NULL){
		printf("oi\n");
		aux2->prox = aux;
	}
}

void criarListaMesclada(Lista *lista_1, Lista *lista_2, Lista *nova_lista){
	No_lista *aux, *aux2;

	aux = lista_1->prox;
	aux2 = lista_2->prox;
	while(aux != NULL && aux2 != NULL){
		if(aux->info > aux2->info){
			insereFim(nova_lista, aux2->info);
			aux2 = aux2->prox;
		} else {
			insereFim(nova_lista, aux->info);
			aux = aux->prox;
		}
	}	

	while(aux != NULL){
		insereFim(nova_lista, aux->info);
		aux = aux->prox;
	}
	while(aux2 != NULL){
		insereFim(nova_lista, aux2->info);
		aux2 = aux2->prox;
	}
}

void leLista(Lista *lista){
	int N, i, item;

	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%d", &item);
		insereFim(lista, item);
	}
}
