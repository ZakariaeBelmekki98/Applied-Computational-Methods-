#include "Computational_utils.h"


int main(){

	
	Matrix m1;
	double arr[] = {1, 12, 1, 2, 7, 6, 1.2, 12, 45};
	init_mat(&m1, 3, 3, arr);
	print_mat(&m1);
	printf("Det: %f\n", det(&m1));
	return 0;
}
