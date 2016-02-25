/*
 * Insertion sort.c
 *
 *   Created on: Oct 24, 2014
 *      Author: michael
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, p = 0;
    double k = 0;
    double* a;

    scanf("%d", &n);
    a = (double*)calloc(n, sizeof(double));

    i=0;
    for (; i<n; i++) {
        scanf("%lg", &a[i]);
    }
    for (i=1; i<n; i++) {
        k=a[i];
        p=i-1;
        while ((p>=0)&&(a[p]>k)){
            a[p+1]=a[p];
            a[p]=k;
            p=p-1;
        }
    }
    for (i=0; i<n; i++) {
        printf("a[%d]=%lg\n", i, a[i]);
    }
    free(a);
    return 0;
}

