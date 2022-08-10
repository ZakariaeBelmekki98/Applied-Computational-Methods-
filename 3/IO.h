#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Vector.h"

void vec_to_dat(Vector *vec, const char filename[], const char col_name[]); 
void plot_2graphs(double *data1, double *data2, size_t size);

void plot(double *data, size_t size);
