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
* @brief function to print array in descending order
******************************************************************************/
void sortDown()
{
    if (arr_size == 0)
    {
        printf("Empty Array\n");
    }
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[i] < arr[j])
            {
                uint8_t temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted the array in down\n");
}
