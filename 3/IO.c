#include "IO.h"

void vec_to_dat(Vector *vec, const char filename[], const char col_name[]){
	FILE *output = fopen(filename, "w");
	if(col_name != NULL) fprintf(output,"index\t%s\n", col_name);
	for(int i=0; i<vec->size; i++) fprintf(output, "%d\t%f\n", i, vec->data[i]);
	fflush(output);
	fclose(output);
}

void plot(double *data, size_t size){
	FILE *gnuplot = popen("gnuplot", "w");
	fprintf(gnuplot, "plot '-' with lines\n");
	for(int i=0; i<size; i++) fprintf(gnuplot, "%d %f\n", i, data[i]);
	fprintf(gnuplot, "e\n");
	fflush(gnuplot);	
}

void plot_2graphs(double *data1, double *data2, size_t size){
	FILE *gnuplot = popen("gnuplot --persist", "w");
	fprintf(gnuplot, "plot '-' with lines, '-' with lines\n");

	for(int i=0; i<size; i++) fprintf(gnuplot, "%d %f\n", i, data1[i]);
	fprintf(gnuplot, "e\n");
	for(int i=0; i<size; i++) fprintf(gnuplot, "%d %f\n", i, data2[i]);
	fprintf(gnuplot, "e\n");
	fflush(gnuplot);

}
