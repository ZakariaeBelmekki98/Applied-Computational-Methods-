#include "Signal_processing.h"
#include "IO.h"

int main(){
	double arr[] = {1.23, -11, 3.45, -10.5, 5.3, -4};
	double *res = moving_avg_filter(arr, 6);
	plot(res, 6);	
	return 0;
}
