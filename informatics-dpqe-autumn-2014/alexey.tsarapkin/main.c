#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define shift(letter, key, start, end)                                                          \
                                        if((letter >= start) && (letter <= end))                \
                                        letter = (letter - start + key) % 26 + start;

int read_cipher(char** result) {
        static char chunk_size = 5;

        int result_size = chunk_size;
        unsigned char result_length = 0;
        char character;

        *result = (char*)calloc(result_size + 1, sizeof(char));

        while((character = getchar()) != EOF && character != '\n') {
                result_length++;

                if(result_length > result_size) {
                        result_size += chunk_size;
                        if((*result = (char*)realloc((void*)(*result), result_size + 1)) == NULL)
                                return -1;
                        memset(*result + strlen(*result), '\0', chunk_size + 1);
                }

                (*result)[result_length - 1] = character;
        }

        if(strlen(*result) == 0)
                return -1;

        if(result_size > result_length) {
                if((*result = (char*)realloc((void*)(*result), result_length + 1)) == NULL)
                        return -1;
                (*result)[result_length] = '\0';
        }

        return 0;
}
int main()
{
    char* cipher;
    int i;
    int key;

    printf("Program Caesar cipher.\nEnter your message\n");
    read_cipher(&cipher);
    printf("Enter the key\n");
    scanf("%d", &key);

    for( i = 0 ; i < strlen(cipher) ; i++) {
        shift(cipher[i], key, 'a', 'z');
        shift(cipher[i], key, 'A', 'Z');
    }

    printf("Encrypted message:\n");
    printf("%s", cipher);

    return 0;
}
