#include <stdio.h>
#include <stdlib.h>

struct list {
    data_type data;
    struct list* next;
    struct list* prev;
}

void init_list(struct list* l, char data) {
    l->data = data;
    l->next = NULL;
}

int get_list_length(struct list* l, struct list** last) {
    int i = 0;
    *last = NULL;
    while(l) {
        i++;
        *last = l;
        l = l->next;
    }
    return i;
}

int add_element(struct list* l, char data) {
    struct list* last;
    if(!get_list_length(l, &last)) {
        return -1;
    }
        last->next = (struct list*)malloc(sizeof(struct list));
        init_list(last->next, data);

        return 0;
}

void print_list(struct list* l) {
    struct list* tmp = l;
    int i = 1;
    while(tmp) {
        tmp = tmp->next;
        i++;
    }
}

void free_memory(struct list* l) {
    struct list *next = NULL;
    int i = 1;
    while(l) {
        next = l->next;
        free(l);
        l = next;
        i++;
    }
}

void push_back(struct list, struct list* p) {
	struct list* last = list->last;
	
	if(last) {
		last->next = p;
		p->prev = last;
	} else {
		lst->first = p;
		p->prev = 0;
	}
	
	list->last = p;
	p->next = 0;

	++list->l;
}

int main (){
	struct list* list_of_smth = (struct list*)malloc(sizeof(struct list));
	data_type data;
	init_list(list_of_smth, data);
	for (int t = 0;t<N;++y){
		if(add_element(list_of_chars, data)) {
                a = -1;
                goto out;
		}
	}
	scanf("%d",p);
	void push_back(list_of_smth , struct list* p);
	out:
    		free_memory(list_of_chars);	
}














}

