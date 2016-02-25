/* реализую список через не имеющие смысловой нагрузки служебные начало и конец */

#include <stdlib.h>
#include <stdio.h>


struct list {
	char data;
   	struct list* next;
    struct list* prev;
};


int add_element(struct list* first, struct list* last, char data);
void reversed_print_list(struct list* first, struct list* last);
void free_memory(struct list* first, struct list* last);
int init_list(struct list** first, struct list** last);

int init_list(struct list** first, struct list** last) {
    *first = (struct list*)malloc(sizeof(struct list));
    *last = (struct list*)malloc(sizeof(struct list));
    if(*first == NULL || *last == NULL) {
        printf("Memory allocation error");
        if(*first != NULL)
            free(first);
        if(*last != NULL)
            free(last);
        return -1;
    }

    (*first)->next = *last;
    (*last)->prev = *first;
    (*first)->prev = (*last)->next = NULL;

    return 0;
}

int add_element(struct list* first, struct list* last, char data) {
	struct list* element = (struct list*)malloc(sizeof(struct list));
	if(element == NULL) {
        printf("\nMemory allocation error");
        return -1;
    }
	element->data = data;

	element->next = last;
	element->prev = last->prev;
	last->prev->next = element;
	last->prev = element;

	return 0;
}


void reversed_print_list(struct list* first, struct list* last) {
	struct list* tmp = last->prev;
	while(tmp != first) {
		printf("%c", tmp->data);
        tmp = tmp->prev;
	}
}


void free_memory(struct list* first, struct list* last) {
	if(first == NULL || last == NULL)
		printf("Can't free memory, wrong pointers\n");
	else {
		struct list* tmp = first;
		while(tmp != last) {
			tmp = tmp->next;
			free(tmp->prev);
		}
		free(tmp);
	}
}


int main(void) {
    char data;
    struct list* first;
    struct list* last;
    if(init_list(&first, &last) !=0)
		return -1;

    while(data = getchar()){
        if((data == '\n') || (add_element(first, last, data) != 0))
            break;
	}

	reversed_print_list(first, last);
	free_memory(first, last);

	return 0;
}


