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
	init_mat(&result, mat1->rows, mat1->cols);
	for(int i=0; i<mat1->rows*mat1->cols; i++) result.data[i] = mat1->data[i] + mat2->data[i];
	return result;
}

Matrix multiply_mat(Matrix *mat1, Matrix *mat2){
	if(mat1->cols != mat2->rows){
		printf("Matrix::multiply_mat:: M1.cols must be equal to M2.rows.\n");
		exit(1);
	}
	Matrix result;
	init_mat(&result, mat1->rows, mat2->cols);
	for(int i=0; i < result.rows*result.cols; i++){
		result.data[i]=0.0;
		int r= i % result.cols;
		int d= i / mat2->cols;
		for(int j=0; j < mat1->cols; j++){
			//printf("data[%d] += [%d]*[%d]\n", i, d+j, j*mat2->cols+r);
			result.data[i]+= mat1->data[d+j]*mat2->data[j*mat2->cols+r];
		}
	}
	return result;

}

Matrix transpose(Matrix *mat){
	Matrix result;
	init_mat(&result, mat->cols, mat->rows);
	for(int i=0; i<result.rows*result.cols; i++){
		int d=i/mat->rows;
		int r=i%mat->cols;
		result.data[i]= mat->data[d + r * mat->cols];
	}
	return result;
}

double l1_norm_mat(Matrix *mat){
	double result = 0;
	for(int i=0; i<mat->cols; i++){
		double tmp = 0;
		for(int j=0; j<mat->rows; j++) tmp+= fabs(mat->data[i*mat->cols+j*mat->rows]);
		if(tmp > result) result=tmp;
	}
	return result;

}

double l2_norm_mat(Matrix *mat){
	double result = 0;
	for(int i=0; i<mat->rows*mat->cols; i++) result += fabs(mat->data[i])*fabs(mat->data[i]);
	return sqrt(result);
}

double linf_norm_mat(Matrix *mat){
	double result = 0;
	for(int i=0; i<mat->rows; i++){
		double tmp = 0;
		for(int j=0; j < mat->cols; j++){
			tmp += fabs(mat->data[i*mat->cols+j*mat->rows]);
			if(tmp > result) result=tmp;

		}
	}
	return result;
}

void print_mat(Matrix *mat){
	for(int i=0; i<mat->rows*mat->cols; i++){
		printf("%f ", mat->data[i]);
		if((i+1)%mat->cols == 0) printf("\n");
	}
}
