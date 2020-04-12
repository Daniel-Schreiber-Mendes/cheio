#include "io.h"


bool file_construct(File *const f, char const *restrict path, char const *restrict mode)
{
    FILE* file = fopen(path, mode);

    if (!file)
    {
        printf("File %s couldn't be opened\n", path);
        return false;
    }

    switch (mode[0])
    {
        case 'r':
            fseek(file, 0, SEEK_END); //move file pointer to end of file
            f->bufferSize = ftell(file); //tell position of pointer which means length of string
            fseek(file, 0, SEEK_SET); //move file pointer back to file begin

            f->buffer = malloc(f->bufferSize);
            fread(f->buffer, f->bufferSize, 1, file); //copy memory in file to buffer
            ((char*)f->buffer)[f->bufferSize] = '\0'; //the string has to end with a null terminator, so put it at the end of it
            break;
        default:
            break;
    }

    fclose(file);
    return true;
}


bool file_construct_bin(File *const f, char const *const path)
{
    FILE* file = fopen(path, "rb");

    if (!file)
    {
        printf("File %s couldn't be opened\n", path);
        return false;
    }

    fseek(file, 0, SEEK_END); //move file pointer to end of file
    f->bufferSize = ftell(file); //tell position of pointer which means length of string
    fseek(file, 0, SEEK_SET); //move file pointer back to file begin

    f->buffer = malloc(f->bufferSize);
    fread(f->buffer, f->bufferSize, 1, file); //copy memory in file to buffer

    fclose(file);
    return true;
}


void file_destruct(File const *const f)
{
	free(f->buffer);
}