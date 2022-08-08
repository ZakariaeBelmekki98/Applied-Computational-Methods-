#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int factorial(long int n);
double sterlings_formula(int n);
double binomial(int n, int r);
double exp_series(double x);
double sum(double *input, int size);
double num_integ_pow2(int n);
double num_integ_exp(int y, int n);
void euler_cos(double t0, double tn, double y0, int n);
void euler_exp(int n);

int main(){
	int n, r;
	//printf("Input n: ");
	//scanf("%d", &n);
	//printf("%d! = %d | sterling's formula: %f\n", n,factorial(n), sterlings_formula(n));
	
	//printf("Input n and r: ");
	//scanf("%d %d", &n, &r);
	//printf("binomial: %f\n", binomial(n, r));
	
	//double x;
	//printf("Input x: ");
	//scanf("%lf", &x);
	//printf("Exp approx: %f | exp: %f \n", exp_series(x), exp(x));

	//double input[] = {1, 2, 3, 4};
	//printf("Sum: %f\n", sum(&input, 4));
	//int y;
	printf("Input n: ");
	scanf("%d", &n);
	//printf("Numerical integration result: %f, %f\n", num_integ_pow2(n), num_integ_exp(y, n));
	euler_exp(n);



	return 0;
}

void euler_exp(int n){
	double t0=0.0;
	double tn=1.0;
	double y0=0.5;

	double y_current, y_next;
	double h=(tn-t0)/(double)n;
	y_current=y0;
	inline double function(double x){
		return exp(-x*x/2.)/(sqrt(2*M_PI));
	}

	for(double i=t0; i<=tn; i=i+h){
		y_next=y_current+h* function(i);
		printf("Point: %f | Solution: %f\n", i, y_next);
		y_current = y_next;
	}
}

void euler_cos(double t0, double tn, double y0, int n){
	double y_current, y_next;
	double h = (tn-t0)/(double)n;
	y_current=y0;
	for(double i=t0; i<=tn; i=i+h){
		y_next=y_current+ h * cos(i);
		printf("Point: %f | Solution: %f\n", i, y_next);
		y_current=y_next;
	}

}

long int factorial(long int n){
	if(n==0) return 1;
	if(n<0) return 0;
	long int result = 1;
	
	while(n!=0){
		result*= n;
		n=n-1;
	}
	return result;
}

double sterlings_formula(int n){
	return sqrt(2*M_PI*n) * exp(-n) * pow(n,n);
}

double binomial(int n, int r){
	if(n-r < 0) return 0;
	return factorial(n) / (factorial(r) * factorial(n-r));
}

double exp_series(double x){
	double term=1.;
	double sum=1;
	int i= 1;
	while(term > 0.0001){
		term = pow(x, i)/ factorial(i);
		printf("%f\n", term);
		sum+=term;
		i++;
	}
	return sum;
}

double sum(double *input, int size){
	double sum=0.0;
	for(int i=0; i<size; i++){
		sum += input[i];
	}
	return sum;
}

double num_integ_pow2(int n){
	double step= 1./n;
	double sum= 1/2.;
	
	for(double i=step; i<1.; i=i+step) sum += i*i;
	return step * sum; 
}

double num_integ_exp(int y, int n){
	double step= (double)y/(double) n;
	inline double function(double x){return exp(-x*x/2.);}
	double sum = (function(y) - function(0))/2.;

	for(double i=step; i<y; i=i+step){sum += function(step); }
	return step * sum;
}

