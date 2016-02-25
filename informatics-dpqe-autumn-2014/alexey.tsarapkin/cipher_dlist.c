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

/* Насколько здесь лучше использовать указатель на DataType вместо передачи по значению? - Вопрос к зачету.
В данной задаче разницы особой не будет, будем ли мы использовать указатель или передавать по значению.
Но если перед нами будет стоять вопрос в считывании большого кол-во информации, состоящей из повторяющихся данных,
с помощью указателя мы оптимизируем затраты памяти. Так же передача в функцию по указателю при изменении данных
изменит их в глобалном смысле, что избавит нас от передачи возможно большого количества параметров*/

int Pop_back(struct Node* First, struct Node* Last) {
    if (Check_FL(First, Last) == -1 || Last->previous == First)
        return -1;
    struct Node* P = Last->previous;
    P->previous->next = Last;
    Last->previous = P->previous;
    free(P);
    return 1;
}

/* В случае пустого списка в P будет First, что неверно, так как, насколько я понял, это служебный элемент в данной реализации.
Вообще то в 65 строке стоит проверка  if (Check_FL(First, Last) == -1 || Last->previous == First) return -1; */

void print_list(struct Node* Top)
{
    Top=Top->next;

    while (Top -> next != NULL)
    {
        printf("%c", Top->data);
        Top=Top->next;
    }
}

/* надо было сделать так: сначала считать строку целиком в список(отдельная функция), затем отдельной функцией переконвертировать
 ее в шифрованную, память под нее кстати уже можно выделить динамически без списков, мы же уже знаем длину списка в этом случае.
 По-моему разницы никакой, так как в моем случае сложность О(n) а в вашем О(2n), а как вы говорили, они равны.
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
