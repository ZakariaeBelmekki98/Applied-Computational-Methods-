#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double *data;
	int size;
} Vector;

void init_vector(Vector *vector, int _size);
Vector dot_product(Vector *v1, Vector *v2);
