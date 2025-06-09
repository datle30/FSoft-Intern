#include <stdio.h>
#include "fibonacci.h"

int main(int argc, char* argv[])
{
	int N;
	printf("The Fibonancci number you want: ");
	scanf_s("%d", &N);

	if (N < 1 || N > 100) 
	{
		printf("Error. Please try again.\n");
		return 1;
	}

	printf("The %d Fibonacci is %u", N, fibonacci(N));
	return 0;
}