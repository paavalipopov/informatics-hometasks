#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

struct Node {
    DataType data;
    struct Node* previous;
    struct Node* next;
};

int Check(struct Node* P) {
    return P == NULL ? -1 : 0;
}

int Check_FL(struct Node* First, struct Node* Last) {
    return (Check(First) && Check(Last));
}

int Init(struct Node** First, struct Node** Last) {
    *First = (struct Node*) malloc(sizeof(struct Node));
    *Last  = (struct Node*) malloc(sizeof(struct Node));
    if (Check_FL(*First, *Last) == -1)
        return -1;
    (*First)->previous = NULL;
    (*First)->next = *Last;
    (*Last)->previous = *First;
    (*Last)->next = NULL;
    return 1;
}

int Push_back_pointer(struct Node* First, struct Node* Last, struct Node* New) {
    if (Check_FL(First, Last) == -1)
        return -1;
    New->previous = Last->previous;
    New->next = Last;
    Last->previous->next = New;
    Last->previous = New;
    return 1;
}

int Push_back_data(struct Node* First, struct Node* Last, DataType Data) {
    if (Check_FL(First, Last) == -1)
        return -1;
    struct Node* New = (struct Node*) malloc(sizeof(struct Node));
    New->data = Data;
    New->next = New->previous = NULL;
    return Push_back_pointer(First, Last, New);
}

int Get_back_data(struct Node* First, struct Node* Last, DataType* Data) {
    if (Check_FL(First, Last) == -1 || Last->previous == First)
        return -1;
    *Data = Last->previous->data;
    return 1;
}

/* ��������� ����� ����� ������������ ��������� �� DataType ������ �������� �� ��������? - ������ � ������.
� ������ ������ ������� ������ �� �����, ����� �� �� ������������ ��������� ��� ���������� �� ��������.
�� ���� ����� ���� ����� ������ ������ � ���������� �������� ���-�� ����������, ��������� �� ������������� ������,
� ������� ��������� �� ������������ ������� ������. ��� �� �������� � ������� �� ��������� ��� ��������� ������
������� �� � ��������� ������, ��� ������� ��� �� �������� �������� �������� ���������� ����������*/

int Pop_back(struct Node* First, struct Node* Last) {
    if (Check_FL(First, Last) == -1 || Last->previous == First)
        return -1;
    struct Node* P = Last->previous;
    P->previous->next = Last;
    Last->previous = P->previous;
    free(P);
    return 1;
}

/* � ������ ������� ������ � P ����� First, ��� �������, ��� ���, ��������� � �����, ��� ��������� ������� � ������ ����������.
������ �� � 65 ������ ����� ��������  if (Check_FL(First, Last) == -1 || Last->previous == First) return -1; */

void print_list(struct Node* Top)
{
    Top=Top->next;

    while (Top -> next != NULL)
    {
        printf("%c", Top->data);
        Top=Top->next;
    }
}

/* ���� ���� ������� ���: ������� ������� ������ ������� � ������(��������� �������), ����� ��������� �������� ������������������
 �� � �����������, ������ ��� ��� ������ ��� ����� �������� ����������� ��� �������, �� �� ��� ����� ����� ������ � ���� ������.
 ��-����� ������� �������, ��� ��� � ���� ������ ��������� �(n) � � ����� �(2n), � ��� �� ��������, ��� �����.
*/

int main() {

    int c;
    int i;
    int key;
    struct Node* First = NULL;
    struct Node* Last = NULL;

    printf("Program Caesar cipher.\nEnter the key\n");
    scanf("%d", &key);

    printf("Enter your message\n");

    Init(&First, &Last);
        while ((c=getchar())!= EOF) {

            if((c >= 'a') && (c <= 'z'))
            c = (c - 'a' + key) % 26 + 'a';
            if((c >= 'A') && (c <= 'Z'))
            c = (c - 'A' + key) % 26 + 'A';

            Push_back_data(First, Last, c);
        }
    print_list(First);

    return 0;
}
