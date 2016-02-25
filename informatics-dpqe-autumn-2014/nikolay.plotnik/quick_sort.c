#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

int test_quick_sort() {
    struct dlist* list_to_sort = NULL;

    list_to_sort = generate_dlist();
    print_dlist(list_to_sort);
    //quick_sort(list_to_sort);
    struct dlist* tmp = get_element_by_index(list_to_sort, 1);
    printf("5 element - %d %p\n", tmp->data, tmp);
    print_dlist(list_to_sort);
    free_dlist(list_to_sort);
    return 0;
}
