#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_generation.h"

int** generate_matrix(size_t height, size_t width) {
    int** matrix;
	size_t row_index = 0;
	size_t column_index = 0;

    srand((unsigned int)time(NULL));

	if ((matrix = (int**)malloc(height*sizeof(int*))) == NULL) {
		printf("Can't allocate memory for " SIZE_T_FORMAT " rows\n", height);
        return NULL;
    }
	for (row_index = 0; row_index < height; row_index++) {
        if((matrix[row_index] = (int*)malloc(width*sizeof(int))) == NULL) {
			printf("Can't allocate memory for " SIZE_T_FORMAT " row\n", row_index + 1);
            free_matrix(matrix, row_index);     
            return NULL;
        }
        for(column_index = 0; column_index < width; column_index++) {
            matrix[row_index][column_index] = rand();
        }
    }

    return matrix;
}

void print_matrix(int** matrix, size_t height, size_t width) {
	size_t row_index = 0;
	size_t column_index = 0;

	for (row_index = 0; row_index < height; row_index++) {
		for (column_index = 0; column_index < width; column_index++) {
			printf("%d ", matrix[row_index][column_index]);
		}
		printf("\n");
	}
}

int read_matrix_size(size_t *height, size_t *width) {
    if (!feof(stdin) && scanf("%d %d", height, width) != 2) {
        printf("Can't read matrix size");
        return -1;
    }
	printf("Read matrix size: " SIZE_T_FORMAT " " SIZE_T_FORMAT " \n", *height, *width);
    return 0;
}

void free_matrix(int** matrix, size_t height) {
	size_t row_index;
	for (row_index = 0; row_index < height; row_index++) {
		free(matrix[row_index]);
    }
    free(matrix);
}

int test_matrix_generation() {
	int number_of_matrix = 0;
	int i = 0;
	size_t height = 0;
	size_t width = 0;
	int** matrix = NULL;

	srand((unsigned int)time(NULL));
	number_of_matrix = (rand() % MAX_MATRIX_NUMBER) + 1;

	printf("Generating %d matrixes...\n", number_of_matrix);

	for (i = 0; i < number_of_matrix; i++) {
		if (read_matrix_size(&height, &width) < 0)
			return -1;
		if ((matrix = generate_matrix(height, width)) == NULL) {
			return -1;
		}
		print_matrix(matrix, height, width);
		free_matrix(matrix, height);
	}
	return 0;
}
