CC = gcc
CFLAGS = -g -Wall

DEP = hello


ALL = main

all: $(ALL)

$(DEP).o: $(DEP).h $(DEP).c


$(ALL): $(DEP).o $(ALL).c

clean:
	rm -f *.o *~ $(ALL)
