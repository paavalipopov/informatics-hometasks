#include<stdio.h>
int main(){
int i = 0;
int j = 0;
int a;
int m;
int k;
char substring[1000];
char string[1000];
char c;
printf("Enter the substring\n");
while ((c = getchar()) != '\n' ){
    substring[i] = c;
    ++i;
}
printf("Enter the string\n");
while ((c = getchar()) != '\n' ){
    string[j] = c;
    ++j;
}
for (k=0;k<=j-1;k++){
    a = 0;
    for (m=k;m<=i+k-1;m++){
        if(string[m] == substring[a])
            a++;
        else break;
    }
    if (a>=i)
        printf("%d ",k);
}
return 0;
}
