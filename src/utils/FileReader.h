
#ifndef ASSEMBLER_FILEREADER_H
#define ASSEMBLER_FILEREADER_H


#include <stdio.h>
#include <stdlib.h>
#include "../constants.h"
FILE * openReadFile(char *filename);

/**
 * Keep getting line by line until the end of file.
 * @param file pointer to file.
 * @param nextLineHandler pointer to fucnction that get the next line.
 */
void doWhileFileHaveLines(FILE * file, void (*nextLineHandler)(char*));
#endif


