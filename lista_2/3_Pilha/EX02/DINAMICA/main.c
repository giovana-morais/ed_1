#include "header.h"
#include <stdio.h>

int main(){
  char opc;
  Pilha p;
  elem_t n;
  inicPilha(&p);
  while(1){
    scanf("%c", &opc);
    switch(opc){
      case 'e': scanf("%d", &n);
                enqueue(&p, n);
      break;
      case 'd': printf("%d\n", dequeue(&p));
      break;
      case 'f': libera(&p);
                return 0;
      break;
    }
  }
}
