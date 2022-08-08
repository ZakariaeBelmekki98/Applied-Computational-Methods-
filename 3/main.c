#include "Vector.h"


int main(){
	Vector v1;
	Vector v2;

	init_vector(&v1, 3);
	init_vector(&v2, 3);

	v1.data[0]=2;
	v1.data[1]=0;
	v1.data[2]=1;
	v2.data[0]=2;
	v2.data[1]=0;
	v2.data[2]=1;

	Vector result; 
	result = dot_product(&v1, &v2);
	for(int i=0;i<3;i++) printf("%f\n", result.data[i]);
	return 0;
}
