#include "Vector.h"
#include "Matrix.h"

int main(){

	Matrix m1, m2;
	init_mat(&m1, 4, 3);
	init_mat(&m2, 3, 2);

	for(int i=0; i<12; i++)m1.data[i] = 1;
	for(int i=0; i<6; i++) m2.data[i] = 1;
	printf("Matrix 1: \n");
	print_mat(&m1);
	printf("Matrix 2: \n");
	print_mat(&m2);
	printf("Result: \n");
	Matrix m3 = multiply_mat(&m1, &m2);
	print_mat(&m3);
	printf("Transpose: \n");
	Matrix m4 = transpose(&m3);
	print_mat(&m4);

	printf("l1 norm: %f | l2 norm: %f | linf norm: %f \n", l1_norm_mat(&m4), l2_norm_mat(&m4), linf_norm_mat(&m4));
	return 0;
}
