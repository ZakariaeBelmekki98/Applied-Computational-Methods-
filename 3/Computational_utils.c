#include "Computational_utils.h"

double *cramers_rule(Matrix *coefficients){
	/* 
	 * Function: solves a system of equations using Cramer's rule
	 * 
	 * */

	double *solutions = malloc(sizeof(double)*(coefficients->cols-1));
	Matrix A = rm_col(coefficients, coefficients->cols-2); 

}
