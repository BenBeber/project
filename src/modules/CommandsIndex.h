#ifndef ASSEMBLER_COMMANDSINDEX_H
#define ASSEMBLER_COMMANDSINDEX_H
#include "../constants.h"
#include "../utils/Error.h"
#include <string.h>
#define  NO_OTHER_OPERAND -1

/**
 * Enum that holds all the possible commands that our assembler can handle
 */
typedef enum { mov, cmp, add , sub, notCMD, clr, lea, inc, dec, jmp, bne, red, prn, jsr, rts, stop, UNKNOWN_COMMAND } COMMANDS;

/**
 * A type that describes a command,
 *  numberOfOperands - describes the number of operands required by this command.
 *  canUseJumpOperand - boolean wether this command can accepts jump operator
 */
typedef struct command_descriptor {
    int numberOfOperands;
    boolean canUseJumpOperand;
    int allowedSrcOperands[3];
    int allowedDestOperands[3];
} CommandDescriptor;


/**
 * Init the map of the commands */
void initCommandsDescriptors();

/**
 * Gets the command descriptor for the given command, if not given a command string will return NULL.
 * @param command
 * @return
 */
CommandDescriptor* getCommandDescriptor(COMMANDS command);


/**
 * Converts the given string to one of the COMMANDS Enums, if it do not match, return UNKNOWN_COMMAND.
 * @param commandString - string to check if matches to enum.
 * @return COMMANDS enum
 */
COMMANDS commandStringToEnum(char *commandString);

#endif
