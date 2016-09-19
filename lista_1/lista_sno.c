#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista_sno.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	*p_l = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
	if(*p_l == NULL) 
		return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->info = e;

	novo_no->prox = *p_l;
	*p_l = novo_no;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo, *aux;
	
	if(listaVazia(p_l)){
		insereInicio(p_l, e);
	} else {
		novo = malloc(sizeof(No_lista));
		novo->info = e;
		novo->prox = NULL;
		aux = *p_l;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}


/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo;
	
	if (!ordenada(p_l))
		ordena (p_l);
	
	novo = (No_lista *)malloc (sizeof(No_lista));
	novo->info = e;
	
	while((*p_l)->prox != NULL && (*p_l)->prox->info < novo->info){
		*p_l = (*p_l)->prox;
	}
	novo->prox = (*p_l)->prox;
	(*p_l)->prox = novo;
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	if (listaVazia(p_l))
		return 1;
		
	while((*p_l)->prox->prox != NULL){
		if ((*p_l)->prox->info > (*p_l)->prox->prox->info)
			return 0;
		*p_l = (*p_l)->prox;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	No_lista *ord, *desord, *aux;	
	
		
	if(listaVazia(p_l) || (*p_l)->prox == NULL)
		return;
	
	desord = (*p_l)->prox;
	aux = desord->prox;
	(*p_l)->prox = NULL;

	while(desord != NULL){
		ord = *p_l;
		if(ord->info > desord->info){
			desord->prox = ord;
			*p_l = desord;
		} else {
			while(ord->prox != NULL && desord->info > ord->prox->info){
				ord = ord->prox;
			}
			desord->prox = ord->prox;
			ord->prox = desord;
		}
		
		desord = aux;
		if(aux != NULL)
			aux = aux->prox;
		
		/*
		if(ord->prox == NULL){
			desord->prox = ord->prox;
			ord->prox = desord;
			desord = aux;
			if(aux != NULL)
				aux = aux->prox;
				
		} else { 
			// inserindo em p_l
			desord->prox = ord->prox;
			ord->prox = desord;
			printf("lista ordenada:\n");
			exibe(&desord);	
			*p_l = desord;
			desord = aux;
			if(aux != NULL)
				aux = aux->prox;

		}
		
		*/
		
//		printf("lista desordenada:\n");
//		exibe(&desord);
	}
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
/*int removeInicio(Lista *p_l, elem_t *p_e){
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
*/ 
/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */

int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux, *aux2;

	aux = *p_l;
	aux2 = aux->prox;
	if (listaVazia(p_l))
		return 0;
	
	while(aux2->prox != NULL){
		aux = aux->prox;
		aux2 = aux2->prox;
	}

	*p_e = aux2->info;
	free(aux2);
	aux->prox = NULL;

/*
	aux = p_l->prox;
	while(aux->prox != NULL){
		p_l = aux;
		aux = aux->prox;
	}
*/
	

	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
/*
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
*/

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *aux, *inverte;

	inverte = *p_l;
	
	if(listaVazia(p_l) || inverte->prox == NULL){
		return;
	}
	*p_l = NULL;
	aux = inverte->prox;
	
	while(inverte->prox != NULL){
		inverte->prox = *p_l;
		*p_l = inverte;
		inverte = aux;
		aux = aux->prox;
	}	
	inverte->prox = *p_l;
	*p_l = inverte;
}

/* Remove todos os numeros da lista */
/*void libera(Lista *p_l){
	No_lista *aux;
	
	while (p_l->prox != NULL){
		aux = p_l->prox;
		p_l->prox = aux->prox;
		free (aux);
	}
}
*/ 
/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	No_lista *aux;
	aux = *p_l;

	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");
}

/* Insere números aleatórios na lista */
void geraListaAleatoria(int N, Lista *p_l){
	int i, num;
	
	//srand((unsigned) time(NULL));

	for(i = 0; i < N; i++){
		num = 1 + rand() % 9;
		insereFim(p_l, num);
		
	}
}

/* Calcula média 
 *	 Retorna 0 se a lista estiver vazia */

float calculaMedia(Lista *p_l){
	int soma = 0;
	float media = 0.00;	
	No_lista *aux;

	aux = *p_l;
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

No_lista* interseccao(Lista *lista_1, Lista *lista_2){
	No_lista *aux, *aux2, *aux3;
	Lista inter;

	inter = *lista_1;

	if(listaVazia(lista_1) || listaVazia(lista_2) || inter->prox == NULL)
		return NULL;
	
	*lista_1 = (*lista_1)->prox;
	inter->prox = NULL;
	aux = *lista_1;
	aux2 = *lista_2;
	aux3 = inter;
	while(aux != NULL && aux2 != NULL){
		if(aux->info > aux2->info)
			aux2 = aux2->prox;
		else if(aux2->info > aux->info)
			aux = aux->prox;
		else {
			//inserindo em inter
			aux3->prox = aux;
			aux = aux->prox;
			aux2 = aux2->prox;
			aux3 = aux3->prox;
			aux3->prox = NULL;
		}

	}
	exibe(&inter);
	return inter;
} 

void concatena(Lista *lista_1, Lista *lista_2){
	No_lista *aux;

	aux = *lista_1;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = *lista_2;
}

No_lista* divide(Lista *lista, elem_t e){
	No_lista *aux, *aux2;
	
	aux = *lista;

	if(listaVazia(lista) || aux->prox == NULL)
		return aux;

	aux2 = aux->prox;

	while(aux->prox != NULL){
		if(aux2->info == e){
			aux->prox = NULL;
			return aux2;
		} 
		aux = aux2;
		aux2 = aux2->prox;
		}
	return aux;
}

void transformaCircular(Lista *lista){
	No_lista *aux;

	while(aux->prox != NULL)
		aux = aux->prox;

	aux->prox = *lista;
}

No_lista* criaLista(int *v, int tamanho){
	int i;
	No_lista *lista;

	inicLista(&lista);

	for(i = 0; i < tamanho; i++){
		insereFim(&lista, v[i]);
	}

	return lista;
}

No_lista* soma(Lista *lista_1, Lista *lista_2){
	No_lista *aux, *aux2, *novo;
	int soma = 0;

	inicLista(&novo);

	aux = *lista_1;
	aux2 = *lista_2;

	while(aux != NULL && aux2 != NULL){
		//fazer a soma
		soma = aux->info + aux2->info;
		insereFim(&novo, soma);
		soma = 0;
		aux = aux->prox;
		aux2 = aux2->prox;
	}

	while(aux != NULL){
		soma = aux->info;
		insereFim(&novo, soma);	
		soma = 0;
		aux = aux->prox;
	}
	
	while(aux2 != NULL){
		soma = aux2->info;
		insereFim(&novo, soma);	
		soma = 0;
		aux2 = aux2->prox;
	}

	return novo;
}
