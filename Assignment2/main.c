int chuoiDoixung(char str[], int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			return 0;    /* Khong la chuoi doi xung */
		}
	}
	return 1;    /* Chuoi doi xung */
}

char daonguocChuoi(char strIn[], char strOut[], int length)
{
	for (int i = 0; i < length; i++)
	{
		strOut[i] = strIn[length - i - 1];    /* First char of strOut is Last char of strIn */
	}
	strOut[length] = '\0';
	printf("%s\n", strOut);
}

int strLength(char str[])
{
	int length = 0;
	while (str[length] != 0)
	{
		length++;
	}
	return length;
}

#include <stdio.h>

#define MAX_LENGTH 255

int main(int argc, char* argv[])
{
	char strIn[MAX_LENGTH + 1];
	char strOut[MAX_LENGTH + 1];

	printf("Please entrer the String: ");
	if (fgets(strIn, sizeof(strIn), stdin) != NULL)    /* Input String is not Null */
	{
		int length = strLength(strIn);    /* Length of string*/
		if (strIn[length - 1] == '\n')    /* Last char is newline */
		{
			strIn[length - 1] = '\0';    /* Last char is end of string */
			length--;
		}

		if (chuoiDoixung(strIn, length))
		{
			printf("Chuoi doi xung");
		}
		else
		{
			printf("Chuoi khong doi xung\n");
			printf("Chuoi dao nguoc: ");
			daonguocChuoi(strIn, strOut, length);
		}
	}
	else
	{
		printf("Error\n");
		return 1;
	}
	return 0;
}