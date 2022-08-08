#define _USE_MATH_DEFINES
#include "Complex.h"
#include <math.h>

Complex* DFT(Complex *xk, int size);
Complex* IDFT(Complex *xk, int size);

int main(){
	double xk[]={1, 1, 1, 1, 0, 0, 0, 0};
	Complex *xn = malloc(8 * sizeof(Complex));
	int size=8;
	for(int i=0; i<size; i++){
		if(i<4) xn[i].re=1;
		else xn[i].re=0;
		xn[i].im=0;
	}

	Complex *dft = DFT(xn, size);
	printf("INVERSE \n");
	IDFT(dft, size);
	return 0;
}

Complex* DFT(Complex *xk, int size){
	Complex *result = malloc(size * sizeof(Complex));
	inline Complex term(Complex *x, int k, int n){
		Complex fourier_term;
		fourier_term.re = cos(-2*M_PI*k*n/size);
		fourier_term.im = sin(-2*M_PI*k*n/size);
		Complex result= c_multiply(x, &fourier_term);
		return result;
	}
	for(int i=0; i<size; i++){
		result[i].re=0;
		result[i].im=0;
		for(int j=0; j<size; j++){
			result[i].re += term(&(xk[j]), j, i).re;
			result[i].im += term(&(xk[j]), j, i).im;
		}
		c_print(&(result[i]));
	}

	return result;
}

Complex* IDFT(Complex *xk, int size){
	Complex * result = malloc(size*sizeof(Complex));
	inline Complex term(Complex *x, int k, int n){
		Complex fourier_term;
		fourier_term.re= cos(2*M_PI*k*n/size);
		fourier_term.im= sin(2*M_PI*k*n/size);
		return c_multiply(x, &fourier_term);
	}
	for(int i=0; i<size; i++){
		result[i].re=0;
		result[i].im=0;
		for(int j=0; j<size; j++){
			Complex tmp = term(&(xk[j]), j, i);
			result[i].re += tmp.re;
			result[i].im += tmp.im;
		}
		result[i].re = result[i].re / (double) size;
		result[i].im = result[i].im / (double) size;
		c_print(&(result[i]));
	}
	return result;
}

