#include "Signal_processing.h"
#include "Computational_utils.h"
#include <unistd.h>


/*
 * Notes:
 * 	- The norms might be inversed in Matrix.c and Vector.c
 * 	- Change the functions to return pointers to Matrix objects not the objects themselves
 *
 * */

int main(){
	double a_coef[] = {6, -2, 1, 1,
	       		1, 10, 1, -6,
		       	1, 12, 24, 2, 
			0, 10, -1, 12};
	double b_coef[] = {9, 6, 1, -10};

	Matrix a;
	init_mat(&a, 4, 4, a_coef);

	Vector b;
	init_vec(&b, 4, b_coef);
	int iter = 100;
	Vector sol1 = jacobis_method(&a, &b, iter, "j1.dat", 1);
	printf("Jacobi's method solutions at iteration %d:\n", iter);
	print_vec(&sol1);
	Vector sol2 = gauss_seidel_method(&a, &b, iter, "gs1.dat", 1);
	printf("Gauss-Seidel's method solutions at iteration %d:\n", iter);
	print_vec(&sol2);
	free_vec(&sol1);
	free_vec(&sol2);
	free_mat(&a);
	free_vec(&b);
	return 0;
}
