#include <stdio.h>
#include <stdlib.h>

struct cyclo_list {
        int data;
        struct cyclo_list* next;
};

void maxmin(struct cyclo_list* tmp, int* min, int* max){
        printf("started finding maxmin\n");
        
        *max = tmp -> data;
        *min = tmp -> data;
        
        struct cyclo_list* mem = tmp;
        tmp = tmp->next;
        
        while (mem != tmp) {
                if (*max < tmp->data){
                        *max = tmp->data;
                }
                if (*min > tmp->data){
                        *min = tmp->data;
                }
                tmp = tmp->next;
                
                
        }

}

void print_cycle(struct cyclo_list* element){
    printf("start printing\n");
        struct cyclo_list* mem = element;
        printf("element = %d\n", element->data);
        element = element->next;
        while (mem != element) {
                printf("element = %d\n", element->data);
                element = element->next;
        }   
     printf("ended printing\n");           
}



void in_list(struct cyclo_list** l, int data, struct cyclo_list* begin) {
      (*l)->data = data;
      (*l)->next = begin;
  }     
void add_data(struct cyclo_list** l, struct cyclo_list* begin) {
        int data;
        char sign; // Эта переменная используется только в ненужной строке, без которой все не очень работает.
        
        printf("add data\n");
        scanf("%d",&data);
        scanf("%c",&sign); // Не ищите смысл в этой строке, но без нее программа не очень  работает.
        
        (*l)->next = (struct cyclo_list*)malloc(sizeof(struct cyclo_list));
        (*l) = (*l)->next;
        in_list(l, data, begin);
        printf("looped\n");

  }
int main(){
        struct cyclo_list* list = (struct cyclo_list*)malloc(sizeof(struct cyclo_list));
        struct cyclo_list* begin = list;
        char ans = 'n';
        int max, min, data;

        printf("enter data\n");
        scanf("%d",&data);
        in_list(&list, data, begin);
        while(ans != 'y'){
                add_data(&list, begin);
                printf("end cycle? y/n\n");
                scanf("%c",&ans);
        }
        print_cycle(list);
        maxmin(list, &min, &max);
        printf("max=%d    min=%d\n", max, min);
}