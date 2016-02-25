/*
 * main.c
 *
 *  Created on: Oct 18, 2014
 *      Author: nick
 */


#include <stdio.h>
#include <stdlib.h>

struct list {
    char data;
    struct list* next;
};

struct double_list {
    char data;
    struct double_list* next;
    struct double_list* prev;
};

void init_list(struct list* l, char data) {
    l->data = data;
    l->next = NULL;
}

int get_list_length(struct list* l, struct list** last) {
    int i = 0;
    *last = NULL;
    while(l) {
        i++;
        *last = l;
        l = l->next;
    }
    return i;
}

int add_element(struct list* l, char data) {
    struct list* last;
    if(!get_list_length(l, &last)) {
        printf("Given list is empty\n");
        return -1;
    }
        last->next = (struct list*)malloc(sizeof(struct list));
        init_list(last->next, data);

        return 0;
}

void print_list(struct list* l) {
    struct list* tmp = l;
    int i = 1;
    while(tmp) {
        printf("%d element of list: %c; pointer - %p\n", i, tmp->data, tmp);
        tmp = tmp->next;
        i=i++;
    }
}

void reverse_list(struct list* root, struct list** new_root) {
        struct list* first_element = NULL;
        *new_root = NULL;
        while(root) {
                first_element = root->next;
                root->next = *new_root;
                *new_root = root;
                root = first_element;
        }
}

void free_memory(struct list* l) {
    struct list *next = NULL;
    int i = 1;
    printf("Before free\n");
    while(l) {
        printf("Free %d %p\n", i, l);
        next = l->next;
        free(l);
        l = next;
        i++;
    }
}

int main() {
    struct list* list_of_chars = (struct list*)malloc(sizeof(struct list));
    struct list* reversed_alphabet;
    char i = 0;
    int ret = 0;
    init_list(list_of_chars, 'a');
    for(i = 1; i < 1; i++) {
        if(add_element(list_of_chars, i + 'a')) {
                printf("Can't add element %c to list\n", i + 'a');
                ret = -1;
                goto out;
        }
    }
    print_list(list_of_chars);
    reverse_list(list_of_chars, &reversed_alphabet);
    list_of_chars = reversed_alphabet;
    print_list(list_of_chars);

out:
    free_memory(list_of_chars);
    return ret;
}
