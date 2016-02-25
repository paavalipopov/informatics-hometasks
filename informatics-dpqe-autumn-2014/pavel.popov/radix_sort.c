#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct buffer_queue {
    struct buffer_queue* next;
    struct buffer_queue* prev;
    int data;
};

void print(int* array, int n);

int main(void) {
    int n, max_length = 10;
    int* array;

    printf("Enter number of elements and max length(max = 10, because of type int): ");
	scanf("%d %d", &n, &max_length);
	if(n < 1 || max_length < 1) {
		printf("Nothing to do.\n");
		return -1;
	}


    array = (int*)calloc(n, sizeof(int));
	if (array == NULL) {
		printf("Error with allocating memory");
		return -2;
	}

	if(radix_sort(array, n, max_length) != 0) {
        free(array);
        return -3;
    }
    print(array, n);
    free(array);

    return 0;
}

void fill(int* array, int n, int max_length) {
    int i;
    char yn;

    yn = getchar(); //отсекает пеервод строки, который был ещё в мэйне
    printf("Do you want to automaticlly fill the array? (y/anykey): ");
    yn = getchar();

    if(yn == 'y') {
        srand(time(NULL));
        for(i = 0; i < n; i++) {
            array[i] = rand() % ten_power(max_length);
        }
    }

    else {
        for(i = 0; i < n; i++) {
            printf("Enter element %d: ", i+1);
            scanf("%d", array + i);
        }
    }
}

void print(int* array, int n) {
    int i;

    for(i = 0; i < n; i++)
        printf("Element %d: %d\n", i+1, array[i]);
}

void free_memory(struct buffer_queue* first, struct buffer_queue* last) {
	struct buffer_queue* tmp = first;
	while(tmp != last) {
        tmp = tmp->next;
        free(tmp->prev);
	}
	free(last);
}

int ten_power(int n) {
    int result = 1;

    for(;n > 0; n--)
        result = result * 10;

    return result;
}

int radix_sort(int* array, int n, int max_length) {
    int i, j, k, remainder;
    struct buffer_queue* buffer_first[10];
    struct buffer_queue* buffer_last[10];
    for(i = 0; i < 10; i++) {
        buffer_first[i] = (struct buffer_queue*)malloc(sizeof(struct buffer_queue));
        buffer_last[i] = (struct buffer_queue*)malloc(sizeof(struct buffer_queue));
        if(buffer_first[i] == NULL || buffer_last[i] == NULL) {
            printf("\nMemory allocation error\n");
            for(; i >= 0; i--) {
                free(buffer_first[i]);
                free(buffer_last[i]);
            }
            return -2;
        }
        buffer_first[i]->next = buffer_last[i];
        buffer_last[i]->prev = buffer_first[i];
        buffer_first[i]->prev = buffer_last[i]->next = NULL;

    }

    fill(array, n, max_length);

    for(i = 0; i <= max_length; i++){
        for(k = 0; k < n; k++) {
            remainder = (array[k] / ten_power(i)) % 10;
            if(add_element(buffer_first[remainder], buffer_last[remainder], array[k]) != 0) {
                printf("Memory allocating error");
                for(k = 0; k < 10; k++) {
                    free_memory(buffer_first[k], buffer_last[k]);
                    }
                return -2;
            }
        }
        for(k = 0, j = 0; j < 10; j++) {
            while(check_buffer(buffer_first[j], buffer_last[j])) {
                array[k] = get_element(buffer_first[j], buffer_last[j]);
                k++;
            }
        }
    }

    for(i = 0; i < 10; i++) {
        free_memory(buffer_first[i], buffer_last[i]);
    }

    return 0;
}

int check_buffer(struct buffer_queue* first, struct buffer_queue* last) {

    return (first->next != last);
}

int add_element(struct buffer_queue* first, struct buffer_queue* last, int data) {
	struct buffer_queue* element = (struct buffer_queue*)malloc(sizeof(struct buffer_queue));
	if(element == NULL) {
        printf("\nMemory allocation error");
        free_memory(first, last);
        return -1;
    }
	element->data = data;

	element->next = last;
	element->prev = last->prev;
	last->prev->next = element;
	last->prev = element;

	return 0;
}

int get_element(struct buffer_queue* first, struct buffer_queue* last) {
    struct buffer_queue* element = first->next;
    int data = element->data;

    first->next = first->next->next;
    first->next->prev = first;
    free(element);

    return data;
}
