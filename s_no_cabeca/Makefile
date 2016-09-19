CC = gcc
CFLAGS = -g -Wall

# Coloque a implementação de vetor aqui...
ED = lista_dinamica

ALL = teste_lista

all: $(ALL)

$(ED).o: $(ED).h $(ED).c

teste_lista: $(ED).o teste_lista.c

clean:
	rm -f *.o *~ $(ALL)
