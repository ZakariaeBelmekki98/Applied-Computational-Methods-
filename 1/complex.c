#include "complex.h"


Complex complex_add(Complex *c1, Complex *c2){
	Complex result;
	result.im = c1->im+c2->im;
	result.re = c1->re+c2->re;
	return result;
}

Complex complex_div(Complex *c1, Complex *c2){
	Complex result;
	result.re = (c1->re*c2->re + c1->im*c2->im)/(c2->re * c2->re + c2->im * c2->im);
	result.im = (c1->im * c2->re - c1->re*c2->im)/(c2->re * c2->re + c2->im * c2->im);
	return result;
}

Complex complex_mult(Complex *c1, Complex *c2){
	Complex result;
	result.re= c1->re*c2->re - c1->im*c2->im;
	result.im= c1->re*c2->im + c1->im*c2->re;
	return result;
}

double magnitude(Complex *c){
	return sqrt(c->re* c->re + c->im * c->im);

}
