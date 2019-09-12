#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LENGTH 256

int main(int argc, char const *argv[])
{
	char word[MAX_LENGTH];
	printf("Write \\q to exit.\n");
	while(1)
	{
		scanf("%s",word)
		if (word[0] == '\\' && word[1]=='q')
			break;
		system(word);
	}
	return 0;
}