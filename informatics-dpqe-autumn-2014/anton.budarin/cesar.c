#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caesariation(char** result) {
    static char chunk_size = 5;
    char result_size = chunk_size;
    unsigned char result_length = 0;
    char character;
    
    *result = (char*)calloc(result_size + 1, sizeof(char));
 
    while((character = getchar()) != EOF && character != '\n') {
        result_length++;
 
        if(result_length > result_size) {
            result_size = chunk_size;
            if((*result = (char*)realloc((void*)(*result), result_size + 1)) == NULL) {
                printf("Unable to allocate memory for input\n");
                return -1;
            }
            memset(*result + strlen(*result), '\0', chunk_size + 1);
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
        printf("After reallocation - %zu\n", strlen(*result));
    }
    
    
    return 0;
}

int main(){
    char* msg;
    int key;
    int i;
    caesariation(&msg);
    printf("enter the key.\n");
    scanf("%d",&key);
    
    for(i = 0; i < strlen(msg); i++){
        
        if((msg[i] >= 'a')&&(msg[i] <= 'z')){
            msg[i] = ((msg[i] - 'a' - key + 26)%26 +'a');
        }
        
        if((msg[i]>='A')&&(msg[i]<='Z')){
            msg[i] = ((msg[i] - 'A' - key + 26 )%26 +'A');
        }
    }
    
    printf("%s\n", msg);
    return 0;
}
