#include <stdio.h>
#include "arrayCtrl.h"

/*******************************************************************************
* Array management program
* Includes 20 positions, values ​​from 0 - 100, options:
* 1. Enter a value into a specified element of the array
* 2. Remove a specific value from the array
* 3. Print the value of the elements entered into the array, in this option:
*    1. Print the values ​​entered into the array before sorting from low to high.
*    2. Print the values ​​entered into the array after sorting from low to high.
* 4. end the program
******************************************************************************/
int main(int argc, char* argv[])
{
    int option;
    int position;
    int sorted;
    uint8_t value;

    menu();

    while (1)
    {
       printf("Your choice: ");
       scanf_s("%d", &option);

       switch (option) 
       {
           case 1:
           {
               printf("Enter position (1-20): ");
               scanf_s("%d", &position);
               printf("Enter value (0-100): ");
               scanf_s("%hhu", &value);

               if (insertValue(position, value) == 0) 
               {
                   printf("The value %d has been added to position %d\n", value, position);
               }

               break;
           }
           case 2:
           {
               printf("Enter the value to delete (0-100): ");
               scanf_s("%hhu", &value);

               if (deleteValue(value) == 0) 
               {
                   printf("The value %d has been removed.\n", value);
               }

               break;
           }
           case 3:
           {
               printf("1. Print the values entered into the array before sorting from low to high.\n");
               printf("2. Print the values entered into the array after sorting from low to high.\n");
               printf("Your choice: ");
               scanf_s("%d", &sorted);
               printSort(sorted);

               break;
           }
           case 4:
           {
               printf("Exit\n");

               return 0;
           }
           default:
           {
               printf("Invalid option\n");

               break;
           }
       }
    }

    return 0;
}

