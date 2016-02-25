#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dlist.h"

struct dlist* add_element(struct dlist* any_element, data_type data) {
	struct dlist* new_element = NULL;
    struct dlist* last = NULL;

    last = get_dlist_last_element(any_element);

	if ((new_element = (struct dlist*)calloc(1, sizeof(struct dlist))) == NULL) {
		printf("Unable to allocate memory for list element\n");
		return NULL;
	}
	//TODO: Here should be copy constuctor for data
	new_element->data = data;
    
    if(last) {
        last->next = new_element;
        new_element->prev = last;
        return new_element;
       
    }

    return new_element;
}

struct dlist* generate_dlist() {
    struct dlist* new_list = NULL;
    int length = 0;
    int index = 0;

    srand((unsigned int)time(NULL));
    length = 10;//rand();
    for(index = 0; index < length; index++)
        new_list = add_element(new_list, rand());
    return new_list;
}

struct dlist* get_element_by_index(struct dlist* any_element, int index) {
    int counter = 0;
    if(!any_element)
        return NULL;
    while(any_element->prev)
        any_element = any_element->prev;

    for(counter = 0; counter < index; counter++) {
        if(any_element) {
            any_element = any_element->next;
        } else {
            return NULL;
        }
    }
    return any_element;
}

void swap_link(struct dlist* first, struct dlist* second) {
    struct dlist* second_prev = second->prev;
    struct dlist* first_prev = first->prev;

    if(first_prev) {
        first->prev->next = second;
        second->prev = first->prev;
    } else {

        second->prev = NULL;
    }

    if(second_prev) {
        second_prev->next = first;
        first->prev = second_prev;
    } else {
        first->prev = NULL;
    }

    
}

void swap(struct dlist* first, struct dlist* second) {
    //first->prev = second
}

int get_dlist_length(struct dlist* any_element) {
	int i = 0;
	struct dlist* tmp = NULL;
	if (!any_element) {
		return i;
	}
	tmp = any_element->prev;
	while (tmp) {
		i++;
		tmp = tmp->prev;
	}
	while (any_element) {
		i++;
		any_element = any_element->next;
	}
	return i;
}

struct dlist* get_dlist_last_element(struct dlist* any_element) {
	struct dlist* last = NULL;
	//Check for empty list
	if (!any_element)
		return NULL;
	while (any_element->next) {
		any_element = any_element->next;
	}
	return any_element;
}

void print_dlist(struct dlist* any_element) {
	int i = 1;
	if (any_element) {
		while (any_element->prev) {
			any_element = any_element->prev;
		}
		while (any_element) {
			//Here should be data2str function call or data format specifier 
			printf("%d element of list: %d; pointer - %p\n", i, any_element->data, any_element);
			any_element = any_element->next;
			i++;
		}
	}
}

struct dlist* reverse_dlist(struct dlist* any_element) {
	struct dlist* next_copy = NULL;
	struct dlist* new_first_element = NULL;
	struct dlist* any_element_copy = any_element;
	struct dlist* tmp = any_element;
	while (tmp) {
		next_copy = tmp->next;
		tmp->next = tmp->prev;
		tmp->prev = next_copy;
		tmp = tmp->next;
	}
	while (any_element_copy) {
		next_copy = any_element->next;
		any_element->next = any_element->prev;
		any_element->prev = next_copy;
		any_element = any_element->next;
	}
	return any_element;
}

void free_dlist(struct dlist* any_element) {
	struct dlist* tmp;
	struct dlist* prev_copy = NULL;
	if (any_element) {
		tmp = any_element->prev;
		while (tmp) {
			prev_copy = tmp->prev;
			//Here should be called data destructor
			//Something like destroy(tmp->data);
			free(tmp);
			tmp = prev_copy;
		}
		while (any_element) {
			tmp = any_element->next;
			//Here should be called data destructor
			//Something like destroy(any_element->data);
			free(any_element);
			any_element = tmp;
		}
	}
}
