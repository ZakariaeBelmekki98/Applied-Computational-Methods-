#include "Matrix.h"


void init_mat(Matrix *mat, int _rows, int _cols){
	mat->rows = _rows;
	mat->cols = _cols;
	mat->data = malloc(sizeof(double)*_rows*_cols);
}

Matrix add_mat(Matrix *mat1, Matrix *mat2){
	if(mat1->rows != mat2->rows || mat1->cols != mat2->cols){
		printf("Matrix::add_mat: M1 and M2 must be of same size.\n");
		exit(0);
	}
	Matrix result;
	result.rows = mat1->rows;
	result.cols = mat1->cols;
	result.data = malloc(sizeof(double)*result.rows * result.cols);
	for(int i=0; i<mat1->rows*mat1->cols; i++) result.data[i] = mat1->data[i] + mat2->data[i];
	return result;
}

void print_mat(Matrix *mat){
	for(int i=0; i<mat->rows*mat->cols; i++){
		printf("%f ", mat->data[i]);
		if((i+1)%mat->cols == 0) printf("\n");
	}
}
