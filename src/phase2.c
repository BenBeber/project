//
// Created by Ben on 11/03/2020.
//
#include "phase2.h"
#include "utils/List.h"

void handleNextLine(char* line);
void createEnteriesFile(char *fileName);
void createExternalsFile(char *fileName);
void createObjectFile(char *fileName, int codeSegmentSize, int dataSegmentSize);
extern int currentLine;

void doPhase2(char* fileName){
    FILE *fileToAssemble;
    int codeSegmentSize;
    int dataSegmentSize;

    codeSegmentSize = getInstructionsCount();
    dataSegmentSize = getDataInstructionsCount();

    /** file names are given without the extension, we expect the file to end with the .as extension*/
    fileToAssemble = openReadFile(concat(fileName, ".as"));

    /** creates the proper size for the codeSegment as we now know it, and resets the IC count to 0, so we can build the code segement statement after statement */
    initCodeSection();
    /** keeps reading line by line and handle each line */
    doWhileFileHaveLines(fileToAssemble, handleNextLine);


    if(errorFlag == 1){
        printf("didn't output files for file %s, because errors were found. see the errors output for more information.", fileName);
        return;
    }
    createEnteriesFile(fileName);
    createExternalsFile(fileName);
    createObjectFile(fileName, codeSegmentSize, dataSegmentSize);
}


void handleNextLine(char* line){
    /** skip empty lines or comment lines */
    if(isCommentStatementOrEmptyLine(line) == TRUE){
        currentLine++;
        return;
    }

    /** skip data statements lines we already handled them in phase 1 */
    if(isDataStatement(line)){
        currentLine++;
        return;
    } else if(isCommandStatement(line)){
        addStatementToCodeSegment(line);
    } else {
        ERROR_PROGRAM(("error invalid command"));
    }
    currentLine++;
}



void createEnteriesFile(char *fileName){
    listNode *walker;
    list *entryList;
    int address;
    int count;
    char * * buffer;
    entryList = getEntryStatementsList();
    walker = entryList->head;
    /** if not entry statements nothing to do */
    if(walker == NULL){
        return;
    }
    buffer = (char * *) malloc(sizeof(char *) * list_size(entryList));
    errorIfMallocFailed(buffer, "new array of strings");
    count = 0;
    while (walker){
        address = getSymbolAddress((char *)walker->data);
        buffer[count] = (char *) malloc(sizeof(char *));
        sprintf(buffer[count], "%s    %d", walker->data, address);
        walker = walker->next;
        count++;
    }

    writeToFile(concat(fileName, ".ent"), buffer, count);
}


void createExternalsFile(char *fileName){
    listNode *walker;
    list *externalsList;
    char * * buffer;
    int count;
    externalsList = getExternalStatementsList();
    walker = externalsList->head;
    /** if not entry statements nothing to do */
    if(walker == NULL){
        return;
    }
    buffer = (char * *) malloc(sizeof(char *) * list_size(externalsList));
    errorIfMallocFailed(buffer, "new array of strings");
    count = 0;
    while (walker){
        buffer[count] = (char *) malloc(sizeof(char *));
        sprintf(buffer[count], "%s", walker->data);
        walker = walker->next;
        count++;
    }

    writeToFile(concat(fileName, ".ext"), buffer, count);
}


void createObjectFile(char *fileName, int codeSegmentSize, int dataSegmentSize){
    FILE * file;
    int codeItteratorIndex;
    int dataItteratorIndex;
    char ** codeSegment;
    char *firstLine;
    char* lineValue;
    DataSegmentNode *dataSegmentWalker;
    codeSegment = getCodeSection();
    fileName = concat(fileName, ".ob");
    file = fopen(fileName, "w+");
    if(!file){
        fprintf(stderr, "error could not create file: %s \n", fileName);
        exit(1);
    }

    firstLine = (char *)malloc(sizeof(char*));
    /** first put the total code instructions and total data instructions */
    sprintf(firstLine, "%d %d", codeSegmentSize, dataSegmentSize);
    fputs(firstLine, file);
    fputs("\n", file);
    codeItteratorIndex = dataItteratorIndex = 0;
    /** write all the code section to the file line by line */
    while (codeItteratorIndex < codeSegmentSize){
        /** replace each line to it weird binary value */
        replaceToBinaryStringToWierdBinaryString(codeSegment[codeItteratorIndex]);
        fprintf(file, "%d        %s", codeItteratorIndex + MEMOERY_START_ADDRESS, codeSegment[codeItteratorIndex]);
        fputs("\n", file);
        codeItteratorIndex++;
    }


    dataSegmentWalker = getDataSegmentHead();
    /** write all the data section to the file line by line */
    while (dataSegmentWalker != NULL){
        /** turn each value in data segment to it binary value in MACHINE_CODE_LINE_LENGTH bits */
        lineValue = decimal_to_binaryString(dataSegmentWalker->value, MACHINE_CODE_LINE_LENGTH);
        /** replace each line to it weird binary value */
        replaceToBinaryStringToWierdBinaryString(lineValue);
        /*** put the correct address for each line, which is the memory start + where the code section ended + the current place in data section */
        fprintf(file, "%d        %s", dataItteratorIndex + MEMOERY_START_ADDRESS + codeItteratorIndex, lineValue);
        fputs("\n", file);
        dataSegmentWalker = dataSegmentWalker->next;
        dataItteratorIndex++;
    }
    fclose(file);


}
