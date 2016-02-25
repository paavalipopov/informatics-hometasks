#include <stdio.h>
#include <stdlib.h>

struct lst_List {
    struct lst_Link* first;
    struct lst_Link* last;
	unsigned int size;
};

struct lst_Link {
    struct lst_Link* prev;
    struct lst_Link* next;
};

struct lst_Value {
	struct lst_Link lnk;
	
	char* p;
};

/* инициализирует lst пустым */
void lst_init(struct lst_List* lst);

/* создает новый пустой список в свободной памяти */
struct lst_List* lst_create();

/* добавляет элемент p в конец списка lst */
void lst_push_back(struct lst_List* lst, struct lst_Link* p);

/* удаляет элемент p из списка lst 
   возвращает указатель на узел, расположенный после узла p */
struct lst_Link* lst_erase(struct lst_List* lst, struct lst_Link* p);

/* возвращает элемент, находящийся через n узлов после узла p */
struct lst_Link* lst_get_next(struct lst_Link* p, int n);

/* выделяем память для значения списка */
struct lst_Value* make_name(char* n);

/*/////////////////////////////////////////////////////////////////////////////////////////////*/

void lst_init(struct lst_List* lst) {
	lst->first = lst->last = 0;
	lst->size = 0;
}

struct lst_List* lst_create() {
	struct lst_List* lst = (struct lst_List*)malloc(sizeof(struct lst_List));
	lst_init(lst);
	return lst;
}

void lst_push_back(struct lst_List* lst, struct lst_Link* p) {
	struct lst_Link* last = lst->last;
	
	if(last) {
		/* добавляем узел p после узла last */
		last->next = p;
		p->prev = last;
	} else {
		/* p - первый элемент */
		lst->first = p;
		p->prev = 0;
	}
	
	/* p - новый последний элемент */
	
	lst->last = p;
	p->next = 0;

	++lst->size;
}

struct lst_Link* lst_erase(struct lst_List* lst, struct lst_Link* p) {
	if(p == 0) return 0;
	
	if(lst->size == 0) {
		return 0;
	}

	--lst->size;

	if(p == lst->first) {
		if(p->next) {
			/* next узел становится первым */
			lst->first = p->next;
			p->next->prev = 0;
			
			free(p);
			return p->next;
			
		} else {
			/* список становится пустым */
			
			lst->first = lst->last = 0;
			
			free(p);
			return 0;
		}
	} else if(p == lst->last) {
		if(p->prev) {
			/* prev узел становится последним */
			lst->last = p->prev;
			p->prev->next = 0;
			
			free(p);
			return 0;
		
		} else {
			/* список становится пустым, и вообще то это условие не должно выполняться */
			
			lst->first = lst->last = 0;
			
			free(p);
			return 0;
		}
		
	} else {
		/* узел находится где-то между первым и последним */
		p->next->prev = p->prev;
		p->prev->next = p->next;
		
		free(p);
		return p->next;
	}
}

struct lst_Link* lst_get_next(struct lst_Link* p, int n) {

	struct lst_Link* get_next = p->next; /* указатель на след. узел */
	n--;

	if(get_next == 0) {
		return 0;
	}

	while(n > 0){
		
		get_next = get_next->next; /* едем дальше */

		if(get_next == 0) {
			/* мы уже достигли конца (переборщили с n) */
			
			return 0;
			
		}
		
		n--;
	}
	
	return get_next;
}

struct lst_Value* make_name(char* n) {
	struct lst_Value* p = (struct lst_Value*)malloc(sizeof(struct lst_Value));
	p->p = n;
	
	return p;
}



int main()
{
    int get_count = 0;
	struct lst_List lst_names; /* создаем список */
	struct lst_Link* curr; /* указатель который поставим на начало для обхода списка */
	
	lst_init(&lst_names);
	
	/* создаем несколько объектов lst_Value и добавляем их в список */
	lst_push_back(&lst_names,(struct lst_Link*)make_name("Misha"));
	lst_push_back(&lst_names,(struct lst_Link*)make_name("Lesha"));
	lst_push_back(&lst_names,(struct lst_Link*)make_name("Nikita"));
	lst_push_back(&lst_names,(struct lst_Link*)make_name("Anton"));
	lst_push_back(&lst_names,(struct lst_Link*)make_name("Samat"));
	lst_push_back(&lst_names,(struct lst_Link*)make_name("NickPlot"));

	
	/* удаляем второе имя */
	lst_erase(&lst_names,lst_get_next(lst_names.first, 2));
	

	curr = lst_names.first;
	
	printf("size: %d\n", lst_names.size);

	for(; curr != 0; curr = curr->next) {
		get_count++;
		
		printf("element %d: %s\n", get_count, ((struct lst_Value*)curr)->p);
	}



    return 0;
}
