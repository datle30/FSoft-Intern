#include <stdio.h>
#include "studentManagement.h"

/*******************************************************************************
* Student management program includes the following information:
* Student's name
* Student ID
* Math scores
* Implement dashboard menu to use add, delete, find students by id feature
******************************************************************************/
int main(int argc, char* argv[])
{
    Student* head = NULL;   /* initialize an empty student list */

    addStudent(&head, "Dat", 1, 9.5);

    char choice;
    int id;
    char name[100];
    float score;

    menu();

    while (1)
    {
        printf("Enter your choice: ");
        scanf_s(" %c", &choice);

        switch (choice) 
        {
            case 'a':
            {
                //printf("Enter name: ");  /*Phan nay loi em chua fix duoc*/
                //scanf_s("%99s", &name);
                printf("Enter ID: ");
                scanf_s("%d", &id);
                printf("Enter score: ");
                scanf_s("%f", &score);
                /*addStudent(&head, name, id, score); */ 
                // vi du em de la addStudent(&head, "Hello", id, score); thi nhap id va score thi add binh thuong
                addStudent(&head, "Student", id, score);
                break;
            }
            case 'd':
            {
                printf("Enter student ID to delete: ");
                scanf_s("%d", &id);
                deleteStudent(&head, id);
                break;
            }
            case 'f':
            {
                printf("Enter student ID to find: ");
                scanf_s("%d", &id);
                Student* student = findStudent(head, id);
                printStudent(student);
                break;
            }
            case 'p':
            {
                printAllStudents(head);
                break;
            }
            case 'e':
            {
                exit(0);
            }
            default:
            {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}