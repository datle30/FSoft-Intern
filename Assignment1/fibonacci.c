/* fibonacci.c */

#include "fibonacci.h"

unsigned int fibonacci(int n)
{
	if (n <= 0)
	{
		return 0;    /* There is no Fibonacci number 0th or less than 0 */
	}
	else if (n == 1)
	{
		return 1;    /* The first Fibonacci number is 1 */
	}
	else
	{
		int a = 0, b = 1, temp;
		for (int i = 1; i < n; i++)
		{
			temp = a + b;    /* Fibonancci number = previous num + next num */
			a = b;
			b = temp;
		}
		return b;    /* b is the Fibonacci number */
	}
}