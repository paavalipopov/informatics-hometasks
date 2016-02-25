#include <stdio.h>
#include <stdlib.h>

int main()
{ int a;
  char c,c1;
   c='\n';
    scanf("%x%c",&a,&c);
     printf("%c",c1);

    if (c!='\n') {printf("Invalid input number");}
    else
    printf("%d",a);
    return 0;
}
