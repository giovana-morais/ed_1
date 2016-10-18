#include "header.h"
#include <stdio.h>

void inicFila(Fila *f){
  f->head = 0;
  f->tail = 0;
  f->tam = 0;
}

int filaVazia(Fila *f){
  if(f->tam == 0){
    return 1;
  }
  return 0;
}

int filaCheia(Fila *f){
  if(f->tam == MAX){
    return 1;
  }
  return 0;
}

void insereFila(Fila *f, int e){
  if(e > 0){
    if(!filaVazia(f)){
      f->tail++;
    }
    f->info[f->tail] = e;
    f->tam++;
  }
  else{
    printf("Número inválido\n");
  }
}

int removeFila(Fila *f){
  int n;
  if(!filaVazia(f)){
    n = f->info[f->head];
    f->head = (f->head + 1) % MAX;
    f->tam--;
  }
  return n;
}

void fibonacci(Fila *f, int e){
  int i;
  long int aux, n, fib;
  for(i = 1, aux = 0, n = 1; i < e; i++){
    if(i == 1){
      printf("%d ", n);
    }
    fib = aux + n;
    aux = n;
    n = fib;
    printf("%ld ", fib);
    if(i == e){
      insereFila(f, n);
    }
  }
  printf("\n");
}

void imprime(Fila *f){
  int i;
  for(i = f->head; i <= f->tail;){
    printf("%d ", f->info[i]);
    i = (i + 1) % MAX;
  }
  printf("\n");
}
