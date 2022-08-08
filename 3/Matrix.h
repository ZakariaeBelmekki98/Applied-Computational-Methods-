#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double *data;
	int rows, cols;
} Matrix;


void init_mat(Matrix *mat, int rows, int cols);
void print_mat(Matrix *mat);
Matrix add_mat(Matrix *mat1, Matrix *mat2);
Matrix multiply_mat(Matrix *mat1, Matrix *mat2);
Matrix transpose(Matrix *mat);
double l1_norm_mat(Matrix *mat);
double l2_norm_mat(Matrix *mat);
double linf_norm_mat(Matrix *mat);
