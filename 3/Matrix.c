#include "Matrix.h"


void init_mat(Matrix *mat, int _rows, int _cols, double *_data){
	mat->rows = _rows;
	mat->cols = _cols;
	mat->data = calloc(_rows*_cols, sizeof(double));
	if(mat->data == NULL){
		printf("Matrix::init_matrix: malloc() failed.\n");
		exit(1);
	}
	memcpy(mat->data, _data,sizeof(double)*_rows*_cols);
}

Matrix add_mat(Matrix *mat1, Matrix *mat2){
	if(mat1->rows != mat2->rows || mat1->cols != mat2->cols){
		printf("Matrix::add_mat: M1 and M2 must be of same size.\n");
		exit(0);
	}
	Matrix result;
	double *zeros= calloc(mat1->rows*mat1->cols, sizeof(double));
	init_mat(&result, mat1->rows, mat1->cols, zeros);
	for(int i=0; i<mat1->rows*mat1->cols; i++) result.data[i] = mat1->data[i] + mat2->data[i];
	return result;
}

Matrix multiply_mat(Matrix *mat1, Matrix *mat2){
	if(mat1->cols != mat2->rows){
		printf("Matrix::multiply_mat:: M1.cols must be equal to M2.rows.\n");
		exit(1);
	}
	Matrix result;
	double *zeros = calloc(mat1->rows*mat2->cols, sizeof(double));
	init_mat(&result, mat1->rows, mat2->cols, zeros);
	for(int i=0; i < result.rows*result.cols; i++){
		result.data[i]=0.0;
		int r= i % result.cols;
		int d= i / mat2->cols;
		for(int j=0; j < mat1->cols; j++){
			result.data[i]+= mat1->data[d+j]*mat2->data[j*mat2->cols+r];
		}
	}

	free(zeros);
	return result;

}

Matrix identity_mat(size_t size){
	Matrix result;
	result.rows = size;
	result.cols = size;
	result.data = calloc(size*size, sizeof(double));
	for(int i=0; i<size;i++) result.data[i*size+i] = 1;
	return result;
}

Matrix concat_mat(Matrix *mat1, Matrix *mat2){
	if(mat1->rows != mat2->rows){
		printf("Matrix::concat_mat: Mat1 and Mat2 must have the same number of columns.\n");
		exit(1);
	}
	Matrix result;
	result.rows = mat1->rows;
	result.cols = mat1->cols + mat2->cols;
	result.data = malloc(sizeof(double)*result.rows*result.cols);
	int counter1 = 0;
	int counter2 = 0;
	for(int i=0; i < result.cols*result.rows;i++){
		int r=i%result.cols;
		if(r>= mat1->cols){
			result.data[i] = mat2->data[counter2];
			counter2++;
		} 
		else {
			result.data[i] = mat1->data[counter1];
			counter1++;
		}
	}
	return result;

}

Matrix transpose(Matrix *mat){
	Matrix result;
	double *zeros = calloc(mat->rows*mat->cols, sizeof(double));
	init_mat(&result, mat->cols, mat->rows, zeros);
	for(int i=0; i<result.rows*result.cols; i++){
		int d=i/mat->rows;
		int r=i%mat->cols;
		result.data[i]= mat->data[d + r * mat->cols];
	}
	return result;
}

Matrix rm_row(Matrix *mat, int id){
	Matrix result;
	
	double *zeros = calloc((mat->rows-1)*mat->cols, sizeof(double));
	init_mat(&result, (mat->rows)-1, mat->cols, zeros);
	int j = 0;
	for(int i=0; i<mat->cols*mat->rows; i++){
		if(i/mat->cols != id){ 
			result.data[j] = mat->data[i];
			j++;
		}
	}
	return result;
}

Matrix rm_col(Matrix *mat, int id){
	Matrix result; 
	double *zeros = calloc((mat->cols-1)*mat->rows, sizeof(double));
	init_mat(&result, mat->rows, mat->cols-1, zeros);
	int j=0;
	for(int i=0; i<mat->rows*mat->cols; i++) {
		if(i%mat->cols != id) {
			result.data[j]=mat->data[i];
			j++;
		}
	}
	return result;
}

double det(Matrix *mat){
	double result = 0;
	int flag = 0;
	if(mat->rows == 2) return mat->data[0] * mat->data[3] - mat->data[1] * mat->data[2];
	for(int i=0; i<mat->cols; i++){
		Matrix sub_mat1 = rm_row(mat, 0);
		Matrix sub_mat2 = rm_col(&sub_mat1, i);
		if(flag==0){
			result += mat->data[i] * det(&sub_mat2);
			flag = 1;
		} else {
			result -= mat->data[i] * det(&sub_mat2) ;
			flag = 0;
		}
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

void free_mat(Matrix *mat){
	free(mat->data);
	mat->data = NULL;
}
