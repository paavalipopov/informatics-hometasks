#include <stdio.h>
#include <stdlib.h>

int main() {

	struct list {	
		
		struct address *next;
		struct address *previous;	
	}
}


void func(struct first *i, struct first **last)
{
	if(!*last) *last = i; 
	else (*last)->next = i;
	i->next = NULL;
	i->previous = *last;
	*last = i;
}
