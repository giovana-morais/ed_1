#include "header.h"
#include <stdio.h>

int main(){
  Fila f;
  int N, opc, num;

  inicFila(&f);
    while (1) {
      scanf("%d", &opc);
      switch (opc){
        case 1: scanf("%d", &num);
                insereFila(&f, num);
        break;
        case 2: N = removeFila(&f);
                fibonacci(&f, N);
        break;
        case 3: N = removeFila(&f);
                insereFila(&f, N);
        break;
        case 4: imprime(&f);
        break;
        case 5: inicFila(&f);
                return 0;
        break;
        default: printf("Opção inválida!\n");
      }
    }
}
