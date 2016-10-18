#include "header.h"
#include <stdio.h>

void inicFila(fila *f){
  f->comeco = 0;
  f->fim = 0;
  f->tam = 0;
}
int filaCheia(fila *f){
  if(f->tam == MAX_CARROS){
    return 1;
  }
  return 0;
}
void enfileiraCarro(int placa, fila *f){
  if(f->tam == 0){
    f->tam++;
    f->placa[f->fim] = placa;
  }
  else if(!filaCheia(f)){
    f->fim = (f->fim + 1) % MAX_CARROS;
    f->tam++;
    f->placa[f->fim] = placa;
  }
}
int desenfileiraCarro(fila *f){
  int n;
  if(f->tam > 0){
    n= f->placa[f->comeco];
    f->comeco = (f->comeco + 1) % MAX_CARROS;
    f->tam--;
  }
  return n;
}
