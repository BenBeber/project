#include "./constants.h"
#include <stdio.h>
#include <stdlib.h>
#include "./phase1.h"
#include "./phase2.h"
#include "./modules/CommandsIndex.h"

int currentLine;
int errorFlag;
int main(int argc, char *argv[]) {

    if(argc < 2) {
        fprintf(stderr, "Error: Arguments weren't supplied, exiting code \n");
        exit (0);
    }

    /** init the map that defines all the commands rules */
    initCommandsDescriptors();

    for(argc--, argv++; argc; argv++, argc--) {
        printf("\n Begin processing the following file: %s", *argv);
        currentLine = 1;
        errorFlag = 0;
        /** execute phase 1 of the assembler */
        doPhase1(*argv);

        /** rests line read, because reading the file from the start */
        currentLine = 1;
        /** execute phase 2 of the assembler */
        doPhase2(*argv);

        /** clear up so we can process properly the next file*/
        resetDataSegmentModule();
        resetSymbolsModulesModule();
        resetCodeSegmentModule();

        printf("\n Assembler completed processing file: %s", *argv);

    }
    return  0;
}
