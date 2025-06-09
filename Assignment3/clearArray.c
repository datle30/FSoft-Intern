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
* @brief function used to delete the array and enter a new value
******************************************************************************/
void clearArray()
{
    if (arr_size == 0)
    {
        printf("Empty Array\n");
    }

    arr_size = 0;
    printf("The array has been deleted, please enter a new value for the array\n");

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int value;

        printf("Enter a value for number [%d] (0-100, or -1 to stop): ", i + 1);

        scanf("%d", &value);

        if (value == -1) {
            break;
        }
        else if (value >= 0 && value <= 100) {
            arr[i] = (uint8_t)value;
            arr_size++;
        }
        else {
            printf("Invalid value. Please enter again\n");
            i--; /* Retain the current position to enter again */
        }
    }
}