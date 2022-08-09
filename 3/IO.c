#include "IO.h"

void plot(double *data, size_t size){
	FILE *gnuplot = popen("gnuplot", "w");
	fprintf(gnuplot, "plot '-'\n");
	for(int i=0; i<size; i++) fprintf(gnuplot, "%g %g\n", i, data[i]);
	fprintf(gnuplot, "e\n");
	fflush(gnuplot);

}
