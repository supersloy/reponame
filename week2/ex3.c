#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*n-1; ++j)
		{
			//Some math magic in ternary operator :)
			printf("%c", j>=n-i-1 && j<=n-1+i ? '*':' ');
		}
		printf("\n");
	}
	return 0;
}