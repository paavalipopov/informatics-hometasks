#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int height;
    int length;
    int *arr;
} matrix_t ;

void create_new_matrix(int height, int length, matrix_t *one)
{
    one->height = height;
    one->length = length;
    int size_a = one->height * one->length;
    one->arr = (int *)malloc(size_a * sizeof(int));
}

void matrix_filling(matrix_t *a)
{
    int elements = a->height * a-> length;
    int i;
    for(i = 0 ; i < elements; ++i)
    {
        scanf("%d", &a->arr[i]);
    }
}
void multiplication(matrix_t * a, matrix_t * b)// matrix c should be rewritten in matrix a
{
    int i, j, k;
    matrix_t c;
    create_new_matrix(a->height,b->length, &c);
    for( i = 0; i < a->height; ++i)
    {
        for( j = 0; j < b->height; ++j)
        {
            int sum = 0;
            for( k = 0; k < b->length; ++k)
            {
                sum = sum +( a->arr[(a->length * (i - 1)) +  k - 1]) * (b-> arr[(b->length * (k - 1)) + j - 1]);
                printf("%d %d\n", a->arr[(a->length * (i - 1)) +  k - 1], b-> arr[(b->length * (k - 1)) + j -1]);
            }
            c.arr[(c.length * i) + j - 1] = sum;
            sum = 0;
        }
    }
    free(a->arr);
    create_new_matrix(c.height,c.length, &(*a));
    a->arr = c.arr;
}

int main()
{
    int number,i,j, height, length;
    matrix_t a, b;
    scanf("%d", &number);
    if ((number == 0)||(number == 1))
    {
        printf("not enough matrixes\n");
        return 0;
    }
    scanf("%d %d",&height, &length);
    create_new_matrix(height,length, &a);
    matrix_filling(&a);
    for(i = 1; i < number; ++i )
    {
        scanf("%d  %d",&height, &length);
        if (a.length != height)
        {
            printf("Error: multiplication impossible\n");
            return 0;
        }
        create_new_matrix(height,length, &b);
        matrix_filling(&b);
        multiplication(&a,&b);
    }
    printf("resulting matrix is \n");
    for(i = 0; i < a.height; ++i)
    {
        for(j = 0; j < a.length; ++j)
        {
            printf("%d ",a.arr[(i * a.height) + j]);
        }
        printf("\n");
    }
    free(a.arr);
    free(b.arr);
    return 0;
}




















