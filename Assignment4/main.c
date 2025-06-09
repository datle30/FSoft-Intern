#include <stdio.h>
#include "prime.h"

/*******************************************************************************
* Global Variables
******************************************************************************/
char input[100]; /* Mang luu input */
int num1;
int num2;
int num3;
int count = 0;

/*******************************************************************************
* Program to check if two numbers are prime
* Exceptions: user does not enter anything, user enters characters, user enters 1 number, user enters more than 2 numbers
******************************************************************************/
int main(int argc, char* argv[])
{
	while (1)
	{
		printf("Input: ");

		fgets(input, sizeof(input), stdin);

		count = sscanf_s(input, "%d %d %d", &num1, &num2, &num3); /* Search for 3 integers in the input and allocate to num1, num2, num3 */
		
		if (count < 0)
		{
			printf("You haven't entered anything yet\n");
			help();
		}
		else if (count == 0)
		{
			printf("You have entered the character\n");
			help();
		}
		else if (count == 1)
		{
			printf("You enter only 1 number\n");
			help();
		}
		else if (count > 2)
		{
			printf("You enter more than 2 numbers\n");
			help();
		}
		else
		{
			if (checkPrime(num1) == 0)
			{
				printf("[%d] is prime\n", num1);
			}
			else
			{
				printf("[%d] is not prime\n", num1);
			}
			if (checkPrime(num2) == 0)
			{
				printf("[%d] is prime\n", num2);
			}
			else
			{
				printf("[%d] is not prime\n", num2);
			}
		}
	}

	return 0;
}