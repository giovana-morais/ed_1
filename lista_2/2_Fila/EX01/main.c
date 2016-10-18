#include "header.h"
#include <stdio.h>

int main(){
  int placa;
  char opc;
  fila f;
  inicFila(&f);
  //char d;
  while (1){
    //__fpurge(stdin);
    scanf("%c", &opc);
    //scanf("%c", &d);
    if(opc == 'i' && filaCheia(&f)){
      printf("Fila Cheia\n");
      return 0;
    }
      switch(opc){
      case 'i': scanf("%d", &placa);
                //printf("%d\n", placa );
                enfileiraCarro(placa, &f);
      break;
      case 'r': printf("%d\n", desenfileiraCarro(&f));
      break;
      default: break;
      break;
    }
    //printf("oie\n");
  }
}
