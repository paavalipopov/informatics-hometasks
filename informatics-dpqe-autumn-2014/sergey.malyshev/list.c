#include <stdio.h>
#include <stdlib.h>
/* implementation of the doubly linked list, dealocation, out random simbol*/
typedef struct list{
    int i;
    struct list *next;
    struct list *prev;
} list;

list* create(list* a, int val)
{
    a = malloc(sizeof(list));
    a->i = val;
    return a;
}

int print(list* first)
{
    int i = 1;
    printf("%d \n", first->i);
    if (first->next != NULL)
    {
        print(first->next);
    } else
    i = 1;
    return i;
}



int fre(list* first)
{
    int i = 1;
    if (first->next != NULL)
    {
        free(first->next);
    } else
    i = 1;
    free(first);
    return i;
}


int main()
{
    list *a = malloc(sizeof(list));
    list *b;

    a->i = 1;
    b = create(b,2);
    b->prev = a;
    b->next = NULL;
    a->prev = NULL;
    a->next = b;
    printf("%d",a->i);
    fre(a);
    return 0;
}
