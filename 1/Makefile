CC=gcc
CFLAGS= -Wall -g 
DEPS=complex.h
OBJ=complex.o ex5.o
LIBS=-lm
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ex5: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
