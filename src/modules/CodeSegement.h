#ifndef ASSEMBLER_CODESEGEMENT_H
#define ASSEMBLER_CODESEGEMENT_H

#include "Analyzer.h"
#include "Opearnds.h"
#include "DataSegment.h"
#include "SymbolsTable.h"
#include "CommandBuilder.h"

#define COMMAND_VALUE_LENGTH 12
#define COMMAND_ARE_BITS_LENGTH 2
#define COMMAND_REGISTER_LENGTH 6

/** returns the current count of command instructions */
int getInstructionsCount();

/** returns pointer to the code section array */
char** getCodeSection();
/**
 * should go over the instruction and increase the Command instructions count based on the given statment
 */
void increaseCommandInstructionsCountByStatement(char* statement);

/** resets the Code Segment module, reintailzaing it, usually used when start to work with a new file */
void resetCodeSegmentModule();


void addStatementToCodeSegment(char* statement);

void initCodeSection();
#endif


