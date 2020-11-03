#ifndef IO_H
#define IO_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>


//file.c
char* fbcp(FILE *const f);

//to prevent naming collision concatenate dir and end with the entryalias to create unique names/labels
#define fforeach(path, entryalias, expr)\
{\
	DIR *const dir##entryalias = opendir(path);\
    if (!dir##entryalias)\
    {\
        g_print("Folder %s could not be opened", path);\
        goto end##entryalias;\
    }\
    struct dirent *entryalias;\
    while ((entryalias = readdir(dir##entryalias)) != NULL) \
    {\
    	if(!strcmp(entryalias->d_name, ".") || !strcmp(entryalias->d_name, "..")) continue;\
		expr;\
    }\
    closedir(dir##entryalias);\
    end##entryalias: (void)0;\
}


//string.c
char* strfndch(char *const str, char const ch, uint16_t const i);
char* fndstrchnk(char const *restrict buffer, char const *restrict key0, char const *restrict key1, uint16_t *const offset);

//@bufferlen: uint16_t* which will be filled with the value length bufferchunk
//@buffer: char* to the buffer that contains all the text
//@bufferchunk: char** that will be filled with the chunk found between key0 and key1
//@key0 & key1: char*
#define fndstrchnk_foreach(buffer, bufferchunk, key0, key1)\
	uint16_t offset = 0;\
	while ((*bufferchunk = fndstrchnk(buffer + offset, key0, key1, &offset)))


#endif