#include "io.h"


char* strfndch(char *const str, char const c, uint16_t const i)
{
	uint16_t k = 0;
	for (uint16_t found = 0; found < i; ++k)
	{
		if (str[k] == c)
		{
			++found;
		}
	}
	return &str[k];
}


//returns a pointer to a string that lies between the first occurance of key0 and key1
char* fndstrchnk(char const *restrict buffer, char const *restrict key0, char const *restrict key1, uint16_t *const offset)
{
	uint16_t key0len = strlen(key0);
	char *key0end  = strstr(buffer, key0) + key0len;
	char *key1beg = strstr(buffer, key1);
	
	if (!(key0end - key0len) || !key1beg) //if one of them is NULL that means a key couldn't be found
	{
		return NULL;
	}

	char *const midbuffer = malloc(key1beg - key0end + 1);
	memcpy(midbuffer, key0end, key1beg - key0end + 1);
	midbuffer[key1beg - key0end] = '\0';
	*offset += key1beg - buffer + strlen(key1);
	return midbuffer;
}