#ifndef ASSEMBLER_STATEMENTS_TYPES_H
#define ASSEMBLER_STATEMENTS_TYPES_H

/**
 * An enum conatins all the possible statment types that our assembler can handler,
 * We have two main types of statments:
 *  - Data statements (will have to deal with storing data at the symbols table)
 *  - Command statements.
 *    COMMAND_STATEMENT - will add new code segments
 *  We can have 4 different types of data statments
 *   - DATA_STATEMENT_TYPE_DATA - statements that store Data (integers)
 *   - DATA_STATEMENT_TYPE_STRING - statements that store string
 *   - DATA_STATEMENT_TYPE_ENTRY - statements that declares a label that can be used by other files
 *   - DATA_STATEMENT_TYPE_EXTERN - statements that store reference to data that will be given from external source
 *  We can also have INVALID_STATEMENT which the given statement is invalid
 */
typedef enum {
    DATA_STATEMENT_TYPE_DATA,
    DATA_STATEMENT_TYPE_STRING,
    DATA_STATEMENT_TYPE_ENTRY,
    DATA_STATEMENT_TYPE_EXTERN,
    COMMAND_STATEMENT,
    INVALID_STATEMENT
} STATEMENT_TYPE;

#endif
