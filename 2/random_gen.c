#include <stdlib.h>
#include <stdio.h>
#include <math.h>


long int* random_gen(int seed, int n);
long int min(long int* array, int size);
long int max(long int* array, int size);
double* normalize(long int* array, int size);

int main(){
	int seed;
	int n;
	printf("Input seed and n: ");
	scanf("%d %d", &seed, &n);
	long int* result = random_gen(seed, n);
	for(int i=0; i<n; i++) printf("%ld\n", result[i]);
	printf("Min: %ld | Max: %ld\n ", min(result, n), max(result, n));
	double* normalized_results = normalize(result, n);
	
	for(int i=0; i<n; i++) printf("%f\n", normalized_results[i]);
	free(result);
	return 0;
}


long int* random_gen(int seed, int n){
	
	long int* result = (long int*) malloc(sizeof(long int)*n);
	long int P = pow(2, 31);
	int r = 16807;
	result[0] = seed;
	for(int i=0; i<n-1; i++){
		result[i+1] = r * result[i] % P;
	}
	return result;
}

long int min(long int* array, int size){
	long int min = array[0];
	for(int i=1; i<size; i++){
		if(array[i] < min) min=array[i];
	}
	return min;
}

long int max(long int* array, int size){
	long int max=array[0];
	for(int i=1; i<size; i++) if(array[i]>max) max=array[i];
	return max;
}

double* normalize(long int* array, int size){
	double* normalized_arr = (double*)malloc(sizeof(double)*size);
	long int min_val = min(array, size);
	long int max_val = max(array, size);
	for(int i=0; i<size; i++) normalized_arr[i]= (array[i] - min_val)/ (double) (max_val-min_val);
	return normalized_arr;
}
