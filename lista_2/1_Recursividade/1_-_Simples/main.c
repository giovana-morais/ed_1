#include"header.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
  int opc, num;
  ll *list;

  inicLista(&list);
  while(1){
    printf("1-Insere Ordenado\n2-Imprime Normal\n3-Imprime Reverso\n4-Verifica Tamanho Lista\n5-Libera\n\n");
    scanf("%d", &opc);
    switch(opc){
      case 1:
        scanf("%d", &num);
        insereOrdenado(&list, num);
      break;
      case 2:
        imprimirNormal(list);
      break;
      case 3:
        imprimirReverso(list);
        printf("\n");
      break;
      case 4:
        printf("%d\n", tamanhodaLista(list));
      break;
      case 5:
        liberaRecursivo(&list);
      break;
      default: return 0;
      break;
    }
  }
}
