#include <stdio.h>
#include <stdlib.h>

int listtwoerr;
int listtwook = 0;
intlisttwoempty = 1;
int listtwonomem = 2;
int listtwoend = 3;
int listtwobegin = 4;


typedef int listtwo; 

struct elementtwo {
	listtwo data;
	elementtwo *pred;
	elementtwo *next;
}

typedef struct {
	elementtwo *begin;
	elementtwo *end;
	elementtwo *prt;

void initlisttwo(listtwo *l) {
	l->begin = (elementtwo *) malloc(sizeof(elementtwo));
	if (!l->begin) {
		listtwoerr = listtwonomem;
	return;
	}
	l->end = (elementtwo *) malloc(sizeof(elementtwo));
	if (!l->end) {
		listtwoerr = listtwonomem;
	return;
	} 	

	l->begin->next = l->end;
	l->begin->pred = NULL;
	l->end->next = NULL;
	l->end->pred = l->begin;
	l->prt = l->begin;
	listtwoerr = listtwook;
}

int main() {
	data_type P;
scanf(%d %d %d\n, begin, pnt, P);
}
 
void addpred(listtwo *l, data_type P)  {
	if (l->prt == l->begin) {
		listtwoerr = listtwobegin;
		return;
	}
	
	elementtwo *pnr = (elementtwo *)malloc(sizeof(elementtwo));

	if (!pnt) {
		listtwoerr = listtwonomem;
		return;
	}

	pnt->data = P;
	pnt->next = l->prt->next;
	pnt->pred = l->prt;
	l->prt->next->pred = pnt;
	l->prt->next = pnt;
}

void addpost(listtwo *l, data_type P) {
	if (l->prt == l->end) {
		listtwoerr = listtwoend;
		return;
	elementtwo *pnt = (elementtwo *) malloc(sizeof(elementtwo));
	if (!pntr) {
		listtwoerr = listtwonomem;
		return;
	}

	pnt->data = P;
	pnt->next = l->prt->next;
	pnt->pred = l->prt;
	l->prt->next->pred = pnt;
	l->prt->next = pnt;
