#include "FileReader.h"

FILE * openReadFile(char *filename){
    FILE * file = fopen(filename, "r");
    if(!file){
        fprintf(stdout, "\n error could not open file: %s \n", filename);
        exit(1);
    }
    return file;
}


void doWhileFileHaveLines(FILE * file, void (*nextLineHandler)(char*)){
    char line[MAX_LINE_SIZE];
    while(fgets(line, sizeof(line), file)){
        nextLineHandler(line);
    }
}


