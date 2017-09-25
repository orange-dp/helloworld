center : memory.o dns.o

memory.o : memory.h

dns.o : dns.h

clean : 
	rm *.o *~
