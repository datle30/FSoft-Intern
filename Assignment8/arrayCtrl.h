#ifndef _ARRAY_CTRL_H_
#define _ARRAY_CTRL_H_

#include <stdint.h>

/*******************************************************************************
* Definitions
******************************************************************************/
#define MAX_SIZE 20
#define MAX_VALUE 100

typedef struct Node
{
    uint8_t value;
    struct Node* next;
} Node;

/*******************************************************************************
* Variables
******************************************************************************/
extern uint8_t assignment4[MAX_SIZE];
extern Node* head;

/*******************************************************************************
* @brief function to enter a value into a specified element of the array
* @params a: position of the element
* @params b: value of the element
* @return: 0 on success, -1 on error
******************************************************************************/
int insertValue(int position, uint8_t value);

/*******************************************************************************
* @brief function to remove a specific value from the array
* @params a: value 
* @return: 0 on success, -1 on error
******************************************************************************/
int deleteValue(uint8_t value);

/*******************************************************************************
* @brief function to add value to linked list
* @params a: value 
* @return: 0 on success, -1 on error
******************************************************************************/
int addToList(uint8_t value);

/*******************************************************************************
* @brief function to remove values ​​from linked list
* @params a: value
* @return: 0 on success, -1 on error
******************************************************************************/
int deleteFromList(uint8_t value);

/*******************************************************************************
* @brief function to print a linked list, 
* select 1 to print an unsorted linked list, 
* select 2 to print a linked list sorted from low to high
******************************************************************************/
void printSort(int sorted);

/*******************************************************************************
* @brief function to prints the values ​​of the elements entered into the array
******************************************************************************/
void printList();

/*******************************************************************************
* @brief function to prints out the functions to choose from
******************************************************************************/
void menu();

#endif // _ARRAY_CTRL_H_

