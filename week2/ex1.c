#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	int _int = INT_MAX;
	float _float = FLT_MAX;
	double _double = DBL_MAX;

	printf("Size of int: %lu | Value of int: %d\n", sizeof(_int), _int);
	printf("Size of float: %lu | Value of float: %f\n", sizeof(_float), _float);
	printf("Size of double: %lu | Value of double: %f\n", sizeof(_double),_double);

	return 0;
}