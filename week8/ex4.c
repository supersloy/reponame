#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

#define _10MB 10*1024*1024

int main(int argc, char const *argv[])
{
	printf("Recomended memory amount: INFINITY.\n");
	void *ptr;
	struct rusage memUsage;
	int mem;
	while(1)
	{
		getrusage(RUSAGE_SELF,&memUsage);
		mem = memUsage.ru_maxrss;
		printf("Maximum resident set size used : %d kilobytes\n",mem);
		ptr = malloc(_10MB);
		memset(ptr	,0,_10MB);
		sleep(1);
	}
	return 0;
}	