#pragma once
#include "Matrix.h"
#include "Vector.h"
#include "IO.h"


Vector cramers_rule(Matrix *coefficients);
Vector jacobis_method(Matrix *a, Vector *b, size_t iter, const char filename[], size_t idx_output);
Vector gauss_seidel_method(Matrix *a, Vector *b, size_t iter, const char filename[], size_t idx_output);
