#include "io.h"


bool fstrcmp(FILE *file, char const *const string)
{
	uint16_t i = 0; 
	for (; string[i] != '\0'; ++i)
	{
		if (string[i] != fgetc(file))
		{
			fseek(file, -i, SEEK_CUR); //move file pointer back to where it wasnat the beginning
			return false;
		}
	}
	fseek(file, -i, SEEK_CUR); //move file pointer back to where it wasnat the beginning
	return true;
}




char* strfndi(char *const string, char const ch, uint16_t const i)
{
	uint16_t k = 0;
	for (uint16_t found = 0; found != i; ++k)
	{
		if (string[k] == ch)
		{
			++found;
		}
	}
	return &string[k];
}


//moves the file pointer to the begin of the i-th occurance of a string

bool ffndi(FILE *const file, char *const ch, uint16_t const i)
{
	uint16_t found = 0;
	while (found != i)
	{
		if (fgetc(file) == EOF)
		{
			return false;
		}
		if (fstrcmp(file, ch))
		{
			++found;
		}
	}
	return true;
}