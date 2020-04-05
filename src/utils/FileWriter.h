#ifndef ASSEMBLER_FILEWRITER_H
#define ASSEMBLER_FILEWRITER_H
#include <stdio.h>
#include <stdlib.h>
/** writes the given string array to a new file with the given name */
void writeToFile(char *filename, char * *buffer, int bufferLength);
#endif
