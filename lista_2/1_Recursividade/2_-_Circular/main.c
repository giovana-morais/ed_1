#include "header.h"

int main(){
	Lista l;
	
	inicLista(&l);

//	insereOrdenado(&l, l, 3);
	insereOrdenado(&l, l, 4);
//	insereOrdenado(&l, l, 1);	
	insereOrdenado(&l, l, 5);
	insereOrdenado(&l, l, 2);	
	imprimirNormal(l, l);
}
