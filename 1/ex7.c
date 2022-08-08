#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"


void quadratic_solution(double a, double b, double c);

int main(){
	double a, b, c;
	printf("Input a, b, c:");
	scanf("%lf %lf %lf", &a, &b, &c);
	quadratic_solution(a,b,c);
	return 0;
}

void quadratic_solution(double a, double b, double c){
	double delta = b*b - 4*a*c;
	if(delta>0){
		double sol1 = (-b + sqrt(delta))/(2.*a);
		double sol2 = (-b - sqrt(delta))/(2.*a);
		printf("L'équation admet 2 solutions: %f et %f\n", sol1, sol2);
	}
	else if(delta==0){
		double solution = -b/(2.*a);
	       printf("L'équation admet 1 solution: %f\n", solution);	
	}
	else {
		Complex sol1, sol2;
	       	sol1.re = -b/(2.*a);
		sol1.im = sqrt(fabs(delta))/(2.*a);
		sol2.re=sol1.re;
		sol2.im= -sqrt(fabs(delta))/(2.*a);

		printf("L'équation admet 2 solutions complexes: (%f, %f), (%f, %f)\n", sol1.re, sol1.im, sol2.re, sol2.im);
	}
}
