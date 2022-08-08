#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exponential(double x);
double error(double x);


int main(){
	
	double x;
	printf("Input x: ");
	scanf("%lf", &x);

	printf("Error = %lf | approx: %lf, C-exp(): %lf", error(x), exponential(x), exp(x));

	return 0;
}


double exponential(double x ){
	return 1+x*(1+x*(1./2. + x * (1./6. + x * (1./24. + x/120.))));
}

double error(double x){
	return fabs(exp(x) - exponential(x));
}


