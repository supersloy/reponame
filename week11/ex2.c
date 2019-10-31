#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	char buffer[5]="";
	const char text[5] = "Hello";
	setvbuf(stdout,buffer,_IOLBF,5);

	for (int i = 0; i < 5; ++i)
	{
		printf("%c",text[i]);
		/*
		Just for memes, I've tried put that printf with ternary expressions,
		but compiler optimize my code in such way that "H" is put in output
		before it check buffer on fullfillness. Unlucky :(

		printf(i<4? i<2? i<1? "H" : "e" : "l" : "o");
		*/
		sleep(1);
	}
	printf("\n");
	return 0;
}