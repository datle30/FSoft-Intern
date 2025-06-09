#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileManagement.h"

/*******************************************************************************
* @brief function to print out functions
******************************************************************************/
void menu()
{
	printf("File Management Program\n");
	printf("Option:\n");
	printf("1. Print out the contents of the file\n");
	printf("2. Add the string to the end of the file\n");
	printf("3. Find the string in the file\n");
	printf("4. Exit\n");
}

int createFile(char* filepath)
{
	FILE* file = NULL;
	errno_t err;

	err = fopen_s(&file, filepath, "r"); /* open the file for reading */

	if (err == 0 && file != NULL)
	{
		fclose(file);	/* file exists */
		return 0;
	}
	else
	{
		err = fopen_s(&file, filepath, "w");	/* create file */
		if (err != 0 || file == NULL)
		{
			perror("Error creating file");
			return -1; 
		}

		fclose(file);
		printf("File created successfully.\n", filepath);
		return 0;
	}
}

/*******************************************************************************
* @brief function to print the contents of the file
* @params a: file path
* @return: 0 on success, -1 on error
******************************************************************************/
int fileContent(char* filepath)
{
	FILE* file = fopen(filepath, "r+");	/* read the file */

	if (file == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}

	char line[MAX_LENGTH];	/* variable to store each line of the file */

	while (fgets(line, sizeof(line), file))
	{
		printf("%s\n", line);
	}

	fclose(file);
	return 0;
}

/*******************************************************************************
* @brief function to add string to the end of the file
* @params a: file path
* @params b: string to add to the file
* @return: 0 on success, -1 on error
******************************************************************************/
int addString(char* filepath, char* input)
{
	FILE* file = fopen(filepath, "a");	/* write at the end of the file */

	if (file == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}

	fprintf(file, "\n%s", input);

	fclose(file);
	return 0;
}

/*******************************************************************************
* @brief function to find a string in a file and return the position of the string
* @params a: file path
* @params b: string to find
* @return: 0 if not found, 1 if found
******************************************************************************/
int findString(char* filepath, char* search)
{
	FILE* file = fopen(filepath, "r+");	/* read the file */

	if (file == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}

	char line[MAX_LENGTH];	/* variable to store each line of the file */
	int lineNum = 0;
	int found = 0;
	int searchLenght = strlen(search);

	while (fgets(line, sizeof(line), file))
	{
		lineNum++;
		int lineLenght = strlen(line);
		
		for (int i = 0; i <= lineLenght - searchLenght; i++)	/* go through each position in the line */
		{
			int j;

			for (j = 0; j < searchLenght; j++)
			{
				if (line[i + j] != search[j])
				{
					break;
				}
			}
			if (j == searchLenght)
			{
				printf("Found at line %d, position %d\n", lineNum, i + 1);
				found = 1;
			}
		}
	}

	fclose(file);

	if (found == 0)
	{
		return 0;
	}
	return 1;
}