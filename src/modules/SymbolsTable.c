#include "SymbolsTable.h"
/** data instructions counter */
static int DC = 0;

static Symbol *tableHead;
static Symbol *tableTail;

int getDataInstructionsCount(){
    return  DC;
}

void increaseDataInstructionsCount(){
    DC++;
}

Symbol* getSymbolsTableHead(){
    return  tableHead;
}

Symbol* getSymbolsTableTail(){
    return  tableTail;
}

void resetSymbolsModulesModule(){
    Symbol *temp;
    DC = 0; /** resets the data instructions count */
    /** free up the whole list memory */
    while (tableHead){
        temp = tableHead;
        tableHead = tableHead->next;
        free(temp);
    }
    /** avoid dangling pointers, verify that after memory was freed tableTail will stay NULL, note tableHead is garunted to be NULL after the while, due to the fact that we enfoce tail->NEXT will be NULL */
    tableTail = NULL;
}



void addSymbolToTable(Symbol *newSymbol){
    Symbol *isSymbolExists = searchForSymbolByLabel(newSymbol->label);

    /** label already exists */
    if(isSymbolExists != NULL){
        ERROR_PROGRAM(("Requested label %s, already exists, can't declare the same label twice.", newSymbol->label));
    }

    /** if no tail, it means we are setting the first item in the table */
    if(tableTail == NULL){
        tableHead = tableTail = newSymbol;
        tableHead->next = NULL;
        return;
    }

    /** appends the new item to the end of the table */
    tableTail->next = newSymbol;
    tableTail = newSymbol;
    tableTail->next = NULL;
}

Symbol* buildSymbol(char* label, boolean isExternal, boolean isPartOfCommandStatement, int address){
    Symbol* newSymbol = malloc(sizeof(Symbol));
    errorIfMallocFailed(newSymbol, "while trying to allocate memory to create a new Symbol");
    newSymbol->label = label;
    newSymbol->isExternal = isExternal;
    newSymbol->isPartOfCommandStatement = isPartOfCommandStatement;
    newSymbol->address = address;
    newSymbol->next = NULL; /** protect pointer dangling, initialize it as NULL */
    return  newSymbol;
}

Symbol* searchForSymbolByLabel(char* label){
    Symbol *currentSymbol;

    currentSymbol = tableHead;

    while (currentSymbol){
        /** if matches, meaning we found the requested label */
        if(strcmp(currentSymbol->label, label) == 0){
            return  currentSymbol; /** returns pointer to the symbol with the requested label */
        }
        /** advance to next symbol */
        currentSymbol = currentSymbol->next;
    }

    /** could'nt find a symbol with the request label, returns NULL **/
    return  NULL;
}

int getSymbolAddress(char *symbolLabel){
    Symbol *symbol;
    symbol = searchForSymbolByLabel(symbolLabel);

    if(symbol == NULL){

        ERROR_PROGRAM(("Unknown symbol %s", symbolLabel));
        return  0;
    }

    return  symbol->address;
}
