#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define allocate(n) (long*)calloc(n, sizeof(long));


void fill(long* array, long n);
long* merge_sort(long* array, long* buffer, long bottom, long top);
void print(long* array, long n);


int main(void) {
	long n = 1048576;
	long* array;
	long* buffer;

	printf("Number of elements is 10493952 ");

	array = allocate(n);
	buffer = allocate(n);
	if (array == NULL || buffer == NULL) {
		printf("Error with allocating memory");
		if(array != NULL)
            free(array);
        if(buffer != NULL)
            free(buffer);
		return -2;
	}

    fill(array, n);
	array = merge_sort(array, buffer, 0, n-1);

	print(array, n);

	free(array);

	return 0;
}


void fill(long* array, long n) {
    long i;
    FILE* file;
    file = fopen("text", "r");

    printf("Elements are taken form \"text\"\n");

    for(i = 0; i < n; i++)
        fscanf(file ,"%ld", array + i);

    fclose(file);
}

long* merge_sort(long* array, long* buffer, long bottom, long top) {
    if (bottom == top)
    {
        buffer[bottom] = array[bottom];
        return buffer;
    }

    long middle = (bottom + top) / 2;

    long* left_buffer = merge_sort(array, buffer,  bottom, middle);
    long* right_buffer = merge_sort(array, buffer, middle + 1, top);

    long* target = (left_buffer == array ? buffer : array);
    long i = bottom, left_cursor = bottom, right_cursor = middle + 1;

    for(; left_cursor <= middle && right_cursor <= top; i++) {
        if (left_buffer[left_cursor] < right_buffer[right_cursor]) {
            target[i] = left_buffer[left_cursor];
            left_cursor++;
        }
        else {
            target[i] = right_buffer[right_cursor];
            right_cursor++;
        }
    }

    for(;left_cursor <= middle; i++, left_cursor++) {
        target[i] = left_buffer[left_cursor];
    }

    for(;right_cursor <= top; i++, right_cursor++) {
            target[i] = right_buffer[right_cursor];
    }

    return target;
}



void print(long* array, long n) {
    long i;
    char choice;
    FILE* file;

    printf("Do you want to print result into the file \"result\" or on the screen? (f/anykey):");
    choice = getchar();
    if(choice == 'f') {
        file = fopen("result", "w");
        for(i = 0; i < n; i++)
            fprintf(file, "Element %ld: %ld\n", i+1, array[i]);;
        fclose(file);
    }
    else {
        for(i = 0; i < n; i++)
            printf("Element %ld: %ld\n", i+1, array[i]);
        printf("\n");
    }
}
