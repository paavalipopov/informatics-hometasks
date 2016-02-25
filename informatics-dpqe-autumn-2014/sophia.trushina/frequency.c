#include <stdio.h>
#include <stdlib.h>


int read_string(char** result) {
	static int chunk_size = 5;
	int result_size = chunk_size;
	int result_length = 0;
	char character;

	*result = (char*)calloc(result_size + 1, sizeof(char));

	while((character = getchar()) != EOF && character != '\n') {
		result_length++;

		if(result_length > result_size) {
			printf("Maximum size of %d characters reached, reallocating memory. Current result: %s\n", result_size, *result);
			result_size += chunk_size;
			if((*result = (char*)realloc((void*)(*result), result_size + 1)) == NULL) {
				printf("Unable to allocate memory for input\n");
				return -1;
			}
			memset((*result + strlen(*result)), '\0', chunk_size + 1);
		}

		(*result)[result_length - 1] = character;
	}

	if(strlen(*result) == 0) {
		printf("Input string is empty\n");
		return -1;
	}

	if(result_size > result_length) {
		printf("Final reallocation memory for precise string length.\nBefore reallocation - %d\n", result_size);
		if((*result = (char*)realloc((void*)(*result), result_length + 1)) == NULL) {
			printf("Unable to allocate memory for input\n");
			return -1;
		}
		(*result)[result_length] = '\0';
		printf("After reallocation - %lu\n", strlen(*result));
	}

	return 0;
}

int frequency(char* str) {
	if(str == NULL) {
		printf("Wrong string\n");
		return -1;
	}
	int frequency[26];
	int chara, ch, j = 0;
	for (ch = 0; ch < 26; ch++)
		frequency[ch] = 0;

	for (;str[j] != '\0'; j++) {
		if(('a' <= str[j]) && (str[j] <= 'z') )
			frequency[str[j] - 'a']++;
		else if (('A' <= str[j]) && (str[j] <= 'Z'))
			frequency[str[j] - 'A']++;
		j++;
	}

	for (ch = 0; ch < 26; ch++)
		printf("%c - %d \n", 'a' + ch, frequency[ch]);

	return 0;
}

void free_memory(char* str) {
//	int j = 0;
//	for(; str[j] != '/0'; j++)
//		free(str[j]);
	free(str);
}

int main() {
	char* str;

	read_string(&str);
	frequency(str);
	free_memory(str);

    return 0;
}
