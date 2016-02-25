#include <stdio.h>
#include <stdlib.h>
#define MIN_INT -100500
#define MAX_INT  100500

void search_max_min (int *max_int, int *min_int, int n, int a[]) {
    int i = 0;
    *max_int = MIN_INT;
    *min_int = MAX_INT;
    for (; i < n; i++) {
        if (a[i]>*max_int) {
            *max_int = a[i];
        }
        if (a[i]<*min_int) {
            *min_int = a[i];
        }
    }
}

int main()
{
    int n = 0;
    int i, max_int, min_int;
    scanf("%d", &n);
    int *a = (int*) calloc (n, sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    search_max_min(&max_int, &min_int, n, a);
    int difference = max_int - min_int + 1;
    int *s = (int*) calloc (difference, sizeof(int));
    for(i = 0; i < n; i++) {
        s[a[i]-min_int]++;
    }
    n = 1;
    for( i = 0; i< difference; i++)
        for(; s[i] > 0; s[i]--, n++)
            printf("%d element: %d\n", n, (i+min_int));
    system("pause");
   return 0;
}
