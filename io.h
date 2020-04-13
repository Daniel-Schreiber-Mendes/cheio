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

bool fstrcmp(FILE *file, char const *const string);
char* strfndi(char *const string, char const ch, uint16_t const i);
bool ffndi(FILE *const file, char *const ch, uint16_t const i);


//executes the given scope for each occurance of a string inside a file
#define fforeach(file, string)\
	while(ffndi(file, ))


#endif