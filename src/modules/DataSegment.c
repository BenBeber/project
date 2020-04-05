#include "DataSegment.h"

static DataSegmentNode *head;
static DataSegmentNode *tail;
static list entryStatementsList;
static list externalStatementsList;


/** private methods declarations*/
/**
 * Handles a case of .data statement
 * @param operands  - the list of operands of the .data statement
 * @param label  - the actual value of the label
 */
void handleDataTypeStatementOfData(OperandNode *operands, char* label);
/**
 * Handles a case of .string statement
 * @param operands  - the list of operands of the .data statement
 * @param label  - the actual value of the label
 */
void handleDataTypeStatementOfString(OperandNode *operand, char* label);

/**
 * Handles a case of .entry statement
 * @param operand
 */
void handleDataStatmentTypeEntry(OperandNode *operand);


/**
 * Handles a case of .extern statement
 * @param operand
 */
void handleDataStatmentTypeExtern(OperandNode *operand);


/**
 * Apeends the given node to the end of the data segment list
 * @param valueToAdd
 */
void addDataSegmentNode(int valueToAdd);

void initEntryStatementsList();
void initExternalStatementsList();

void addLabelToEntriesList(char* label);

/** private methods declarations end */

void handleDataStatement(char* dataStatement){
    STATEMENT_TYPE type;
    OperandNode *operands;
    char *label;
    label = extractLabel(dataStatement);
    type = getStatementTypeOfSentence(dataStatement);
    operands = getOperandsListOfStatement(dataStatement, type, label);
    switch (type){
        case DATA_STATEMENT_TYPE_DATA:
            handleDataTypeStatementOfData(operands, label);
            break;
        case  DATA_STATEMENT_TYPE_STRING:
            handleDataTypeStatementOfString(operands, label);
            break;
        case DATA_STATEMENT_TYPE_ENTRY:
            handleDataStatmentTypeEntry(operands);
            break;
        case DATA_STATEMENT_TYPE_EXTERN:
            handleDataStatmentTypeExtern(operands);
            break;
        default:
            ERROR_PROGRAM(("received invalid data statement %s", dataStatement));
            break;
    }
}


void addDataSymbolIfLabelGiven(char* label){
    Symbol *newSymbol;
    if(label != NULL){
        newSymbol = buildSymbol(label, FALSE, FALSE, getDataInstructionsCount());
        addSymbolToTable(newSymbol);
    }
}

void handleDataTypeStatementOfData(OperandNode *operands, char* label){
    OperandNode *temp = operands;
    addDataSymbolIfLabelGiven(label);

    if (operands == NULL)
    {
        ERROR_PROGRAM((".data statements must have at least one operand"));
    }

    /** iterate over all the operands */
    while (temp){
        /** .data statements can only use numeric (direct) operands e.g -1 */
        if(temp->type != DIRECT_VALUE_OPERAND){
            ERROR_PROGRAM(("Invalid operand value handling .data statement, received %s, .data operations can only use direct(numeric) operands. ", temp->value));
        }
        /** for each operand add it to the code segment, cast the string value to int, and increase the data count */
        addDataSegmentNode(atoi(temp->value));
        increaseDataInstructionsCount();
        /** advance to the next operand */
        temp = temp->next;
    }
}

void handleDataTypeStatementOfString(OperandNode *operand, char* label){
    int stringIndex;
    addDataSymbolIfLabelGiven(label);
    if (operand == NULL || countNumberOfOpearnds(operand) != 1)
    {
        ERROR_PROGRAM((".string statements must exactly have one operand"));
    }
    if(operand->type != DIRECT_VALUE_OPERAND){
        ERROR_PROGRAM(("Invalid operand value handling .string statement, received %s, .string operations can only use direct operand. ", operand->value));
    }
    stringIndex = 0;
    while (stringIndex < strlen(operand->value)){
        /** add each character to the data segment */
        addDataSegmentNode((int)operand->value[stringIndex]);
        /** increase data instructions count */
        increaseDataInstructionsCount();
        /** move to the next char */
        stringIndex++;
    }

    /** add zero  to indicate the end of the string */
    addDataSegmentNode(0);
    increaseDataInstructionsCount();
}

void handleDataStatmentTypeEntry(OperandNode *operand){
    if (operand == NULL || countNumberOfOpearnds(operand) != 1)
    {
        ERROR_PROGRAM((".entry statements must exactly have one operand"));
    }
    if(operand->type != LABEL_OPERAND){
        ERROR_PROGRAM(("Invalid operand value handling .entry statement, received %s, .entry operations can only use label operand. ", operand->value));
    }
    /** add the entry label to the entries list */
    addLabelToEntriesList(operand->value);
}

void handleDataStatmentTypeExtern(OperandNode *operands){
    OperandNode *walker = operands;
    if (operands == NULL)
    {
        ERROR_PROGRAM((".extern statements must at least one operand"));
    }
    while (walker){
        if(walker->type != LABEL_OPERAND){
            ERROR_PROGRAM(("Invalid operand value handling .extern statement, received %s, .extern operations can only use label operands. ", walker->value));
        }
        /** add the extern statment to the symbols table */
        addSymbolToTable(buildSymbol(walker->value, TRUE, FALSE, 0));
        walker = walker->next;
    }
}

DataSegmentNode* getDataSegmentHead(){
    return head;
}


list* getEntryStatementsList(){
    return  &entryStatementsList;
}


list* getExternalStatementsList(){
    return  &externalStatementsList;
}
void addDataSegmentNode(int valueToAdd){
    DataSegmentNode *newNode = malloc(sizeof(DataSegmentNode));
    errorIfMallocFailed(newNode, "when trying to allocate memory for a new DataSegmentNode");
    newNode->value = valueToAdd;
    newNode->next = NULL; /** enforce next of tail is NULL, avoiding dangling pointers */

    /** if no tail, it means we are setting the first item in the DataSegment */
    if(tail == NULL){
        head = tail = newNode;
        return;
    }

    /** appends the new item to the end of the DataSegment */
    tail->next = newNode;
    tail = newNode;
}


void initEntryStatementsList(){
    list_new(&entryStatementsList, sizeof(char *));
}

void initExternalStatementsList(){
    list_new(&externalStatementsList, sizeof(char *));
}
void addLabelToEntriesList(char* label){
    list_append(&entryStatementsList, label);
}

void addExternalStatementUsage(char* label, int addressOfUsage){
    char *row;
    row = (char *) malloc(sizeof(char*));
    errorIfMallocFailed(row, "new row of external statement");
    sprintf(row, "%s   %d", label, addressOfUsage);
    list_append(&externalStatementsList, row);
}

void resetDataSegmentModule(){
    DataSegmentNode *temp;
    /** free up the whole list memory */
    while (head){
        temp = head;
        head = head->next;
        free(temp);
    }
    /** avoid dangling pointers, verify that after memory was freed tail will stay NULL, note head is guaranteed to be NULL after the while, due to the fact that we enforce tail->next will be NULL */
    tail = NULL;

    /** recreate the entry & externals list */
    list_destroy(&entryStatementsList);
    list_destroy(&externalStatementsList);
    initEntryStatementsList();
    initExternalStatementsList();
    resetSymbolsModulesModule();
}
