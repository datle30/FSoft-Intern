#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdint.h>

/*******************************************************************************
* @brief functions provide instructions for using program features.
******************************************************************************/
void introduction();

/*******************************************************************************
* @brief function used to delete the array and enter a new value
******************************************************************************/
void clearArray();

/*******************************************************************************
* @brief function used to print array
******************************************************************************/
void printArray();

/*******************************************************************************
* @brief function to insert an element into the array at position k (if position k already contains a value, insertion is not allowed).
* @params a: index
* @params b: value
******************************************************************************/
void insertValue(int k, uint8_t value);

/*******************************************************************************
* @brief function to to delete the element at position k (if position k does not contain a value, it indicates there is no element at position k).
* @params a: index
******************************************************************************/
void deleteValue(int k);

/*******************************************************************************
* @brief function to print array in ascending order.
******************************************************************************/
void sortUp();

/*******************************************************************************
* @brief function to print array in descending order
******************************************************************************/
void sortDown();

/*******************************************************************************
* @brief function to search for number x in the array (x is entered from the keyboard) and display its position if found.
* @params a: value
******************************************************************************/
void searchValue(uint8_t value);

/*******************************************************************************
* @brief function to print the maximum number in the array.
******************************************************************************/
void printMax();

/*******************************************************************************
* @brief function to print the minimum number in the array.
******************************************************************************/
void printMin();

#endif /* _ARRAY_H_ */

