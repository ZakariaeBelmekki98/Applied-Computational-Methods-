#include "Vector.h"

void init_vector(Vector *vector, int _size){
	vector->data = malloc(sizeof(double) * _size);
	vector->size = _size;
}

Vector dot_product(Vector *v1, Vector *v2){
	if(v1->size != v2->size){
		printf("Vector::dot_product: V1 and V2 must be of same size.\n");
		exit(1);
	}
	Vector result;
	result.size = v1->size;
	result.data = malloc(sizeof(double)*result.size);
	for(int i=0; i<result.size; i++){
		result.data[i] = v1->data[i] * v2->data[i];
	}
	return result;
}

double l1_norm(Vector *vector){
	double result=0;
	for(int i=0; i<vector->size; i++) {
		result += fabs(vector->data[i]);
	}
	return result;
}

double l2_norm(Vector *vector){
	double result = 0;
	for(int i=0; i<vector->size; i++){
		result += fabs(vector->data[i])*fabs(vector->data[i]);
	}
	return sqrt(result);
}

double linf_norm(Vector *vector){
	double max = vector->data[0];
	for(int i=0; i<vector->size; i++) {
		if(vector->data[i] > max) max = vector->data[i];
	}
	return max;
}

void print_vec(Vector *vector){
	for(int i=0; i < vector->size; i++){
		printf("%f\n", vector->data[i]);
	}
}
