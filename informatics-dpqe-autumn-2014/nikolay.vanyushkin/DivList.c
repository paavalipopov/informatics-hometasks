/*
 * main.c
 *
 *  Created on: Oct 18, 2014
 *      Author: nick
 */
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list* next;
    struct list* prev;
};
void init(struct list* l)
{
    l->data=1;
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
};

int func(struct list* l,int n1)
{
    int n2=n1,i=2;
    for (;i<=n1;i++)
        {
            while(n1%i==0)
                {
                    n1=n1/i;
                    add(l,i);
                }
        }
    if ((l->next==NULL)) //If 0 or 1 was entered
         printf("%d is prime\n",n1);
    else if ((l->next->next==NULL)) //For other prime numbers
         printf("%d is prime\n",n2);
         else print(l);
}
int main()
{
    struct list list_n;
    init(&list_n);
    int x=0;
    if (scanf("%d",&x)!=1||x<0)
    {
       printf("Error:'invalid type'");
       return -1;
    }
    func(&list_n,x);
    free_list(&list_n);
    return 0;
}
