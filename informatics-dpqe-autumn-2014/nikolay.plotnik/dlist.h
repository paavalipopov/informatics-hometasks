#ifndef DLIST_H
#define DLIST_H

typedef int data_type;

struct dlist {
    data_type data;
	struct dlist* next;
	struct dlist* prev;
};

struct dlist* generate_dlist();
struct dlist* add_element(struct dlist* any_element, data_type data);
struct dlist* get_element_by_index(struct dlist* any_element, int index);
void swap(struct dlist* first, struct dlist* second);
int get_dlist_length(struct dlist* any_element);
struct dlist* get_dlist_last_element(struct dlist* any_element);
void print_dlist(struct dlist* any_element);
struct dlist* reverse_dlist(struct dlist* any_element);
void free_dlist(struct dlist* any_element);

#endif
