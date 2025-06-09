#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sRecord.h"

/*******************************************************************************
* Main Function Bonus 
*******************************************************************************/
int main(int argc, char* argv[]) 
{
	if (argc < 2)
	{
		printf("You have not entered anything yet\n");
		Help();
		return -1;
	}

	uint16_t errCheckSum = 0;
	uint16_t errCheckType = 0;
	uint16_t errCheckByteCount = 0;
	uint16_t errCheckLength = 0;
	uint16_t errCheckHexa = 0;

	char line[256];
	uint16_t countLine = 0;
	FILE* input_file = NULL;
	FILE* output_file = NULL;

	input_file = fopen(argv[1], "r");
	output_file = fopen("Output.txt", "w");

	if (input_file == NULL) 
	{
		printf("Error open input file\n");
		Help();
	}
	else if (output_file == NULL) 
	{
		printf("Error to create output file\n");
		Help();
	}
	else 
	{
		fprintf(output_file, "Line ||  Address   || Data\n");

		while (fgets(line, sizeof(line), input_file)) 
		{
			uint8_t len = strlen(line);

			if (len > 0 && line[len - 1] == '\n')	/* Loai bo ki tu xuong dong */
			{
				line[len - 1] = '\0';
			}
			if (ParseRecord(line) == -1) 
			{
				fprintf(output_file, "%-5d||  ERROR CHECK TYPE\n", countLine + 1);
				errCheckType++;
				//printf("Checking error");
				//return -1;
			}
			else if (ParseRecord(line) == -2)
			{
				fprintf(output_file, "%-5d||  ERROR CHECK BYTE COUNT\n", countLine + 1);
				errCheckByteCount++;
				//printf("Checking error");
				//return -1;
			}
			else if (ParseRecord(line) == -3)
			{
				fprintf(output_file, "%-5d||  ERROR CHECK HEXA\n", countLine + 1);
				errCheckHexa++;
				//printf("Checking error");
				//return -1;
			}
			else if (ParseRecord(line) == -4)
			{
				fprintf(output_file, "%-5d||  ERROR CHECK LENGTH\n", countLine + 1);
				errCheckLength++;
				//printf("Checking error");
				//return -1;
			}
			else if (ParseRecord(line) == -5)
			{
				fprintf(output_file, "%-5d||  ERROR CHECK SUM\n", countLine + 1);
				errCheckSum++;
				//printf("Checking error");
				//return -1;
			}
			else 
			{
				fprintf(output_file, "%-5d||", countLine + 1);
				Print(line, output_file);
			}
			countLine++;
		}
		fprintf(output_file, "ERROR CHECK TYPE: %-5d\n", errCheckType);
		fprintf(output_file, "ERROR CHECK SUM: %-5d\n", errCheckSum);
		fprintf(output_file, "ERROR CHECK HEXA: %-5d\n", errCheckHexa);
		fprintf(output_file, "ERROR CHECK LENGTH: %-5d\n", errCheckLength);
		fprintf(output_file, "ERROR CHECK BYTE COUNT: %-5d\n", errCheckByteCount);

		printf("Checking completed\n"); 
		printf("ERROR CHECK TYPE: %-5d\n", errCheckType);
		printf("ERROR CHECK SUM: %-5d\n", errCheckSum);
		printf("ERROR CHECK HEXA: %-5d\n", errCheckHexa);
		printf("ERROR CHECK LENGTH: %-5d\n", errCheckLength);
		printf("ERROR CHECK BYTE COUNT: %-5d\n", errCheckByteCount);
	}
	return 0;
}