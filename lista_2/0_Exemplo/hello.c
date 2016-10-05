// Implementacao e variaveis globais das funcoes.
#include "hello.h"
#include <stdio.h>
int hellow()
{
  char nome[32];
  printf(PERGUNTA);
  scanf("%s",nome);
  printf(FRASE,nome);
  return 0;
}
