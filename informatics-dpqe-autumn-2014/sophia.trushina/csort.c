#include <stdlib.h>
#include <stdio.h>

void maxmin (int* max, int* min, int arr[], int n) {

    int i = 0;

    *max = arr[1];
    *min = arr[1];

    for (; i < n; i++) {

        if (arr[i] > *max) {
            *max = arr[i];
        }

        if (arr[i] < *min) {
            *min = arr[i];
        }

    }

    }

void countsort (int* arr, int length, int max, int min)

  {
      int count[max-min+1];

      int i = min;

      for (i; i <= max; i++) {

        count[i - min] = 0;

      }

      i = min;

      int j;

      for (j = 0; i < length; i++) {

        count[arr[i] - min];

      }

      for (i; i <= max; i++) {

        for(j = count[i - min]; j--;) {

            *arr++ = i;

        }

      }
  }

int main() {

    int n = 0;

    int m, max, min, i, j;

    scanf ("%d", n); //length

    int *arr = (int*)calloc(n, sizeof(int));

      for (i = 0; i < n; i++) {

        scanf("%d", &arr[i]);

	    }

    maxmin (&max, &min, arr, n);

    countsort (arr, n, max, min);

    for (j = 0; j < n; j++) {

            printf ("%d", arr[i]);

    }

}

