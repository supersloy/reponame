#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i)
	{
		fork();
	}
	system("sleep 5");
	return 0;
}