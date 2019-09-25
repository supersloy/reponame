#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_LENGTH 50
int main(int argc, char const *argv[])
{
	int p[2];
	char *string1="Look at my string, my string is amazing.", string2[MAX_LENGTH];
	if(pipe(p)<0)
		return -1;

	write(p[1], string1, MAX_LENGTH);
	printf("String written in pipe from first string.\n");


	int pid = fork();

	if (pid==0)
	{
		read(p[0], string2, MAX_LENGTH);
		printf("String read from pipe in second string in child thread: %s\n", string2);
	}

	return 0;
}