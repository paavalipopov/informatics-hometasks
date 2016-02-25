#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

#define MAX_MATRIX_NUMBER 10
//For linux it will be %zu
#define SIZE_T_FORMAT "%Iu"

int** generate_matrix(size_t height, size_t width);
int read_matrix_size(size_t *height, size_t *width);
void free_matrix(int **matrix, size_t height);
int test_matrix_generation();

#endif
