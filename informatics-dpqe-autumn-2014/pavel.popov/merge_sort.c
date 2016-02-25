#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define allocate(n) (long*)calloc(n, sizeof(long));


void fill(long* array, int n);
long* merge_sort(long* array, long* buffer, short bottom, short top);
void print(long* array, int n);


int main(void) {
	long n = 0;
	long* array;
	long* buffer;

	printf("Enter number of elements: ");
	scanf("%ld", &n);
	if(n < 1) {
		printf("Nothing to do.\n");
		return -1;
	}



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


void fill(long* array, int n) {
    int i;
    char yn;

    yn = getchar(); //отсекает пеервод строки, который был ещё в мэйне
    printf("Do you want to automaticlly fill the array? (y/anykey): ");
    yn = getchar();

    if(yn == 'y') {
        srand(time(NULL));
        for(i = 0; i < n; i++) {
            array[i] = rand() % 1000;
        }
    }

    else {
        for(i = 0; i < n; i++) {
            printf("Enter element %d: ", i+1);
            scanf("%ld", array + i);
        }
    }
}

long* merge_sort(long* array, long* buffer, short bottom, short top) {
    if (bottom == top)
    {
        buffer[bottom] = array[bottom];
        return buffer;
    }

    int middle = (bottom + top) / 2;

    long* left_buffer = merge_sort(array, buffer,  bottom, middle);
    long* right_buffer = merge_sort(array, buffer, middle + 1, top);

    long* target = (left_buffer == array ? buffer : array);
    short i = bottom, left_cursor = bottom, right_cursor = middle + 1;

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



void print(long* array, int n) {
    int i;

    for(i = 0; i < n; i++)
        printf("Element %d: %ld\n", i+1, array[i]);
    printf("\n");
}
