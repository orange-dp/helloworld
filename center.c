#include "memory.h"
#include "dns.h"

int Entry(Bottom *queue,char *url)
{
	if(!Push(queue,url)) 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void ParserUrl(pBottom waitQueue)
{

}

int main()
{
	Bottom waitQueue;
	Bottom doneQueue;
	InitQueue(&waitQueue);
	InitQueue(&doneQueue);
	
	char url[100] = {0};

	Entry(&waitQueue,"http://baidu.com");
	Entry(&waitQueue,"http://google.com");
	PrintQueue(&waitQueue);
	printf("\n");
	Pop(&waitQueue,url);
	//Push(&doneQueue,url);
	PrintQueue(&waitQueue);
	printf("\n");
	//PrintQueue(&doneQueue);
	Pop(&waitQueue,url);
	PrintQueue(&waitQueue);
	
	InitDNSPacket("wwww.baidu.com");

	return 0;
}
