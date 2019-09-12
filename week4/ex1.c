#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{	
	pid_t pid;
	int n = 1;
	if(pid = fork())
	{
		printf("Hello from parent [%d - %d]\n", getpid(), n);
	}
	else
	{
		printf("Hello from child [%d - %d]\n", pid, n);
	}
	return 0;
}