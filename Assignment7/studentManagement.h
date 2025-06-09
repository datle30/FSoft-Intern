#ifndef _STUDENT_MANAGEMENT_H_
#define _STUDENT_MANAGEMENT_H_

/*******************************************************************************
* Definitions
******************************************************************************/
typedef struct Student
{
	char name[100];
	int id;
	float score;
	struct Student *next;
} Student;

/*******************************************************************************
* @brief function prints out the console menu to use the feature
******************************************************************************/
void menu();

/*******************************************************************************
* @brief function to create new students
* @params a: student name
* @params b: student id code
* @params c: student scores
******************************************************************************/
Student* createStudent(char* name, int id, float score);

/*******************************************************************************
* @brief function to add a new student to the beginning of a linked list of students
* @params a: pointer to the pointer to the beginning of the student list
* @params b: pointer to a character array containing the new student's name
* @params c: new student id code
* @params d: new student scores
******************************************************************************/
void addStudent(Student** head, char* name, int id, float score);

/*******************************************************************************
* @brief function used to remove students from the linked list
* @params a: pointer to the pointer to the beginning of the student list
* @params b: student's ID code needs to be deleted
******************************************************************************/
void deleteStudent(Student** head, int id);

/*******************************************************************************
* @brief function used to find students in a linked list
* @params a: pointer to the pointer to the beginning of the student list
* @params b: student's ID code needs to be found
******************************************************************************/
Student* findStudent(Student* head, int id);

/*******************************************************************************
* @brief function to print student information
******************************************************************************/
void printStudent(Student* student);

/*******************************************************************************
* @brief function used to print the student list
* @params a: pointer to the pointer to the beginning of the student list
******************************************************************************/
void printAllStudents(Student* head);

#endif // _STUDENT_MANAGEMENT_H_

