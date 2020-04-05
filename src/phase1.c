#include "phase1.h"
extern int currentLine;
void handleNextLIne(char* line);


void doPhase1(char* fileName){

    FILE *fileToAssemble;
    /** file names are given without the extension, we expect the file to end with the .as extension*/
    fileToAssemble = openReadFile(concat(fileName, ".as"));

    /** keeps reading line by line and handle each line */
    doWhileFileHaveLines(fileToAssemble, handleNextLIne);

    /** after we handled all the lines, update the final addresses in the symbols table */
    updateSymbolTableAddresses();
}


void handleNextLIne(char* line){

    /** skip empty lines or comment lines */
    if(isCommentStatementOrEmptyLine(line) == TRUE){
        currentLine++;
        return;
    }

    /** check if it data statment line, or command instruction line, and handle it as needed */
    if(isDataStatement(line)){
        handleDataStatement(line);
    } else if(isCommandStatement(line)){
        increaseCommandInstructionsCountByStatement(line);
    } else {
        printf("error invalid command at line");
    }
    currentLine++;
}



void updateSymbolTableAddresses(){
    Symbol *walker;
    walker = getSymbolsTableHead();
    while (walker){
        /** skip external or command labels, as we don't need to update their addresses */
        if(walker->isPartOfCommandStatement == TRUE ||  walker->isExternal == TRUE){
            walker = walker->next;
            continue;
        }

        /** add to the address the amount of command instructions + the memory start address, as the data segment starts immidiately after the code segment */
        walker->address += getInstructionsCount() + MEMOERY_START_ADDRESS;

        walker = walker->next;
    }
}
