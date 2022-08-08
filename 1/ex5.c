#include "complex.h"

Complex frequency_response(double frequency);

int main(){
	

	printf("Frequency response function for feed back system\n");
	printf("************************************************\n");
	printf("Frequency     Real      Imaginary      Magnitude\n");
	for(double i=1.0; i<=10; i++){
		Complex response=frequency_response(i);
		printf(" %f       %f       %f         %f\n", i, response.re, response.im, magnitude(&response));
	
	}

	return 0;
}


Complex frequency_response(double fr){
	Complex c1, c2, top;
	c1.re=2;
	c1.im=fr;
	c2.re=0;
	c2.im=200;

	top=complex_mult(&c2, &c1);

	Complex c3, c4, c5, c6, c7, bot;
       	c3.im= fr*fr*fr;
	c3.re=0;
	
	c4.im=0.1*fr;
	c4.re=1;
	c5.im=0.3*fr;
	c5.re=1;
	c6.im=0.6*fr;
	c6.re=1;
	c7.im=0.8*fr;
	c7.re=1;

	Complex p1=complex_mult(&c3, &c4);
	Complex p2=complex_mult(&p1, &c5);
	Complex p3=complex_mult(&p2, &c6);
	bot=complex_mult(&p3, &c7);

	return complex_div(&top, &bot);	

}


