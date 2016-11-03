/*
 * Arvores binarias de busca
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"


int main() {
  Arvore a;
  int i, num;

  iniciaArvore(&a);
  
  srand(time(NULL));
/*
  for (i = 0; i < 5; i++){
    num = rand()%50;
    printf("\ninsere: %d", num);
    if (insere(&a, num))
      printf(" OK");
    else
      printf(" ja tem");
  }
 
  for (i = 0; i < 5; i++){
    num = rand()%50;
    printf("\ninsere: %d", num);
    if (n_rec_insere(&a, num))
      printf(" OK");
    else
      printf(" ja tem");
  }
*/
  
  insere(&a, 18);
  insere(&a, 12);
  insere(&a, 39);
  insere(&a, 10);
  insere(&a, 13);
  insere(&a, 48);
  insere(&a, 17);
  insere(&a, 42);
  insere(&a, 14);
  insere(&a, 43);
  
  
  printf("\n\n");
  num = rand()%50;
/*
  printf("\nbusca: %d", num);
  if (busca(a, num))
    printf(" Encontrou");
  else
    printf(" Nao encontrou");
  num = rand()%50;
  printf("\nbusca: %d", num);
  */

  if (n_rec_busca(a, num))
    printf(" Encontrou");
  else
    printf(" Nao encontrou");


  printf("\nEm ordem: ");
  inorder(a);
  printf("\n");

  for (i = 0; i < 5; i++){
  	printf("\n\n remove: ");
  	scanf("%d", &num);
  	remove_arv(&a, num);
  }
  printf("\nEm ordem: ");
  inorder(a);
  printf("\n");
  

  //libera(a);
  return 0;

}
    
