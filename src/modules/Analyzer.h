#ifndef ASSEMBLER_ANALYZER_H
#define ASSEMBLER_ANALYZER_H

#include "./statments_types.h"
#include "../utils/Error.h"
#include "../utils/TextUtils.h"
#include "CommandsIndex.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE_OF_LABEL 255
#define  MAX_COMMAND_LENGTH 4
/**
 * Returns the type of the given statement
 * @param sentence
 * @return one of the STATEMENT_TYPE enum values, based on which type is the given sentence.
 */
STATEMENT_TYPE getStatementTypeOfSentence(char* sentence);

/**
 * Checks if the given statement is of type of DataStatement of data (integers)
 * @param sentence
 * @return 1 true, 0 if false
 */
int isStatementTypeDataStatement(char* sentence);
/**
 * Checks if the given statement is of type of DataStatement of string
 * @param sentence
 * @return 1 true, 0 if false
 */
int isStatementTypeDataStatementString(char* sentence);
/**
 * Checks if the given statement is of type of DataStatement of entry
 * @param sentence
 * @return 1 true, 0 if false
 */
int isStatementTypeDataStatementEntry(char* sentence);
/**
 * Checks if the given statement is of type of DataStatement of extern
 * @param sentence
 * @return 1 true, 0 if false
 */
int isStatementTypeDataStatementExtern(char* sentence);
/**
 * Checks if the given statement is of type of command statement, if not will throw error
 * @param sentence
 */
int isCommandStatement(char *sentence);


/**
 * Checks if the given sentence type is of any of data statements types
 * @param sentence
 * @return 1 if true, 0 if false
 *
 */
int isDataStatement(char *sentence);

/**
 * Check if the given label is a valid label name
 * @param label
 * @return return 1 if label is according to rules, else return 0
 */
int validateLabel(char* label);

/**
 * Extracts the label from the statement and returns a pointer to the string value of the label
 * @param sentence
 * @return pointer to the string value of the statement, or NULL if statement has no label
 */
char * extractLabel(char* sentence);

/**
 * Extracts the label from the jump operand value and returns a pointer to the string value of the label
 * @param sentence
 * @return pointer to the string value of the statement, or NULL if statement has no label
 */
char * extractJumpOperandLabel(char* jumpOperandValue);

/** returns true if the given line is a comment line or empty line */
boolean isCommentStatementOrEmptyLine(char *sentence);

/** returns which command is used in this sentence, if any, otherwise returns UNKOWN command */
COMMANDS getCommandOfStatement(char *sentence);

#endif
