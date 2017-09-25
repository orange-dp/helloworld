//all function which type is 'int' 
//return 0 : false and return 1 : true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define QUEUESIZE 96

typedef struct Queue_bottom
{
	char **urlarr;
	int depth;
	int top;
}Bottom,*pBottom;

static int IsFull(const pBottom bottom){

	return bottom->top == bottom->depth ? 1 : 0;
}

static int AddCap(pBottom que){

	return 1;	
}

void InitQueue(pBottom bottom);

int IsEmpty(const pBottom bottom);

int Push(pBottom bottom,char *url);

void Pop(pBottom bottom,char *rev);

void PrintQueue(const pBottom bottom);
