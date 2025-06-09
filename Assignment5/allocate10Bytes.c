#include "pointer.h"
#include <stdlib.h>

/*******************************************************************************
* @brief the function dynamically allocates 10 bytes of memory for a pointer
* @params a: pointer outPtr
* @return: true: if successful, false: if unsuccessful
******************************************************************************/
bool allocate10Bytes(uint8_t* outPtr) 
{
    if (outPtr == NULL) 
    {
        return false;
    }

    uint8_t* tempPtr = (uint8_t*)malloc(10 * sizeof(uint8_t)); /* Dynamic memory allocation for Temp pointer */

    printf("%s, p addr = [%p]\n", __FUNCTION__, outPtr);

    if (tempPtr == NULL) 
    {
        return false;
    }

    *(uint8_t**)outPtr = tempPtr;   /* Assign the allocated Temp pointer to the outPtr pointer */

    return true;
}