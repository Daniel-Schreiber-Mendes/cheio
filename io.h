#ifndef IO_H
#define IO_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


typedef struct
{
	void *buffer;
	uint16_t bufferSize; //size in bytes
}
File;


//file.c
bool file_construct(File *const f, char const *restrict path, char const *restrict mode);
bool file_construct_bin(File *const f, char const *const path);
void file_destruct(File const *const f);


//string.c

char* strfndch(char *const str, char const ch, uint16_t const i);
char* fbcp(FILE *const f);
char* fndstrchnk(char const *restrict buffer, char const *restrict key0, char const *restrict key1);


#endif