/* Убрать из двусвязного списка элементы, начиная с индекса start, заканчивая индексом end.*/

#include <stdlib.h>
#include <stdio.h>
#define NUMBER_OF_ELEMENTS 20

struct list {
	int data;
   	struct list* next;
	struct list* prev;

};

void init_list(struct list* l, int data) {
    l->data = data;
   	l->next = NULL;
	l->prev = NULL;
}

void last_element(struct list* l, struct list** last) {
	struct list *tmp = l;
	while(tmp != NULL) {
        *last = tmp;
        tmp = tmp->next;
    }
}

void add_element(struct list* l, int data) {
	struct list* last;
	last_element(l, &last);
	last->next = (struct list*)malloc(sizeof(struct list));
	last->next->prev = last;
	last->next->next = NULL;
	last->next->data = data;
}

void print_list(struct list* l) {
	struct list* tmp = l;
	int i = 0;
	while(tmp) {
		printf("%d element of list: %d\n", i, tmp->data);
        tmp = tmp->next;
        i++;
	}
}

void free_memory(struct list* l) {
	struct list *tmp = l;
	struct list *next = tmp->next;
	int i = 1;
	while(tmp) {
        free(tmp);
        tmp = next;
        i++;
        if(next)
            next = next->next;
	}
}


int del_elements(struct list* l, int start, int end) {
	if(start < 0 || start > NUMBER_OF_ELEMENTS || end < 0 || end > NUMBER_OF_ELEMENTS) {
        printf("Wrong start or end index\n");
        return -1;
    }

    int i;
    struct list *tmp = l;
    struct list *tmp0;
    for(i = 0; i < start; i++) {
        tmp = tmp->next;
    }

    tmp0 = tmp->prev;
    for(;i <= end; i++) {
        tmp = tmp->next;
        free(tmp->prev);
    }

    tmp->prev = tmp0;
    tmp0->next = tmp;

    return 0;
}


int main(void) {
	int start, end, i;
	struct list list_of_ints;

	i = 0;                                  //инициализация листа
	init_list(&list_of_ints, i);
	for(i = 1; i < NUMBER_OF_ELEMENTS; i++)
        	add_element(&list_of_ints, i);
    print_list(&list_of_ints);

	printf("Start and end: ");
	scanf("%d %d", &start, &end);

    if(del_elements(&list_of_ints, start, end) != 0) {
        free_memory(list_of_ints.next);
        return -1;
    }

	print_list(&list_of_ints);
	free_memory(list_of_ints.next);
	return 0;
}


