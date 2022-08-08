#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double im;
	double re;
} Complex;


Complex complex_mult(Complex *c1, Complex *c2);
Complex complex_add(Complex *c1, Complex *c2);
Complex complex_div(Complex *c1, Complex *c2);
double magnitude(Complex *c);
