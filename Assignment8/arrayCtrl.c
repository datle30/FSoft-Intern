#include <stdio.h>
#include <stdlib.h>
#include "arrayCtrl.h"

/*******************************************************************************
* Global Variables
******************************************************************************/
uint8_t assignment4[MAX_SIZE] = { 0xFF, };
Node* head = NULL;

/*******************************************************************************
* @brief function to enter a value into a specified element of the array
* @params a: position of the element
* @params b: value of the element
* @return: 0 on success, -1 on error
******************************************************************************/
int insertValue(int position, uint8_t value) 
{
    if (position < 0 || position > MAX_SIZE) 
    {
        printf("Please enter the position in interval from 1 to 20\n");
        return -1;
    }
    if (assignment4[position] != 0) 
    {
        printf("The position is full\n");
        return -1;
    }
    if (value > MAX_VALUE) 
    {
        printf("Please enter a value between 0 and 100\n");
        return -1;
    }
    for (int i = 1; i <= MAX_SIZE; i++) 
    {
        if (assignment4[i] == value) 
        {
            printf("The value already exists in the array\n");
            return -1;
        }
    }

    assignment4[position] = value;
    addToList(value);

    return 0;
}

/*******************************************************************************
* @brief function to remove a specific value from the array
* @params a: value
* @return: 0 on success, -1 on error
******************************************************************************/
int deleteValue(uint8_t value) 
{
    if (value > MAX_VALUE) 
    {
        printf("Please enter a value between 0 and 100\n");
        return -1;
    }

    int found = 0;

    for (int i = 1; i <= MAX_SIZE; i++) 
    {
        if (assignment4[i] == value) 
        {
            assignment4[i] = 0xFF;
            found = 1;
            break;
        }
    }
    if (found == 0) 
    {
        printf("The value does not exist in the array\n");
        return -1;
    }

    deleteFromList(value);

    return 0;
}

/*******************************************************************************
* @brief function to add value to linked list
* @params a: value
* @return: 0 on success, -1 on error
******************************************************************************/
int addToList(uint8_t value) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) 
    {
        printf("Error\n");
        return -1;
    }

    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL) 
    {
        head = new_node;
    }
    else 
    {
        Node* current = head;
        while (current->next != NULL) 
        {
            current = current->next;    /* add value to the end of the list */
        }
        current->next = new_node;
    }
    return 0;
}

/*******************************************************************************
* @brief function to remove values ​​from linked list
* @params a: value
* @return: 0 on success, -1 on error
******************************************************************************/
int deleteFromList(uint8_t value) 
{
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->value != value)  /* go through all the elements in the list */
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("The value does not exist in the linked list\n");
        return -1;
    }

    if (prev == NULL) 
    {
        head = current->next;
    }
    else 
    {
        prev->next = current->next;
    }

    free(current);
    return 0;
}

/*******************************************************************************
* @brief function to print a linked list,
* select 1 to print an unsorted linked list,
* select 2 to print a linked list sorted from low to high
******************************************************************************/
void printSort(int sorted)
{
    if (sorted == 1) 
    {
        if (head == NULL) 
        {
            printf("Empty array\n");
        }
        else
        {
            printf("Values before sorting:\n");

            for (int i = 1; i <= MAX_SIZE; i++)
            {
                if (assignment4[i] != 0)
                {
                    printf("[%d] ", assignment4[i]);
                }
            }
            printf("\n");
        }
    }
    else if (sorted == 2)
    {
        if (head == NULL) 
        {
            printf("Empty array\n");
        }
        else
        {
            Node* current;
            Node* next;
            int temp;

            /* current = head then move current to the next node until current = NULL */
            for (current = head; current != NULL; current = current->next)
            {
                /* next = node after head then move current to next node until next = NULL */
                for (next = current->next; next != NULL; next = next->next)
                {
                    /* compare the values ​​of current and next */
                    if (current->value > next->value)
                    {
                        temp = current->value;
                        current->value = next->value;
                        next->value = temp;
                    }
                }
            }

            printf("Values after sorting from low to high:\n");
            printList();
        }
    }
    else 
    {
        printf("Invalid choice\n");
    }
}

/*******************************************************************************
* @brief function to prints the values ​​of the elements entered into the array
******************************************************************************/
void printList() 
{
    Node* current = head;
    while (current != NULL) 
    {
        printf("[%d] ", current->value);
        current = current->next;
    }
    printf("\n");
}

/*******************************************************************************
* @brief function to prints out the functions to choose from
******************************************************************************/
void menu()
{
    printf("Array management program\n");
    printf("Option:\n");
    printf("1. Enter a value into a specified element of the array\n");
    printf("2. Remove a specific value from the array\n");
    printf("3. Print the value of the elements entered into the array, in this option:\n");
    printf("   1. Print the values entered into the array before sorting from low to high.\n");
    printf("   2. Print the values entered into the array after sorting from low to high.\n");
    printf("4. End the program\n");
}