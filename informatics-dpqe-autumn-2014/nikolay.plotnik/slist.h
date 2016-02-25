#ifndef SLIST_H
#define SLIST_H

struct slist {
	char data;
	struct slist* next;
};

struct slist* create_slist(char data);
int get_slist_length(struct slist* first_element);
struct slist* get_slist_last_element(struct slist* any_element);
void print_slist(struct slist* first_element);
struct slist* reverse_slist(struct slist* first_element);
void free_slist(struct slist* first_element);

#endif
