#include<stdio.h>
#include<stdlib.h>

typedef int newtp;
struct node
{
  newtp data;
  node *next;
  node *pred;
} *First=NULL;
void push(newtp val,int pos)// это я хочел проделать для каждого элемента второго списка, но не получилось
{
  node *a=new node;
  a-&gt;data=val;
  if(First==NULL)
    {
      a-&gt;next=a;
      a-&gt;pred=a;
      First=a;
}
else
  {
    node *t=First;
    for(int i=pos;i&gt;1;i--,t=t-&gt;next);
    t-&gt;pred-&gt;next=a;
    a-&gt;pred=t-&gt;pred;
    a-&gt;next=t;
    t-&gt;pred=a;
  }
}
delete First;
First=NULL;
}
elsenode *t=First;
for(int i=pos;i&gt;1;i--,t=t-&gt;next);
if(t==First)First=t-&gt;next;
t-&gt;pred-&gt;ne
void view()
{
if(First==NULL)return ;
node *a=First;
do
{
printf (&quot;Value=%d \n&quot;,(int)a-&gt;data);
a=a-&gt;next;
}while(a!=First);
}
