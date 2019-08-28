#include <stdio.h>

void swap(int *foo, int *bar)
{
	int temp = *foo;
	*foo = *bar;
	*bar = temp;
}

int main(int argc, char const *argv[])
{
	int foo, bar;
	printf("Write two numbers separated by space: ");
	scanf("%d %d",&foo,&bar);

	swap(&foo,&bar);

	printf("Swapped numbers: %d %d\n", foo, bar);
	return 0;
}