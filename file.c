#include "io.h"


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