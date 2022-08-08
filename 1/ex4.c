#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double gaussian_density(double x);

int main(){

	printf("Standard Gaussian density function\n");
	printf("**********************************\n");	
	printf("value of x              value of y\n");
	for(double i=0.; i<1.0; i=i+0.1){
		printf("%lf                %lf\n ", i, gaussian_density(i));
	}

	return 0;
}


double gaussian_density(double x){
	return (1./(2. * M_PI)) * exp(x * x / 2.); 
}
