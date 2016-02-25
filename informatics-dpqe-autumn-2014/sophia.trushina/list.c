#include <stdio.h>
#include <stdlib.h>

struct list {
	char data;
	struct list* next;
    struct list* prev;
};


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
        printf("Given list is empty\n");
        return -1;
    }
        last->next = (struct list*)malloc(sizeof(struct list));
        init_list(last->next, data);

        return 0;
}

void deletereq(struct list **head_ref, struct list *del)
{
  if(*head_ref == NULL || del == NULL)
    return;
  if(*head_ref == del)
    *head_ref = del->next;
  if(del->next != NULL)
    del->next->prev = del->prev;
  if(del->prev != NULL)
    del->prev->next = del->next;    
  free(del);
  return;
}    

void print_list(struct list* l) {
    struct list* tmp = l;
    int i = 1;
    while(tmp) {
        printf("%d element of list: %c; pointer - %p\n", i, tmp->data, tmp);
        tmp = tmp->next;
        i++;
    }
}

void free_memory(struct list* l) {
    struct list *next = NULL;
    int i = 1;
    printf("Before free\n");
    while(l) {
        printf("Free %d %p\n", i, l);
        next = l->next;
        free(l);
        l = next;
        i++;
    }
}


main() {
	struct list* list_of_chars = (struct list*)malloc(sizeof(struct list));
	init_list (list_of_chars, 'g');
	int i = 1; char req;
	for (i; i < 30; i++) {
		   if(add_element(list_of_chars, i + 'g')) {
                printf("Can't add element %c to list\n", i + 'a');
                goto out;
        }
    }
    print_list(list_of_chars);
    scanf ("%c", &req);
    print_list(list_of_chars);
    for (i; i < 30; i++) {
    	if (list_of_chars->next == req) {
    		deletereq (list_of_chars, list_of_chars->next);
    	}
    print_list(list_of_chars);
	out:
    free_memory(list_of_chars);
	return 0;
}
