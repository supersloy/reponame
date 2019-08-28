#include <stdio.h>
#include <string.h>
#define MAX_LINE 1024
int main(int argc, char const *argv[])
{
	char string[MAX_LINE];
	scanf("%s",string);
	unsigned int length = strlen(string);
	for (int i = length-1; i >= 0; --i)
		printf("%c",string[i]);
	printf("\n");
	return 0;
}