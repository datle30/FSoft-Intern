#include <stdio.h>
#include "studentManagement.h"
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
* @brief function prints out the console menu to use the feature
******************************************************************************/
void menu()
{
	printf("a. Add Student\n");
	printf("d. Delete Student\n");
	printf("f. Find Student\n");
	printf("p. Print All Students\n");
	printf("e. Exit\n");
}

/*******************************************************************************
* @brief function to create new students
* @params a: student name
* @params b: student id code
* @params c: student scores
******************************************************************************/
Student* createStudent(char* name, int id, float score)	
{
	Student* newStudent = (Student*)malloc(sizeof(Student));

	strcpy_s(newStudent->name, 99, name);

	newStudent->id = id;

	newStudent->score = score;

	newStudent->next = NULL;

	return newStudent;
}

/*******************************************************************************
* @brief function to add a new student to the beginning of a linked list of students
* @params a: pointer to the pointer to the beginning of the student list
* @params b: pointer to a character array containing the new student's name
* @params c: new student id code.
* @params d: new student scores
******************************************************************************/
void addStudent(Student** head, char* name, int id, float score)
{
	Student* newStudent = createStudent(name, id, score);

	newStudent->next = *head;

	*head = newStudent;
}

/*******************************************************************************
* @brief function used to remove students from the linked list
* @params a: pointer to the pointer to the beginning of the student list
* @params b: student's ID code needs to be deleted
******************************************************************************/
void deleteStudent(Student** head, int id)
{
	Student* temp = *head;	/* creates a temporary pointer to head */
	Student* prev = NULL;	/* pointer to save previous student */

	if (temp != NULL && temp->id == id) /* if the list is not empty and the student to be deleted is the first student */
	{
		*head = temp->next;	/* head points to the next student */
		free(temp);
		return;
	}

	while (temp != NULL && temp->id != id) /* list is not empty */
	{
		prev = temp;	/* prev to point to current student (temp) */
		temp = temp->next; /* move temp to next student (temp->next) */
	}

	if (temp == NULL)	/* browsed through the list but could not find the student */
	{
		return;
	}

	prev->next = temp->next; /* skip students that need to be deleted from the list */

	free(temp);
}

/*******************************************************************************
* @brief function used to find students in a linked list
* @params a: pointer to the pointer to the beginning of the student list
* @params b: student's ID code needs to be found
******************************************************************************/
Student* findStudent(Student* head, int id)
{
	Student* current = head; /* starting from the first student */

	while (current != NULL)
	{
		if (current->id == id)	/* find student with id */
		{
			return current;
		}
		else
		{
			current = current->next;	/* move to the next student */
		}
	}

	return NULL;	/* if the student is not found */
}

/*******************************************************************************
* @brief function to print student information
******************************************************************************/
void printStudent(Student* student)
{
	if (student != NULL) 
	{
		printf("Name: %s\n", student->name);
		printf("ID: %d\n", student->id);
		printf("Score: %.2f\n", student->score);
	}
	else 
	{
		printf("Student not found.\n");
	}
}

/*******************************************************************************
* @brief function used to print the student list
* @params a: pointer to the pointer to the beginning of the student list
******************************************************************************/
void printAllStudents(Student* head)
{
	Student* current = head;	/* starting from the first student */ 

	while (current != NULL) 
	{
		printStudent(current); 
		current = current->next;	/* move to the next student */
	}
}