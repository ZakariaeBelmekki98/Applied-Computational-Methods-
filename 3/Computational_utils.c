#include "Computational_utils.h"

double *cramers_rule(Matrix *coefficients){
	/* 
	 * Function: solves a system of equations using Cramer's rule
	 * 
	 * */

	double *solutions = malloc(sizeof(double)*(coefficients->cols-1));
	Matrix a = rm_col(coefficients, coefficients->cols-1);
	printf("A: \n");
	print_mat(&a);
	double a_det = det(&a);
	for(int i=0; i<coefficients->cols-1; i++){
		Matrix tmp;
		matcpy(&tmp, &a);
		for(int j=0; j<a.rows; j++){
			tmp.data[i+j*a.rows] = coefficients->data[coefficients->cols-1 + j * (coefficients->cols)];
		}
		solutions[i] = det(&tmp) / a_det;
		printf("TMP %d\n", i);
		print_mat(&tmp);
	}

	return solutions;
}
