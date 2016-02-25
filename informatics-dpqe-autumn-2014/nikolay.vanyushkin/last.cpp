#include <stdio.h>
#include <stdlib.h>

struct double_list
       {
            int x;
            struct double_list* next;
            struct double_list* prev;
       }
;
void init_list(struct double_list* l, int x)
{
    l->x = x;
    l->next = NULL;
}

int get_list_length(struct double_list* l, struct double_list** last)
    {
    int i = 0;
    *last = NULL;
    while(l)
        {
        i++;
        *last = l;
        l = l->next;
        }
    return i;
    }

int add(struct double_list* l, int x)
{
    struct double_list* last;
    last->next = (struct double_list*)malloc(sizeof(struct double_list));
    init_list(last->next, x);
    return 0;
}

void print_list(struct double_list* l)
     {
    struct double_list* tmp = l;
    int i = 1;
    while(tmp) 
    {
        printf("%d element of list: %d - %p\n", i, tmp->x, tmp);
        tmp = tmp->next;
        i++;
    }
}

void reverse_list(struct double_list* root, struct double_list** new_root)
     {
        struct double_list* first_element = NULL;
        *new_root = NULL;
        while(root) 
        {
                first_element = root->next;
                root->next = *new_root;
                *new_root = root;
                root = first_element;
        }
     }
void free_memory(struct double_list* l)
     {
        struct double_list *next = NULL;
        int i = 1;
        while(l) {
                  printf("Free %d %p\n", i, l);
                  next = l->next;
                  free(l);
                  l = next;
                  i++;
                  }
     }
int main() {
    struct double_list* list_of_n = (struct double_list*)malloc(sizeof(struct double_list));
    struct double_list* reversed_n;
    int ret = 0,x=0;
    init_list(list_of_n, x);
    int i = 0;
    for(; i < 5; i++) 
    {
          add(list_of_n, scanf("%d",&x));
    }
    print_list(list_of_n);
    reverse_list(list_of_n, &reversed_n);
    list_of_n = reversed_n;
    print_list(list_of_n);
out:
    free_memory(list_of_n);
    w:
    goto w;
    return ret;
}
