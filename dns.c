#include "dns.h"

DNSPacket* InitDNSPacket(char *domain_name){
	DNSPacket *dnsPacket = (DNSPacket *)malloc(sizeof(DNSPacket));
	assert(dnsPacket != NULL);

	//set Head
	dnsPacket->ID = 0x0000;
	dnsPacket->mark =0x0100;
	dnsPacket->num_ques = 0x0001;//question number
	dnsPacket->num_record = 0x0000;
	dnsPacket->num_author = 0x0000;
	dnsPacket->num_other = 0x0000;

	//set domain name
	char tmp[64] = {0};
	int i = 0;
	int j = 0;
	int count = 0;
	for(i = 0; i < strlen(domain_name); ++i)
	{
		if(domain_name[i] != '.')
		{
			tmp[j++] = domain_name[i];
		}
		else
		{
			dnsPacket->domain_name[count] = (char)j;
			memcpy((dnsPacket->domain_name)+1,tmp,j+1);
			memset(tmp,0,64);
			count+=j;
			j = 0;
		}
	}
	printf("%s",dnsPacket->domain_name);
	return dnsPacket;
}
