/* Задание №3: реализовать двусвязный список. Добавить функцию добавления элемента в начало.*/

#include <stdio.h>
#include <stdlib.h>

#typedef int Data_type;

struct dlist {      // создание листа
    data_type data;
    struct dlist* next;
    struct dlist* prev;
};

int check(struct dlist* P) { // проверка на ошибку
    return P == NULL ? -1 : 1;
}

int check_f&l(struct dlist* f, struct dlist* l) {   // проверка на ошибку
    return check(f) && check(l);
}

int init_dlist(struct dlist** f, struct dlist** l) {        // инициация листа: выделение памяти на первый и последний элементы (границы листа)
	*f = (struct dlist*) malloc(sizeof(struct dlist));
	*l = (struct dlist*) malloc(sizeof(struct dlist));
	if (check_f&l(*f, *l) == -1)                            // проверка того, выделилась ли память нормально
        return -1;
	(*f)->prev = NULL;                                      // установка указателей начала и конца друг надруга
	(*f)->next = *l;
	(*l)->prev = *f;
	(*l)->next = NULL;
	return 1;
}

int Push_forward_pointer(struct dlist* l,struct dlist* Last, struct dlist* New) {
	if (check_f&l(f, l) == -1)
        return -1;                      //добавление элемента в начало с перенаправлением указателей
	New->prev = f;
    New->next = f->next;
    f->next->previous = New;
    f->next = New;
    return 1;
}

int Push_forward_data(struct dlist* First, struct dlist* Last, Data_type Data) {
    if (Check_f&l(f, l) == -1)          // добавление данных в новый элемент
        return -1;
    struct dlist* New = (struct dlist*) malloc(sizeof(struct Node));
    New->data = Data;
    New->next = New->prev = NULL;
    if (!Check(New))
        return -1;
    return Push_forward_pointer(First, Last, New);
}



/* Очистка элементов массива будет проходить
в зависимости от дополнительных условий задач

 например: очистка элемента с перенаправлением указателей:
            struct dlist* P = f->next;
            struct dlist* T = NULL;
            P->prev->next = P->next;
            P->next->prev = P->prev;
            T = P;
            P = P->prev;
            free(T); */

int free_f&l(struct dlist* f, struct dlist* l) {        // очистим первый и последний элемент
    if (Check_f&l(f, l) == -1)
        return -1;
    free(f);
    free(l);
    f = l = NULL;
    return 1;
}
