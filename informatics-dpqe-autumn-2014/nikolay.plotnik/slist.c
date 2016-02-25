#include <stdio.h>
#include <stdlib.h>
#include "slist.h"


struct slist* create_slist(char data) {
	struct slist* new_slist = NULL;
	if ((new_slist = (struct slist*)calloc(1, sizeof(struct slist)))) {
		printf("Unable to allocate memory for list element\n");
		return NULL;
	}
	//TODO: Here should be copy constuctor for data
	new_slist->data = data;

	new_slist->next = NULL;
	return new_slist;
}

int get_slist_length(struct slist* first_element) {
    int i = 0;
	while (first_element) {
        i++;
		first_element = first_element->next;
	}
    return i;
}

struct slist* get_slist_last_element(struct slist* any_element) {
	struct slist* last = NULL;
	//Check for empty list
	if (!any_element)
		return NULL;
	while (any_element->next) {
		any_element = any_element->next;
	}
	return any_element;
}

void print_slist(struct slist* first_element) {
    int i = 1;
	while (first_element) {
		//Here should be data2str function call or data format specifier 
		printf("%d element of list: %c; pointer - %p\n", i, first_element->data, first_element);
		first_element = first_element->next;
        i++;
    }
}

struct slist* reverse_slist(struct slist* first_element) {
	struct slist* next_copy = NULL;
	struct slist* new_first_element = NULL;
	while(first_element) {
		next_copy = first_element->next;
		first_element->next = new_first_element;
		new_first_element = first_element;
		first_element = next_copy;
	}
	return new_first_element;
}

void free_slist(struct slist* first_element) {
    struct slist* tmp = NULL;
    while(first_element) {
		tmp = first_element->next;
		//Here should be called data destructor
		//Something like destroy(first_element->data);
		free(first_element);
		first_element = tmp;
    }
}
