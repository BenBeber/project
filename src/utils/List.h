#ifndef ASSEMBLER_LIST_H
#define ASSEMBLER_LIST_H

#include "../constants.h"

typedef struct _listNode {
    char *data;
    struct _listNode *next;
} listNode;

typedef struct {
    int logicalLength;
    int elementSize;
    listNode *head;
    listNode *tail;
} list;

/**
 * Creates a  list
 * @param list pointer to hold the new list
 * @param elementSize the size of each element in the list
 */
void list_new(list *list, int elementSize);

/**
 * Destroys the given list, frees up all it allocated memory
 * @param list
 */
void list_destroy(list *list);

/**
 * Adds the given element to the end of the list
 * @param list
 * @param element
 */
void list_append(list *list, char *element);


/**
 * Returns the number of nodes in the given list
 * @param list
 * @return
 */
int list_size(list *list);

/**
 * Using the given iterator function, and runs it against each node element in the list, or until the iterator returns false, or until the end of the list, whichever happens first
 * @param list
 * @param iterator
 */


#endif
