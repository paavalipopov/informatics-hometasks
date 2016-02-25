#include <stdio.h>
#include <stdlib.h>

#define MAX = 1000

void enter_the_string(char* name);
void enter_the_substring(char* name);
void search_engine(char* name1,char* name2);

int main(){
    int j,i,n,k;
    char substring;
    char string;
    char c;
    void enter_the_string(char* string);
    void enter_the_substring(char* substring);
    void search_engine(char* string,char* substring);
    return 0;
    }

void enter_the_string(char* name){
    char c;
    int i,n;
    printf("Enter the string\n");
    while (c != '\n'){
        for (i = 0; i<5 ;i++){
            if (c = getchar() != '\n')
                break;
            if (i == 0)
                char name = (char*) malloc (5*sizeof(char));
            ++n;
        }
    }
}

void enter_the_substring(char* name){
    char c;
    int i,k;
    printf("Enter the string\n");
    while (c != '\n'){
        for (i = 0; i<5 ;i++){
            if (c = getchar() != '\n')
                break;
            if (i == 0)
                char name = (char*) malloc (5*sizeof(char));
            ++k;
        }
    }
}

void search_engine(char* name1,char* name2){
    int j,i,n,k;
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++)
            if (char name1[i+j] != char name2[j])
                break;
        if (j=k)
            printf("%d ",i);
    }
}
