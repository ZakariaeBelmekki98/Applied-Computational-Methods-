#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
	double *data;
	int rows, cols;
} Matrix;


void init_mat(Matrix *mat, size_t rows, size_t cols, double *data);
void print_mat(Matrix *mat);
Matrix add_mat(Matrix *mat1, Matrix *mat2);
Matrix multiply_mat(Matrix *mat1, Matrix *mat2);
Matrix transpose(Matrix *mat);
Matrix rm_row(Matrix *mat, int id);
Matrix rm_col(Matrix *mat, int id);
Matrix concat_mat(Matrix *mat1, Matrix *mat2); // to develop later
Matrix identity_mat(size_t size);
void matcpy(Matrix *mat1, Matrix *mat2);
double det(Matrix *mat);
double l1_norm_mat(Matrix *mat);
double l2_norm_mat(Matrix *mat);
double linf_norm_mat(Matrix *mat);
void free_mat(Matrix *mat);
