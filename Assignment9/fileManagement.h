#ifndef _FILE_MANAGEMENT_H_
#define	_FILE_MANAGEMENT_H_

/*******************************************************************************
* Definitions
******************************************************************************/
#define MAX_LENGTH 1000

/*******************************************************************************
* @brief function to print out functions
******************************************************************************/
void menu();

/*******************************************************************************
* @brief function to create a new file if it does not exist
* @params a: file path
* @return: 0 on success, -1 on error
******************************************************************************/
int createFile(char* filepath);

/*******************************************************************************
* @brief function to print the contents of the file
* @params a: file path
* @return: 0 on success, -1 on error
******************************************************************************/
int fileContent(char* filepath);

/*******************************************************************************
* @brief function to add string to the end of the file
* @params a: file path
* @params b: string to add to the file
* @return: 0 on success, -1 on error
******************************************************************************/
int addString(char* filepath, char* input);

/*******************************************************************************
* @brief function to find a string in a file and return the position of the string
* @params a: file path
* @params b: string to find
* @return: 0 if not found, 1 if found
******************************************************************************/
int findString(char* filepath, char* search);


#endif // _FILE_MANAGEMENT_H_

