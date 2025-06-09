#include <stdio.h>
#include <string.h>
#include "fileManagement.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("You haven't entered anything yet\n");
        return 0;
    }
    
    char* filepath = argv[1];

    if (createFile(filepath) != 0)
    {
        return -1; 
    }

    menu();
    int option;

    while (1)
    {
        printf("Your choice: ");
        if (scanf_s("%d", &option) != 1) 
        {
            printf("Invalid input\n");
            while (getchar() != '\n'); /* Clear the input buffer */
            continue;
        }

        while (getchar() != '\n'); /* clear the newline character left in the buffer */

        switch (option)
        {
            case 1:
            {
                if (fileContent(filepath) == -1)
                {
                    printf("Error displaying file content\n");
                }
                break;
            }
            case 2:
            {
                char input[MAX_LENGTH];

                printf("Enter the string to add: ");

                if (fgets(input, sizeof(input), stdin) == NULL) 
                {
                    printf("Error reading input\n");
                    break;
                }

                input[strcspn(input, "\n")] = '\0'; /* Remove newline character if present */


                if (addString(filepath, input) == -1)
                {
                    printf("Error adding string\n");
                }
                break;
            }
            case 3:
            {
                char search[MAX_LENGTH];

                printf("Enter the string to search: ");
                fgets(search, sizeof(search), stdin);

                search[strcspn(search, "\n")] = '\0';   /* remove newline characters */

                int result = findString(filepath, search);

                if (result == -1)
                {
                    printf("Error finding string in file\n");
                }
                else if (result == 0)
                {
                    printf("Not Found\n");
                }
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