CC=gcc
CFLAGS= -Wall -g 
DEPS=Matrix.h Vector.h Computational_utils.h Signal_processing.h IO.h
OBJ=Matrix.o Vector.o main.o Computational_utils.o Signal_processing.o IO.o
LIBS=-lm 
SRCS=main.c Vector.c Matrix.c Computational_utils.c Signal_processing.c IO.c
OBJS=$(SRCS:.c=.o)
MAIN=main

.PHONY: clean

all: $(MAIN)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

clean: 
	$(RM) *.o *~ $(MAIN)

