#include "memory.h"

void InitQueue(pBottom bottom){
	//*bottom = (pBottom)malloc(sizeof(Bottom));
	bottom->urlarr = (char **)malloc(sizeof(char*)*QUEUESIZE);
	assert(bottom->urlarr != NULL);
	memset(bottom->urlarr,0,sizeof(char*)*QUEUESIZE);
	bottom->depth = QUEUESIZE;
	bottom->top = 0;
}

int IsEmpty(const pBottom bottom){

	return bottom->top == 0 ? 1 : 0;
}

int Push(pBottom bottom,char *url){
	if(url == NULL || bottom == NULL || bottom->urlarr == NULL || strlen(url) == 0)
	{
		printf("fxxk!\n");
		return 0;
	}
	
	if(IsFull(bottom))
	{
		if(AddCap(bottom) == 0)
		{
			return 0;
		}
	}
	else
	{
		bottom->urlarr[bottom->top] = (char *)malloc(sizeof(char)*strlen(url));
		assert(bottom != NULL);
		strcpy(bottom->urlarr[bottom->top],url);
		bottom->top++;
		return 1;
	}
}

void Pop(pBottom bottom,char *rev){
	if(IsEmpty(bottom))
	{
		return ;
	}

	char *rvalue = bottom->urlarr[0];
	if(rev != NULL)
	{
		strcpy(rev,rvalue);
	}
	int i = 0;
	for(i = 0; i+1 < bottom->top; ++i)
	{
		bottom->urlarr[i] = bottom->urlarr[i+1];
	}
	free(rvalue);
	bottom->top--;
}

void PrintQueue(const pBottom bottom){
	if(bottom == NULL || IsEmpty(bottom))
	{
		return;
	}

	int i = 0;
	for(i = 0; i < bottom->top; ++i)
	{
		printf("%s\n",bottom->urlarr[i]);
	}
}
