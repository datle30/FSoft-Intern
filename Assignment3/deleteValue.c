#include "array.h"

/*******************************************************************************
* Definitions
******************************************************************************/
#define MAX_SIZE 100

/*******************************************************************************
* Variables
******************************************************************************/
uint8_t arr[MAX_SIZE];
int arr_size = 0;

/*******************************************************************************
* @brief function to to delete the element at position k (if position k does not contain a value, it indicates there is no element at position k).
* @params a: index k
******************************************************************************/
void deleteValue(int k)
{
	if (k < 0 || k > MAX_SIZE)
	{
		printf("Invalid index[%d]\n", k);
	}
	if (arr_size == 0)
	{
		printf("Empty Array\n");
	}
	else
	{
		for (int i = k; i < arr_size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr_size--;
	}
	printf("Deleted element at position [%d]\n", k);
}