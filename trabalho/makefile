CC = gcc
CFLAGS = -g -Wall

ALL = main
DEP1 = Arvore
DEP2 = My_header

all: clean $(ALL)

$(ALL): $(DEP1).o $(DEP2).o $(ALL).c
$(DEP1).o: $(DEP1).h $(DEP1).c
$(DEP2).o: $(DEP2).h $(DEP2).c

clean: 
	rm -f *.o
	rm -f *~ $(ALL)

	
