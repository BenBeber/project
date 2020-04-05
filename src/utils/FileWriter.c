#include "FileWriter.h"


void writeToFile(char *filename, char * *buffer, int bufferLength){
    FILE * file = fopen(filename, "w+");
    int i;
    if(!file){
        fprintf(stderr, "error could not create file: %s \n", filename);
        exit(0);
    }

    file = fopen(filename, "w+");
    i = 0;
    while (i < bufferLength){
        fputs(buffer[i], file);
        fputs("\n", file);
        i++;
    }

    fclose(file);

}
