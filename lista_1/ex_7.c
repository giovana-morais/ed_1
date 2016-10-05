/* suponha que cadeias de caracteres são armazenadas em listas encadeadas com um caracter por nó. escreva funções análogas a strlen, strcmp, strcpy e strcat */

#include <stdio.h>
#include "lista_string.h"

int main(){
	Str str1, str2, str3, str4, teste;

	inicStr(&str1);
	inicStr(&str2);
	inicStr(&str3);
	inicStr(&str4);
	inicStr(&teste);

	insereFim(&str1, 'g');
	insereFim(&str1, 'i');
	insereFim(&str1, 'o');
	insereFim(&str1, 'v');
	insereFim(&str1, 'a');
	insereFim(&str1, 'n');
	insereFim(&str1, 'a');

	insereFim(&str2, 'o');
	insereFim(&str2, 'i');

	insereFim(&str3, 'o');
	insereFim(&str3, 'i');

	insereFim(&str4, 'O');
	insereFim(&str4, 'I');
/*
	printf("tamanho str1: %d\n", tamanho(&str1));
	printf("tamanho str2: %d\n", tamanho(&str2));

	concatena(&str1, &str2);
	exibe(&str1);

	copia(&teste, &str1);
	exibe(&teste);
*/
	// o primeiro print não deveria dar negativo?
	printf("compara 1 e 2: %d\n", compara(&str1, &str2));
	printf("compara 2 e 3: %d\n", compara(&str2, &str3));
	printf("compara 2 e 4: %d\n", compara(&str2, &str4));
	printf("compara 4 e 2: %d\n", compara(&str4, &str2));
}
