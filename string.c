#include "io.h"


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


FILE* ffndi(FILE *file, char const ch, uint16_t const i)
{
	char c;
	uint16_t found = 0;
	while (found != i)
	{
		if ((c = fgetc(file)) == EOF)
		{
			return NULL;
		}
		if (c == ch)
		{
			++found;
		}
	}
	return file;
}