#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_LENGTH 256
#define MAX_NUMBER_OF_ARG 15

int main(int argc, char const *argv[])
{
	char line[MAX_LENGTH];
	char* line_p;
	char *args[MAX_NUMBER_OF_ARG];
	char word[MAX_LENGTH];
	int i=2;
	args[0] = "sh";
	args[1]="-c";

	printf("Write \\q to exit.\n");

	while(1)
	{
		fgets(line, sizeof(line), stdin);
		line_p = line;

		while (strlen(line_p)!=0){
			sscanf(line_p, "%s", word);
			line_p+=strlen(word)+1;
			args[i] = word;
			i++;
		}
		args[i]=(char*)NULL;
		
		if (line[0] == '\\' && line[1]=='q')
			break;
		else
		{
			if(fork()==0)
				{
					execv("/bin/sh",args);
					exit(0);//Rest in peace
				}
		}
	}
	return 0;
}

