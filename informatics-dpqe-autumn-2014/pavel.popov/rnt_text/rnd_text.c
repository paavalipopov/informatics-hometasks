#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i;
	srand(time(NULL));
	FILE* file;
	file = fopen("text", "w");

	for(i = 0; i < 1024*1024 ; i++)
		fprintf(file, "%d\n", rand());

	fclose(file);

	return 0;
}
