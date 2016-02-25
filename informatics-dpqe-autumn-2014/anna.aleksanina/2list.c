#include <stdio.h>
#include <stdlib.h>

const int double_list_Empty = 1;             
const int double_list_End = 3;               
const int double_list_Begin = 4;
int double_list_Error;

struct double_list {
    char data;
    struct double_list* next;
    struct double_list* prev;
};

struct {
    double_list *Start;          
    double_list *End;            
    double_list *ptr;            
} d_list;

void init_list(struct d_list* l, char data) {
    l->Start = (double_list *) malloc(sizeof(double_list));
    l->End = (double_list *) malloc(sizeof(double_list));
    l->data = data;
    l->End->next = NULL;
    l->Start->prev = NULL;
    l->End->prev = l->Start;
    l->ptr = l->Start;
}

int add_element(struct double_list* l, char data) {
    struct d_list* last;
    if(!get_list_length(l, &last)) {
        printf("Given list is empty\n");
        return -1;
    }
        last->next = (struct d_list*)malloc(sizeof(struct d_list));
        init_list(last->next, data);

        return 0;
}


void delete_prev (d_list *l, char *E) {
 
    if (l->ptr == l->Start) {
        double_list_Error = double_list_Begin;
        return;
    }
 
    *E = l->ptr->prev->data;           
    double_list *ptr1 = l->ptr->prev;  
    l->ptr->prev = ptr1->prev;     
    ptr1->prev->next = l->ptr;     
    free((void *) ptr1);                    
}

void delete_next(d_list *l, char *E) {
 
    if (l->ptr == l->End) {
        double_list_Error = double_list_End;
        return;
    }
 
    *E = l->ptr->next->data;          
    double_list *ptr1 = L->ptr->next;  
    l->ptr->next= ptr1->next;      
    ptr1->next->prev = L->ptr;     
    free((void *) ptr1);                    
}

void movePtrDTwoLeft(d_list *l) {
 
    if (l->ptr == l->Start) {
        double_list_Error = double_list_Begin;
        return;
    }
    l->ptr = l->ptr->prev;
}

void movePtrListDRight(d_list *l) {
 
    if (l->ptr == l->End) {
        double_list_Error = double_list_End;
        return;
    }
    l->ptr = l->ptr->next;
}

void beginPtrListD(d_list *l) {
    while (l->ptr != l->Start) {
        movePtrListDLeft(l);
    }
}

void endPtrListD(d_list *l) {
    while (l->ptr != l->End) {
        movePtrListDRight(l);
    }
}

void free_ListD(d_list *l) {
    beginPtrListD(l);             
    char E;              
 
    while (!Empty_list(l)) {    
        delete_next(l, &E);             
    }
 
    free((void *) l->Start);
    free((void *) l->End);
}

int Empty_list(d_list *l) {
    if (L->Start->next == l->End) {
        double_list_Error = double_list_Empty;
        return 1;
    }
    return 0;
}

int get_list_length(struct double_list* l, struct double_list** last) {
    int j = 0;
    *last = NULL;
    while(l) {
        j++;
        *last = l;
        l = l->next;
    }
    return j;
}


int main () {
int start, n, i;
struct double_list* current_list = (struct double_list*)malloc(sizeof(struct double_list));
printf("Enter first element: ");
scanf("%d", &start);
printf("Enter number of the elements: ");
printf("%d", &n);
int m = get_list_length;
if ((n > m) || (start > m)) {
	double_list_Error = double_list_End;
	return -1;
}
else {
	while (i != n) {
		delete_next(curent_list,i);
		movePtrListDRight(i);
	}
}
beginPtrListD(current_list);
free_ListD(current_list);
return 0;
}
