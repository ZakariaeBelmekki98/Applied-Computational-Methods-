#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	double *data;
	int size;
} Vector;


void init_vec(Vector *vector, size_t _size, double *data);
Vector dot_product(Vector *v1, Vector *v2);
double l1_norm(Vector *vector);
double l2_norm(Vector *vector);
double linf_norm(Vector *vector);
void print_vec(Vector *vector);
void free_vec(Vector *vec);
