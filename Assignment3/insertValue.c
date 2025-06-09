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
* @brief function to insert an element into the array at position k (if position k already contains a value, insertion is not allowed).
* @params a: index k
* @params b: value
******************************************************************************/
void insertValue(int k, uint8_t value)
{
	if (k < 0 || k > MAX_SIZE)
	{
		printf("Invalid index[%d]\n", k);
	}
	if (arr_size == MAX_SIZE)
	{
		printf("Array is full\n");
	}
	if (arr_size == 0)
	{
		printf("Empty Array\n");
	}
	if (k >= arr_size)
	{
		arr[arr_size++] = value;
	}
	else
	{
		for (int i = arr_size; i > k; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[k] = value;
		arr_size++;
	}
	printf("Inserted value [%d] into position [%d] of the array\n", value, k);
}