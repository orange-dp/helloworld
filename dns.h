#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct DNSPacket{
	uint16_t ID;
	uint16_t mark;
	uint16_t num_ques;
	uint16_t num_record;
	uint16_t num_author;
	uint16_t num_other;
	char domain_name[64];
}DNSPacket;

DNSPacket* InitDNSPacket(char *domain_name);	
