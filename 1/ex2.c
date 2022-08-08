#include <stdlib.h>
#include <stdio.h>

#define MAXSTR 80

double eval_poly_at_point(double a, double b, double c, double d, double x);

int main(){

	char buffer[MAXSTR];
	printf("This program evalutaes a second degree polynomial on a give point.\n");
	double a,b,c,d,x;
	do {
		printf("Input parameters a, b, c, d and x:");
		scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &x);

		printf("Result: %lf\n", eval_poly_at_point(a,b,c,d,x));
		
		fflush(stdin);
		printf("Another go? (y/n)");
		fgets(buffer, MAXSTR, stdin);
	
	} while(buffer[0]=='y' || buffer[0]=='Y');


	return 0;
}


double eval_poly_at_point(double a, double b, double c, double d, double x){
	return d + x * (c + x * (b + a * x));
}

