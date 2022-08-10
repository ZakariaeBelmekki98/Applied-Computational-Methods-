#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Vector.h"

struct plot_2D_data{
	Vector *x;
	Vector *y;
};

struct plots_args {
	size_t nb_plots; 
	char *filename;
	char *plot_type;
	struct plot_2D_data *plots;
};

void vec_to_dat(Vector *vec, const char filename[], const char col_name[]); 
void plot_2graphs(double *data1, double *data2, size_t size);
//void plot(double *data, size_t size);
void plot(struct plot_2D_data *data);

