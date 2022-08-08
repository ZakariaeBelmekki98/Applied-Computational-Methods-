CC=gcc
CFLAGS= -Wall -g 
DEPS=Complex.h
OBJ=Complex.o ex3.o
LIBS=-lm
SRCS=main.c Vector.c 
DEPS=Vector.h
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

