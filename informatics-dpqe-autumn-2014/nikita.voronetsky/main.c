#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct List List;
struct List
{
    int item;
    List *next;
    List *prev;
};

List *list_add(List *head, int item)
{
    List *new_item = (List *)malloc(sizeof(List));
    new_item->item = item;
    new_item->next = head;
    new_item->prev = NULL;
    head = new_item;
    return head;
}

List *list_append(List *head, int item)
{
    List *new_item = (List *)malloc(sizeof(List));
    new_item->item = item;
    new_item->next = NULL;
    if (head)
    {
        List *list;
        for (list = head; list->next; list = list->next);
        list->next = new_item;
        new_item->prev = list;
    }
    else
    {
        head = new_item;
    }
    return head;
}

int list_get(List *head, unsigned index)
{
    unsigned i;
    for (i = 0; head; head = head->next, i++)
    if (i == index)
        return head->item;
    return -1;
}

void list_set(List *head, unsigned index, int item) {
    unsigned i;
    for (i = 0; head; head = head->next, i++)
    if (i == index) {
        head->item = item;
        return;
    }
}

unsigned list_size(List *head)
{
    if (!head)
        return 0;
    else
        return list_size(head->next) + 1;
}

void list_print(List *head)
{
    for (; head; head = head->next)
        printf("%d ", head->item);
    printf("\n");
}

void list_destroy(List *list)
{
    if (list)
    {
        list_destroy(list->next);
        free(list);
    }
}
List * list_find(List * head, int item)
{
    int i = 0;
    int l1 = -1, l2 = -1;
    List * list = head;
    List * list1 = NULL;
    List * list2 = NULL;
    while(list)
    {
        if(list->item == item)
        {
            l1 = i;
            list1 = list;
            break;
        }
        i++;
        list = list->next;
    }
    list = head;
    i = 0;
    while(list)
    {
        if(list->item == item)
        {
            l2 = i;
            list2 = list;
        }
        i++;
        list = list->prev;
    }
    if(!list1 && !list2)
        return NULL;
    if(!list1 && list2)
        return list2;
    if(list1 && !list2)
        return list1;
    if(l1 < l2)
        return list1;
    else
        return list2;
}

List * list_getN(List *head, List *listi)
{
    while(head->next)
        head = head->next;
    while(head->prev)
    {
        int i = 0;
        int a = 0;
        while((head) && (head->item != ' '))
        {
            a += (head->item - '0') * pow(10.0, i);
            head = head->prev;
            i++;
        }
        listi = list_append(listi, a);
        if(head)
            head = head->prev;
        else
            break;
    }
    return listi;
}
void MinMaxAvr(List * head)
{
    int max, min, sum = 0, i = 0;
    double avr;
    min = head->item;
    max = head->item;
    while(head)
    {
        if(head->item > max)
            max = head->item;
        if(head->item < min)
            min = head->item;
        sum += head->item;
        i++;
        head = head->next;
    }
    avr = sum / (double)i;
    printf("max = %d\nmin = %d\navr = %lg\n", max, min, avr);
}

int main()
{
    char c;
    List * listc = NULL;
    List * listi = NULL;
    List * l;
    scanf("%c", &c);
    while (c != '\n')
    {
        listc = list_append(listc, (int)c);
        scanf("%c", &c);
    }
    listi = list_getN(listc, listi);
    MinMaxAvr(listi);
    l = list_find(listi, 123);
    list_destroy(listc);
    list_destroy(listi);
    scanf("%c", &c);
    return 0;
}
