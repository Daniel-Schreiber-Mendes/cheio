#include "io.h"

/*
bool fstrcmp(FILE *file, char const *const str)
{
	uint16_t i = 0; 

	for (; str[i] != '\0'; ++i)
	{
		printf("%u\n", i);
		if (str[i] != fgetc(file))
		{
			fseek(file, -i, SEEK_CUR); //move file pointer back to where it was at the beginning
			return false;
		}
	}
	fseek(file, -i, SEEK_CUR);
	return true;
}*/




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


//moves the file pointer to the begin of the i-th occurance of a string
/*
bool fstrfndi(FILE *const file, char *const str, uint16_t const i)
{
	uint16_t found = 0;
	int c;
	while ((c = fgetc(file)) != EOF) 
	{
       	if (fstrcmp(file, str))
		{
			++found;
		}
    	//putchar(c);
		if (found == i)
		{
			return true;
		}
    }
    return false;
}*/


char* fbcp(FILE *const f)
{

    fseek(f, 0, SEEK_END); //move file pointer to end of file
    int64_t const buffersize = ftell(f); //tell position of pointer which means length of string
    fseek(f, 0, SEEK_SET); //move file pointer back to file begin

    char *const buffer = malloc(buffersize);
    fread(buffer, buffersize, 1, f); //copy memory in file to buffer
    buffer[buffersize] = '\0'; //the string has to end with a null terminator, so put it at the end of it
    return buffer;
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