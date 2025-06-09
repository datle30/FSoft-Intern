#include "prime.h"

/*******************************************************************************
* @brief function to check if number is prime
* @params a: the number
* @return: error: -1, pass: 0
******************************************************************************/
int checkPrime(int num)
{
	if (num <= 1)
	{
		return -1;
	}
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return -1;
		}
	}
	return 0;
}

