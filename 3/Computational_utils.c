#include "Computational_utils.h"

Vector cramers_rule(Matrix *coefficients){
	/* 
	 * Function: solves a system of equations using Cramer's rule
	 * 
	 * */
	Vector solutions;
	solutions.size = coefficients->cols-1;
	solutions.data = malloc(sizeof(double)*(coefficients->cols-1));
	Matrix a = rm_col(coefficients, coefficients->cols-1);
	double a_det = det(&a);
	for(int i=0; i<coefficients->cols-1; i++){
		Matrix tmp;
		matcpy(&tmp, &a);
		for(int j=0; j<a.rows; j++){
			tmp.data[i+j*a.rows] = coefficients->data[coefficients->cols-1 + j * (coefficients->cols)];
		}
		solutions.data[i] = det(&tmp) / a_det;
		print_mat(&tmp);
	}

	return solutions;
}

Vector jacobis_method(Matrix *a, Vector *b, size_t iter, const char filename[], size_t idx_output){
	if(a->rows != a->cols){
		printf("Computational_utils:jacobis_method: Matrix a must be square.\n");
		exit(1);
	}
	if(b->size != a->rows){
		printf("Computational_utils:jacobis_method: Size of Vector b incompatible with size of Matrix a.\n");
		exit(1);
	}
	if(idx_output > b->size){
		printf("Computational_utils:jacobis_method: idx_output out of range of Vector of solutions.\n");
		exit(1);
	}
	Vector next, current, output;
	next.data = calloc(a->rows, sizeof(double));
	current.data = calloc(a->rows, sizeof(double));
	next.size = a->rows;
	current.size = a->rows;
	if(filename != NULL){
		output.data = malloc(sizeof(double)*iter);
		output.size = iter;
	}
	for(int k=0; k<iter; k++){
		for(int i=0; i<b->size; i++){
			double sum = b->data[i];
			if(k!=0) for(int j=0; j<a->cols; j++) if(j!=i) sum -= a->data[i*a->cols+j] * current.data[j];
			next.data[i] = sum / a->data[i+a->rows*i];
		}
		if(filename != NULL) output.data[k]=next.data[idx_output];
		memcpy(current.data, next.data, sizeof(double)*b->size);
	}
	if(filename != NULL) {
		vec_to_dat(&output, filename, NULL);
		free_vec(&output);
	}
	free_vec(&current);
	return next;
}

Vector gauss_seidel_method(Matrix *a, Vector *b, size_t iter, const char filename[], size_t idx_output){
	if(a->rows != a->cols){
		printf("Computational_utils:gauss_seidel_method: Matrix a must be square.\n");
		exit(1);
	}
	if(b->size != a->rows){
		printf("Computational_utils:gauss_seidel_method: Size of Vector b incompatible with size of Matrix a.\n");
		exit(1);
	}
	if(idx_output > b->size){
		printf("Computational_utils:jacobis_method: idx_output out of range of Vector of solutions.\n");
		exit(1);
	}

	Vector next, current, output;
	next.data = calloc(a->rows, sizeof(double));
	current.data = calloc(a->rows, sizeof(double));
	next.size = a->rows;
	current.size = a->rows;
	if(filename != NULL){
		output.data = malloc(sizeof(double)*iter);
		output.size = iter;
	}

	for(int i=0; i<iter; i++){
		for(int j=0; j<b->size; j++){
			double sum = b->data[j];
			if(i!=0){
				for(int k=0; k<a->cols; k++){
					if(k<j) sum -= a->data[k+j*a->cols] * next.data[k];
					else if(k>j) sum -= a->data[k+j*a->cols] * current.data[k];
				}
			}
			next.data[j] = sum / a->data[j+a->rows*j];
		}
		if(filename!=NULL) output.data[i]=next.data[idx_output];
		memcpy(current.data, next.data, sizeof(double)*b->size);
	}
	if(filename != NULL) {
		vec_to_dat(&output, filename, NULL);
		free_vec(&output);
	}
	free_vec(&current);	
	return next;
}
