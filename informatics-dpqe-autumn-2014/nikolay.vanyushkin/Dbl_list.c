#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list* next;
    struct list* prev;
};
void init(struct list* l,int data)
{
    l->data=data;
    l->next=NULL;
    l->prev=NULL;
};
void add(struct list* l, int data)
{
        while(l->next)
        l = l->next;
        if(!(l->next = (struct list*)malloc(sizeof(struct list))))
        {
            printf("Error");
            exit(0);
        }
        l->next->data = data;
        l->next->prev = l;
        l->next->next = NULL;
}
void print(struct list* l)
{
    int i=1;
    while(l)
    {
       printf("%d element of list: %d\n",i,l->data);
       l=l->next;
       i++;
    }
}
void free_list(struct list* l)
{
    int i=1;
    struct list* copy=NULL;
    while(l)
    {
       copy=l->next;
       printf("%d element of list: %d deleted\n",i,l->data);
       free(l);
       l=copy;
       i++;
    }
    free(copy);
}

void MaxMin(struct list* l)
{
    int max=l->data,min=max;
    while(l->next)
    {
        l=l->next;
        if(max<l->data)
        {
            max=l->data;
        }
        if(min>l->data)
        {
            min=l->data;
        }
    }
    printf("Maximum element of list is %d\n",max);
    printf("Minimum element of list is %d\n",min);
}

int main()
{
    int N=0,x=0,i=0;
    struct list list_n;
    printf("How many elements?\n");
if ((scanf("%d",&N)!=1))
            {
                printf("Error:'invalid type'");
                return 1;
            }
    printf("Enter numbers\n");
if ((scanf("%d",&x)!=1))
            {
                printf("Error:'invalid type'");
                return 1;
            }
    init(&list_n,x);
    for (;i<N-1;i++)
    {
        if ((scanf("%d",&x)!=1))
            {
                printf("Error:'invalid type'");
                return 1;
            }
        add(&list_n,x);
    }
    print(&list_n);
    MaxMin(&list_n);
    free_list(&list_n);
    return 0;
}
