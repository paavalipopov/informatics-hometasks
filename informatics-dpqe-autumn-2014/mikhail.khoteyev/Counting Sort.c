/*
 * Counting sort.c
 *
 *   Created on: Oct 24, 2014
 *      Author: michael
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, max = 0;
    int i, n, k = 0;
    int* a;
    int* b;
    int* c;

    scanf("%d" , &n);
    a = (int*)calloc(n, sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d" , &a[i]);
    }
    min = max = a[0];
    for (i=1; i < n; i++) {
        if (a[i] < min) min = a[i];
            else if (a[i] > max) max = a[i];
    }
    k = max - min + 1;
    c = (int*)calloc(k, sizeof(int));
    b = (int*)calloc(n, sizeof(int));
    for (i = 0; i < k; i++) {
        c[i] = 0;
    }
    for (i=0; i < n; i++) {
        b[i] = 0;
    }
    for (i=0; i < n; i++) {
        c[a[i] - min]++;
    }
    for (i=1; i < k; i++) {
        c[i] = c[i] + c[i-1];
    }
    for (i = 0; i < n; i++) {
        b[c[a[i]-min]-1] = a[i];
        c[a[i]-min]--;
    }
    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    free(b);
    free(c);
    free(a);
    return 0;
    }

