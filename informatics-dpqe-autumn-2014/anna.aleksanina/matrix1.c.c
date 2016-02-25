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

void fill_matrix(matrix_t *a)
{
    int elements = a->height * a-> length;
    int i;
    for(i = 0 ; i < elements; ++i)
    {
        int error;
        error = scanf("%d", &a->arr[i]);
        if (error == 0)
        {
            printf("I'm sorry, I can't eat it:( \n");
        }
    }
}
void multiplication(matrix_t * a, matrix_t * b)// matrix c should be rewritten in matrix a
{
    int i, j, k;
    matrix_t c;
    create_new_matrix(a->height,b->length, &c);
    for( i = 0; i < a->height; ++i)
    {
        for( j = 0; j < b->length; ++j)
        {
            int sum = 0;
            for( k = 0; k < b->height; ++k)
            {
                sum = sum +( a->arr[(a->length * i +  k)]) * (b-> arr[(b->length * k) + j]); // -1 was deleted
            }
            c.arr[(c.length * i) + j] = sum;
            sum = 0;
        }
    }
    free(a->arr);
    create_new_matrix(c.height,c.length, a);
    a->arr = c.arr;
}

int main()
{
    int number,i,j, height, length;
    matrix_t a, b;
    int mistake;
    mistake = scanf("%d", &number);
    if (mistake == 0)
    {
        printf("I'm sorry, I can't eat it:( \n");
    }
    if ((number == 0)||(number == 1))
    {
        printf("not enough matrixes\n");
        return -1;
    }
    mistake = scanf("%d %d",&height, &length);
    if (mistake == 0)
    {
        printf("I'm sorry, I can't eat it:( \n");
    }
    create_new_matrix(height,length, &a);
    fill_matrix(&a);
    for(i = 1; i < number; ++i )
    {
        mistake = scanf("%d  %d",&height, &length);
        if (mistake == 0)
        {
            printf("I'm sorry, I can't eat it:( \n");
        }
        if (a.length != height)
        {
            printf("Error: multiplication impossible\n");
            return -1;
        }
        //free(b.arr);
        create_new_matrix(height,length, &b);
        fill_matrix(&b);
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












