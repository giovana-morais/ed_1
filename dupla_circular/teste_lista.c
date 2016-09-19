/*
 * Programa para testar as operações de lista
 */

#include<stdio.h>
#include "lista_dupla.h"

int main(){
  int num, opcao;
  Lista l;

  inicLista(&l);
  
  opcao = 1;  
  while(opcao <= 10 && opcao > 0){
    printf("\n 1 - insere um numero no inicio da lista");
    printf("\n 2 - insere um numero no fim da lista");
    printf("\n 3 - insere um numero de maneira ordenada");
    printf("\n 4 - verifica se a lista esta ordenada");
    printf("\n 5 - ordena a lista");
    printf("\n 6 - remove o elemento que esta no inicio da lista");
    printf("\n 7 - remove o elemento que esta no fim da lista");
    printf("\n 8 - remove um valor determinado");
    printf("\n 9 - inverte");
    printf("\n 10 - exibe a lista");
    printf("\n qualquer outro numero para sair");
    printf("\n\nEntre com uma das opcoes acima: ");
    scanf("%d", &opcao);
    
    switch (opcao){
    case 1:
      printf("\n\nEntre com o numero a ser inserido: ");
      scanf("%d", &num);
      insereInicio(&l, num);
      break;      
    case 2:
      printf("\n\nEntre com o numero a ser inserido: ");
      scanf("%d", &num);
      insereFim(&l, num);
      break;
    case 3:
      printf("\n\nEntre com o numero a ser inserido: ");
      scanf("%d", &num);
//      insereOrdenado(&l, num);
      break;
    case 4: 
//     if (ordenada(&l))
//	printf("\nLista ordenada\n");
//      else
//	printf("\nLista desordenada\n");
      break;
    case 5: 
//      ordena(&l);      
      break;
    case 6:
      if (removeInicio(&l, &num))
	printf("\nNumero removido: %d\n", num);
      else
	printf("\nLista vazia");
      break;
    case 7:
      if (removeFim(&l, &num))
	printf("\nNumero removido: %d\n", num);
      else
	printf("\nLista vazia");
      break;
    case 8:
      printf("\n\nEntre com o numero a ser removido: ");
      scanf("%d", &num);
//      if (!removeValor(&l, num))
//	printf("Numero nao encontrado");
      break;      
    case 9: 
//      inverte(&l);
      break;            
    case 10: exibe(&l); 
	break;
    }
    
    exibe(&l);
    printf("\n\n");    

  }    
    //    libera(&l);
  return 0;
}
