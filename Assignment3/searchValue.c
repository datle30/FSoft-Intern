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
* @brief function to search for number x in the array (x is entered from the keyboard) and display its position if found.
* @params a: value
******************************************************************************/
void searchValue(uint8_t value)
{
    int found = 0;

    if (arr_size == 0)
    {
        printf("Empty Array\n");
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == value)
        {
            printf("Number [%d] at position [%d]\n", value, i);
            found++;
        }
    }

    if (found == 0)
    {
        printf("Number [%d] was not found in the array\n", value);
    }
}
