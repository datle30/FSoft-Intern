#include <stdio.h>
#include <stdlib.h>
#include "pointer.h"

/*******************************************************************************
* program that dynamically allocates 10 bytes of memory for a pointer
* he function prototype provided as follows:
* #include <stdint.h>
* #include <stdbool.h>
* bool allocate10Bytes(uint8_t* outPtr)
* outPtr: output pointer
* return: true: if successful, false: if unsuccessful.
******************************************************************************/
int main(int argc, char* argv[])
{
    uint8_t* outPtr = NULL;

    printf("%s, p addr = [%p]\n", __FUNCTION__, outPtr);

    if (allocate10Bytes((uint8_t*) &outPtr)) 
    {
        printf("Memory allocated successfully.\n");

        printf("%s, p addr = [%p]\n", __FUNCTION__, outPtr);

        for (int i = 0; i < 10; i++)
        {
            outPtr[i] = i;
        }

        for (int i = 0; i < 10; i++)
        {
            printf("outPtr[%d] = %d\n", i, outPtr[i]);
        }

        free(outPtr);
    }
    else 
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}