/* ������� �3: ����������� ���������� ������. �������� ������� ���������� �������� � ������.*/

#include <stdio.h>
#include <stdlib.h>

#typedef int Data_type;

struct dlist {      // �������� �����
    data_type data;
    struct dlist* next;
    struct dlist* prev;
};

int check(struct dlist* P) { // �������� �� ������
    return P == NULL ? -1 : 1;
}

int check_f&l(struct dlist* f, struct dlist* l) {   // �������� �� ������
    return check(f) && check(l);
}

int init_dlist(struct dlist** f, struct dlist** l) {        // ��������� �����: ��������� ������ �� ������ � ��������� �������� (������� �����)
	*f = (struct dlist*) malloc(sizeof(struct dlist));
	*l = (struct dlist*) malloc(sizeof(struct dlist));
	if (check_f&l(*f, *l) == -1)                            // �������� ����, ���������� �� ������ ���������
        return -1;
	(*f)->prev = NULL;                                      // ��������� ���������� ������ � ����� ���� �������
	(*f)->next = *l;
	(*l)->prev = *f;
	(*l)->next = NULL;
	return 1;
}

int Push_forward_pointer(struct dlist* l,struct dlist* Last, struct dlist* New) {
	if (check_f&l(f, l) == -1)
        return -1;                      //���������� �������� � ������ � ���������������� ����������
	New->prev = f;
    New->next = f->next;
    f->next->previous = New;
    f->next = New;
    return 1;
}

int Push_forward_data(struct dlist* First, struct dlist* Last, Data_type Data) {
    if (Check_f&l(f, l) == -1)          // ���������� ������ � ����� �������
        return -1;
    struct dlist* New = (struct dlist*) malloc(sizeof(struct Node));
    New->data = Data;
    New->next = New->prev = NULL;
    if (!Check(New))
        return -1;
    return Push_forward_pointer(First, Last, New);
}



/* ������� ��������� ������� ����� ���������
� ����������� �� �������������� ������� �����

 ��������: ������� �������� � ���������������� ����������:
            struct dlist* P = f->next;
            struct dlist* T = NULL;
            P->prev->next = P->next;
            P->next->prev = P->prev;
            T = P;
            P = P->prev;
            free(T); */

int free_f&l(struct dlist* f, struct dlist* l) {        // ������� ������ � ��������� �������
    if (Check_f&l(f, l) == -1)
        return -1;
    free(f);
    free(l);
    f = l = NULL;
    return 1;
}
