/*
 * Árvores binárias
 */


#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//No* monta_arv_expr ();
No* monta_arv_expr (char s[], int *pos);


int main() {
  Arvore a, b;
  int i;
/* Cria a árvore           a
                          / \
						 b   c
					 	    /
					  	   d
          
*/
  a = arv('a',arv('b',NULL,NULL),arv('c',arv('d',NULL,NULL),NULL));

  b = copia(a);
  //printf("%x %x", a, b);

//  b = arv('a',arv('b',NULL,NULL),arv('c',NULL,NULL));
  printf("Pre: ");
  preorder(a);
  printf("\nEm: ");
  inorder(a);
  printf("\nPos: ");
  postorder(a);
  printf("\n\n");
  printf("Pre b: ");
  preorder(b);
  printf("\nEm b: ");
  inorder(b);
  printf("\nPos b: ");
  postorder(b);
  printf("\n\nLargura: ");
  largura(a);
  printf("\n\n");

  if (iguais(a,b))
    printf("arvores iguais\n\n");
  else
    printf("arvores diferentes\n\n");

  printf("Altura %d\n", altura(a));

  printf("Numero de nos %d\n", nNos(a));

  libera(&a);

  i = 0;
 /* a = monta_arv_expr("*+abc", &i);
  printf("Pre: ");
  preorder(a);
  printf("\nEm: ");
  inorder(a);
  printf("\nPos: ");
  postorder(a);
  printf("\n\n");
  libera(&b);*/
  
  return 0;
}
