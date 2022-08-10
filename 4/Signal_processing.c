#include "Signal_processing.h"

double *moving_avg_filter(double *data, size_t size){
	double fi = 0;
	double fe = 0;
	double * result = malloc(sizeof(double) * size);
	for(int i=0; i<size; i++){
		if(i == 0) result[i] = (fi + data[i] + data[i+1]) / 3.0;
		else if(i == size-1) result[i] = (data[i-1] + data[i] + fe) / 3.0; 
		else result[i] = (data[i-1] + data[i] + data[i+1]) / 3.0;
	}
	return result;
}
