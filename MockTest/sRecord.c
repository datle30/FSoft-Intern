#define _CRT_SECURE_NO_DEPRECATE  

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sRecord.h"

/*******************************************************************************
* @brief function to print out the instructions and structure of the S Record file
******************************************************************************/
void Help()
{
	printf("Checking the S-record file and generate Output.txt\n");
	printf("Enter the path of the S Record file:\n");
	printf("Structure:\n");
	printf("S | Type | Byte Count | Address | Data | Checksum\n");
	printf("Record start - each record begins with an uppercase letter S\n");
	printf("Type - single numeric digit 0 to 9\n");
	printf("Byte count - two hex digits (00 to FF)\n");
	printf("Address - four / six / eight hex digits as determined by the record type\n");
	printf("Data - a sequence of 2n hex digits, for n bytes of the data\n");
	printf("Checksum - two hex digits");
	printf("Please try again\n");
}

/*******************************************************************************
* @brief: this function convert hex char to dec value
* @param: hex char
******************************************************************************/
uint8_t HexCharToValue(char c)
{
	uint8_t result = 0;

	if ((c >= '0') && (c <= '9')) 
	{
		result = c - '0';
	}
	else if ((c >= 'A') && (c <= 'F')) 
	{
		result = c - 'A' + 10;
	}
	else if ((c >= 'a') && (c <= 'f')) 
	{
		result = c - 'a' + 10;
	}

	return result;
}

/*******************************************************************************
* @brief: this function convert hexstring to byte dec
* @param: hex string
******************************************************************************/
uint8_t HexStringToByte(const char* hexStr)
{
	/* hexStr[0] chuyen sang Dec, dich trai 4 bit (x16) + hexStr[1] chuyen sang Dec  */
	uint8_t value = (HexCharToValue(hexStr[0]) << 4) | HexCharToValue(hexStr[1]);
	return value;
}

/*******************************************************************************
* @brief: function to check if a character is a hex character
* @param: hex char
******************************************************************************/
bool IsHexChar(char c)
{
	bool check = false;
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) 
	{
		check = true;
	}
	else
	{
		check = false;
	}
	return check;
}

/*******************************************************************************
* @brief: this function check line Record format hex
* @param: record line
******************************************************************************/
bool CheckHexa(const char* line)
{
	bool isHex = true;
	line++;

	while (*line) 
	{
		if (!IsHexChar(*line)) 
		{
			isHex = false;
			break;
		}
		line++;
	}

	return isHex;
}

/*******************************************************************************
* @brief: this function check record start with S and not S4
* @param: record line
******************************************************************************/
bool CheckType(const char* line)
{
	bool checkVal = false;

	if ((line[0] == 'S') && (line[1] >= '0') && (line[1] <= '9') && (line[1] != '4')) 
	{
		checkVal = true;
	}
	else
	{
		checkVal = false;
	}
	return checkVal;
}

/*******************************************************************************
* @brief: this function check record length more than 0
* @param: record line
******************************************************************************/
bool CheckLength(const char* line)
{
	bool check = false;
	uint8_t size = strlen(line);

	if (size < 0) 
	{
		check = false;
	}
	else
	{
		check = true;
	}

	return check;
}

/*******************************************************************************
* @brief: this function check is that correct Byte count
* @param: record line
******************************************************************************/
bool CheckByteCount(const char* line)
{
	bool check = false;

	if (!CheckLength(line)) 
	{
		check = false;
	}

	uint8_t count = HexStringToByte(&line[2]);	/* so byte duoc chuyen doi thanh Dec tu vi tri thu 3 */
	uint32_t size = (uint32_t)strlen(line);
	uint32_t dataLength = size - BYTE_COUNT - BYTE_TYPE;

	if (count == (dataLength / HEX_BYTE_LENGTH)) 
	{
		check = true;
	}
	else
	{
		check = false;
	}

	return check;
}

/*******************************************************************************
* @brief: this function check is that correct checksum
* @param: record line
******************************************************************************/
bool CheckSum(const char* hexStr)
{
	bool check = false;
	uint8_t size = (uint8_t)strlen(hexStr);
	uint8_t checksum = HexStringToByte(&hexStr[size - 2]); /* chuyen doi 2 ki tu cuoi */
	uint8_t sum = 0;

	for (int i = 2; i < size - 2; i += 2) 
	{ 
		uint8_t count = HexStringToByte(&hexStr[i]);
		sum += count;
	}

	sum = 0xFF - (sum & 0xFF);

	if (sum == checksum) 
	{
		check = true;
	}
	else 
	{
		check = false;
	}

	return check;
}

/*******************************************************************************
* @brief: this function combine all exception
* @param: record line
******************************************************************************/
int ParseRecord(const char* line)
{
	int check = 0;

	if (!CheckType(line)) 
	{
		check = -1;
	}
	else if (!CheckByteCount(line)) 
	{
		check = -2;
	}
	else if (!CheckHexa(line)) 
	{
		check = -3;
	}
	else if (!CheckLength(line)) 
	{
		check = -4;
	}
	else if (!CheckSum(line)) 
	{
		check = -5;
	}
	else 
	{
		check = 0;
	}

	return check;
}

/*******************************************************************************
* @brief: this function print answer to outputfile
* @param: record line
******************************************************************************/
void Print(const char* line, const char* output)
{
	char type = line[1];
	char address[9] = { 0 };
	char data[256] = { 0 };
	uint8_t dataLength = 0;
	uint8_t addressLength = 0;

	switch (type) 
	{
		case '0':
		{
			addressLength = 4;
			break;
		}
		case '1':
		{
			addressLength = 4;
			break;
		}
		case '2':
		{
			addressLength = 6;
			break;
		}
		case '3':
		{
			addressLength = 8;
			break;
		}
		case '5':
		{
			addressLength = 4;
			dataLength = 0;
			break;
		}
		case '6':
		{
			addressLength = 6;
			dataLength = 0;
			break;
		}
		case '7':
		{
			addressLength = 8;
			dataLength = 0;
			break;
		}
		case '8':
		{
			addressLength = 6;
			dataLength = 0;
			break;
		}
		case '9':
		{
			addressLength = 4;
			dataLength = 0;
			break;
		}
		default:
		{
			printf("Invalid S-record type: %c\n", type);
			break;
		}
	}

	strncpy(address, &line[4], addressLength);	/* Lay add tu vi tri thu 5, do dai addressLength */

	dataLength = strlen(line) - 2 - (addressLength) - HEX_BYTE_LENGTH * 2; /* ngoai tru type, address, checksum */

	if (dataLength > 0) 
	{
		strncpy(data, &line[4 + addressLength], dataLength);	/* Lay data tu vi tri ngay sau add */
		data[dataLength] = '\0';
		fprintf(output, "  %-10s|| %s\n", address, data);
	}
	else 
	{
		fprintf(output, "  %-10s|| 0\n", address);
	}
}
