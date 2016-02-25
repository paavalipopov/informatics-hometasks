#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
	FILE* fp = NULL;
	int* a;
	int i, p, k = 0;
	a = (int*)calloc(N, sizeof(int));
	fp = fopen("LOL", "w");
	srand(time(NULL));
	for (i = 0; i < N; i++) {
		fprintf(fp,"%d ", rand());
	}
	fclose(fp);
	fp = fopen("LOL", "r");
	for (i = 0; i < N; i++) {
		fscanf(fp, "%d ", &a[i]);
	}
	fclose(fp);
	for (i=1; i<N; i++) {
        k=a[i];
        p=i-1;
        while ((p>=0)&&(a[p]>k)){
            a[p+1]=a[p];
            a[p]=k;
            p=p-1;
        }
    }
	fp = fopen("RESULT", "w");
    for (i=0; i<N; i++) {
      fprintf(fp, "a[%d]=%d\n", i, a[i]);
    }
free(a);
fclose(fp);
return 0;
}
		
	
	
