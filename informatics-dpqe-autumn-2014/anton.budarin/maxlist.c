#include <stdio.h>
#include <stdlib.h>

struct cyclo_list {
	int data;
	struct cyclo_list* next;
};

void maxmin(struct cyclo_list* tmp, int* min, int* max){
	max = tmp -> data;
	min = tmp -> data;
	struct cyclo_list* mem = tmp->next;
	tmp = tmp->next;

	while (mem != tmp->next) {
		if (max < tmp->data){
			max = tmp->data;
		}
		if (min > tmp->data){
			min = tmp->data;
		}
		tmp = tmp->next;
	}

}

void in_list(struct cyclo_list* l, char data) {
      l->data = data;
      l->next = NULL;
  }	
void add_data(struct cyclo_list* l, struct cyclo_list* begin,char* ans) {
	struct cyclo_list* last;
	int data;
	char sign;
	printf("enter data\n");
	scanf("%d",&data);
    end: 
	printf("end cycle? y/n\n");
	scanf("%c",&sign);
	*ans = sign;
	if (sign == 'y') {
		last->next = begin;
		in_list(last->next, data);
	}else if (sign == 'n'){ 
		last->next = (struct cyclo_list*)malloc(sizeof(struct cyclo_list));
		in_list(last->next, data); 
	}else goto end;

  }
int main(){
	int data;
	struct cyclo_list* list = (struct cyclo_list*)malloc(sizeof(struct cyclo_list));
	struct cyclo_list* begin = list;
	char ans = 'n';
	int max;
	int min;

	printf("enter data\n");
	scanf("%d",&data);
	in_list(list, data);
	while(ans == 'n'){
		add_data(list, begin, &ans);
	}
	maxmin(list, &min, &max);
}
	
