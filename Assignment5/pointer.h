#ifndef _POINTER_H_
#define _POINTER_H_

#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************
* @brief the function dynamically allocates 10 bytes of memory for a pointer
* @params a: pointer outPtr
* @return: true: if successful, false: if unsuccessful
******************************************************************************/
bool allocate10Bytes(uint8_t* outPtr);

#endif /* _POINTER_H_ */
