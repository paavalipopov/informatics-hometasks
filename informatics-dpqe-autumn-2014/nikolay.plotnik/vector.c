#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector* create_vector_ex(int size) {
	struct vector* out;
	if ((out = (struct vector*)calloc(1, sizeof(struct vector))) == NULL) {
		printf("Unable to allocate memory for vector structure\n");
		return NULL;
	}
	if ((out->arr = (vector_type*)calloc(size, sizeof(vector_type))) == NULL) {
		free(out);
		printf("Unable to allocate memory for vector elements\n");
		return NULL;
	}
    out->size = size;
    out->length = 0;
    return out;
}

struct vector* create_vector() {
    return create_vector_ex(DEFAULT_SIZE);
}

void free_vector(struct vector* out) {
	//Here we should free memory from each element.
    free(out->arr);
    free(out);
}

struct vector* add_value(struct vector* v, vector_type value) {
	vector_type* new_v = NULL;

    if(v->length == v->size) {
		v->size = 2 * v->length;
		if ((new_v = (vector_type*)realloc(v->arr, v->size * sizeof(vector_type))) == NULL) {
			printf("Unable to reallocate memory for vector\n");
			return NULL;
		}
		v->arr = new_v;
    }
	//Here should be called copy constructor for value
    v->arr[v->length++] = value;
    return v;
}

void print_vector(struct vector* v) {
    int i = 0;
	for (i = 0; i < v->length; i++) {
		//Here should be could str(data) to get string representation of object
		printf("%d element: %d\n", i, v->arr[i]);
	}
}
