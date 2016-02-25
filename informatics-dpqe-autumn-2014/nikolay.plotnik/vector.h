#ifndef VECTOR_H
#define VECTOR_H

#define vector_type int
#define DEFAULT_SIZE 10

struct vector {
	vector_type* arr;
	int size;
	int length;
};

struct vector* create_vector_ex(int size);
struct vector* create_vector();
void free_vector(struct vector* out);
struct vector* add_value(struct vector* v, vector_type value);
void print_vector(struct vector* v);

#endif
