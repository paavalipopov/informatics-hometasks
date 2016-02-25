/*
 * main.c
 *
 *  Created on: Oct 18, 2014
 *      Author: nick
 */

#include <stdio.h>
int func(n1)
{
    int i=2,mark=0,n2=n1;
    for (;i<=n2/2;i++)
        {
            while(n1%i==0)
                {
                    printf("%d ",i);
                    n1=n1/i;
                    mark++;
                }
        }
    if (mark==0)
       printf("%d is prime",n2);
}
int main()
{
    int x=0;
    if (scanf("%d",&x)!=1||x<0)
    {
       printf("Error:'invalid type'");
       return -1;
    }
    func(x);
    return 0;
}
