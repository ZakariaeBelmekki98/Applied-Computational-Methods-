CC=gcc
CFLAGS= -Wall -g 
DEPS=Complex.h
OBJ=Complex.o ex29.o
LIBS=-lm
SRCS=main.c Complex.c 
DEPS=Complex.h
OBJS=$(SRCS:.c=.o)
MAIN=fourier

.PHONY: clean

all: $(MAIN)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

clean: 
	$(RM) *.o *~ $(MAIN)

