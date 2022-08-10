#pragma once
#include "Matrix.h"
#include "Vector.h"
#include "IO.h"

Vector fit(Vector *v1, Vector *v2); // To develop later
Vector cramers_rule(Matrix *coefficients);
Vector jacobis_method(Matrix *a, Vector *b, size_t iter, const char filename[], size_t idx_output);
Vector gauss_seidel_method(Matrix *a, Vector *b, size_t iter, const char filename[], size_t idx_output);
void quadratic_interpolation(Vector *x, Vector *y, double upper_bound, double lower_bound, size_t samples);
