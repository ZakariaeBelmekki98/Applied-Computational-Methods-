#include "Signal_processing.h"
#include "Computational_utils.h"


/*
 * Notes:
 * 	- The norms might be inversed in Matrix.c and Vector.c
 * 	- Change the functions to return pointers to Matrix objects not the objects themselves
 *
 * */

double newton_raphson(double x0, size_t iter);

inline double function(double x);

inline double dfunction(double x);

int main(){
	Vector x, y;
	double x_data[] = {3030, 5835, 8293};
	double y_data[] = {2418, 3365, 2872};
	init_vec(&x, 3, x_data);
	init_vec(&y, 3, y_data);

	quadratic_interpolation(&x, &y, 3030, 5000, 10);

	
//	struct plot_2D_data plot_args = {&x, &y};
//	plot(&plot_args);
//	sleep(20);
//	Vector sol = fit(&x, &y);
//	print_vec(&sol);

//	free_vec(&sol);
	free_vec(&x);
	free_vec(&y);

	return 0;
}

inline double function(double x){
	return x*x*x - 2*x*x - 5*x + 6;
}

inline double dfunction(double x){
	return 3*x*x - 4*x - 5;
}


double newton_raphson(double x0, size_t iter){
	double current, next;
	current=x0;
	next = 0;
	for(int i=0; i<iter; i++){
		next = current - function(current) / dfunction(current);
		current = next;
	}
	return next;
}
