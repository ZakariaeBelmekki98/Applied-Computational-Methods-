#include <stdlib.h>
#include <stdio.h>


typedef struct {
	double *data;
	int rows, cols;
} Matrix;


void init_mat(Matrix *mat, int rows, int cols);
void print_mat(Matrix *mat);
Matrix add_mat(Matrix *mat1, Matrix *mat2);
