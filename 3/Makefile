CC=gcc
CFLAGS= -Wall -g 
DEPS=Matrix.h Vector.h
OBJ=Matrix.o Vector.o main.o
LIBS=-lm
SRCS=main.c Vector.c Matrix.c
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

