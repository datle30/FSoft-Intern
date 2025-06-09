#ifndef _S_RECORD_H_
#define _S_RECORD_H_

#include <stdint.h>
#include <stdbool.h>

#define BYTE_COUNT 2
#define BYTE_TYPE 2
#define HEX_BYTE_LENGTH 2

/*******************************************************************************
* @brief function to print out the instructions and structure of the S Record file
******************************************************************************/
void Help();

/*******************************************************************************
* @brief: this function convert hex char to dec value, use for hexStringToByte
* @param: hex char
******************************************************************************/
uint8_t HexCharToValue(char c);

/*******************************************************************************
* @brief: this function convert hexstring to byte dec
* @param: hex string
******************************************************************************/
uint8_t HexStringToByte(const char* hexStr);

/*******************************************************************************
* @brief: function to check if a character is a hex character
* @param: hex char
******************************************************************************/
bool IsHexChar(char c);

/*******************************************************************************
* @brief: this function check Record format hex
* @param: record line
******************************************************************************/
bool CheckHexa(const char* line);

/*******************************************************************************
* @brief: this function check record start with S and not S4
* @param: record line
******************************************************************************/
bool CheckType(const char* line);

/*******************************************************************************
* @brief: this function check record length more than 0
* @param: record line
******************************************************************************/
bool CheckLength(const char* line);

/*******************************************************************************
* @brief: this function check is that correct Byte count
* @param: record line
******************************************************************************/
bool CheckByteCount(const char* line);

/*******************************************************************************
* @brief: this function check is that correct checksum
* @param: record line
******************************************************************************/
bool CheckSum(const char* hexStr);

/*******************************************************************************
* @brief: this function combine all exception
* @param: record line
******************************************************************************/
int ParseRecord(const char* line);

/*******************************************************************************
* @brief: this function print answer to outputfile
* @param: record line
******************************************************************************/
void Print(const char* line, const char* output);

#endif // _S_RECORD_H_
