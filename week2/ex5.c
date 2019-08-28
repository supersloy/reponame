#include <stdio.h>
void print_pyramid(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*n-1; ++j)
		{
			//Some math magic in ternary operator :)
			printf("%c", j>=n-i-1 && j<=n-1+i ? '*':' ');
		}
		printf("\n");
	}
}

void print_right_triangle(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%c", j<=i ? '*':' ');
		}
		printf("\n");
	}
}

void print_isosceles_triangle(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%c", j<=i && j+i<n ? '*':' ');
		}
		printf("\n");
	}
}

void print_square(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int n, print_mod;

	printf("Write number of rows: ");
	scanf("%d",&n);
	printf("Write number of the figure (1-pyramid, 2-right triangle, 3-isosceles triangle, 4-square): ");
	scanf("%d",&print_mod);
	switch(print_mod)
	{
		case 1:
			print_pyramid(n);
			break;
		case 2:
			print_right_triangle(n);
			break;
		case 3:
			print_isosceles_triangle(n);
			break;
		case 4:
			print_square(n);
			break;
		default:
			printf("Number is incorect. Pyramid figure choosen.\n");
			print_pyramid(n);
	}

	return 0;
}