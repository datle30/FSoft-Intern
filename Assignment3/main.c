#include <stdio.h>
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
char choice;
int k;
uint8_t value;

/*******************************************************************************
* Array Management Program
* The array consists of 100 elements. Valid values are in the range of 0 - 100
* 'c' to clear the data of the current array and allow the user to input new values
* 'p' to print the array
* 'i' to insert an element into the array at position k
* 'd' to delete an element at position k
* 's' to print the array in ascending order
* 'x' to print the array in descending order
* 't' to search for a number x in the array and display its position
* 'a' to print the largest number in the array
* 'w' to print the smallest number in the array
* 'e' to exit the program
* Exception: Empty Array, Invalid index, Invalid Value,...
******************************************************************************/
int main(int argc, char* argv[])
{
    introduction();

    while (1) {
        printf("Please select function: ");
        scanf_s("%c", &choice);

        switch (choice) {
        case 'c':
            clearArray();
            break;
        case 'p':
            printArray();
            break;
        case 'i':
            printf("Location you want to insert: ");
            scanf_s("%d", &k);
            printf("Value you want to insert: ");
            scanf_s("%hhu", &value);
            insertValue(k, value);
            break;
        case 'd':
            printf("Location you want to delete: ");
            scanf_s("%d", &k);
            deleteValue(k);
            break;
        case 's':
            sortUp();
            break;
        case 'x':
            sortDown();
            break;
        case 't':
            printf("Enter the number to search: ");
            scanf_s("%hhu", &value);
            searchValue(value);
            break;
        case 'a':
            printMax();
            break;
        case 'w':
            printMin();
            break;
        case 'e':
            printf("Exit.\n");
            return 0;
        default:
            printf("Invalid feature. Please select again\n");
            break;
        }
    }
	
	return 0;
}