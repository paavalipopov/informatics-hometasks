#include <stdio.h>
#include <stdlib.h>

#include "linear_matrix.h"

typedef long double data_type;
#define DATA_FORMAT "%Lf"


static int compare_floats(long double first, long double second) {
	return 0;
}

int solve_matrix() {
    int n = 0;
	data_type** A = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
	data_type tmp = 0.0;
	data_type* ptr = NULL;

    scanf("%d", &n);
	A = (data_type**)calloc(n, sizeof(data_type*));
    for(i = 0; i < n; i++) {
		A[i] = (data_type*)calloc(n + 1, sizeof(data_type));
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n + 1; j++) {
			scanf(DATA_FORMAT, A[i] + j);
        }
    }

    for(i = 0; i < n; i++) {
        if(A[i][i] != 0.0L) {
            tmp = A[i][i];
            for(j = 0; j < n + 1; j++) {
				A[i][j] = A[i][j]/tmp;
            }
            for(k = 0; k < n; k++) {
                if(k != i) {
                    tmp = A[k][i];
                    for(j = 0; j < n + 1; j++) {
                        A[k][j] = A[k][j] - A[i][j]*tmp;
                    }
                }
            }
        } else {
            for(j = i + 1; j < n; j++) {
				if (A[j][i] != 0.0L) {
                    ptr = A[j];
                    A[j] = A[i];
                    A[i] = ptr;
                    i--;
                    break;
                }
            }
        }
    }
    for(i = 0; i < n; i++) {
        k = 0;
        for(j = 0; j < n; j++) {
			if (A[i][j] != 0.0L)
				k = 1;
        }
        if(k == 0) {
            printf("NO\n");
            goto free_memory;
        }
    }
    for(j = 0; j < n; j++) {
        printf(DATA_FORMAT "\n", A[j][n]);
    }
free_memory:
    for(i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
