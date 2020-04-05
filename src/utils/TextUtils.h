#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef ASSEMBLER_TEXTUTILS_H
#define ASSEMBLER_TEXTUTILS_H

#include "./Error.h"
#include "../constants.h"
/**
 * Getting the next word in input, start from startIndex.
 *  Returns the pointer to the beginning of the word
 * */
char* getWord(char *input, int startIndex);


/**
 * Gets an input, returns wether it contains the char
 * @param input  the input to check
 * @return 0 if do not contains comma, 1 the input contains comma
 */
int isContainsComma(char *input);

/**
 * Gets an input, returns wether it contains a given character
 * @param input the input to check
 * @param charToTest which character to look for
 * @return 1 if contains, 0 if not
 */
int isContainsChar(char *input, char charToTest);

/**
 *
 * Getting a word, and character to test, returns if 1 the last chartaer of the give word, matches the charToTest. or 0 if not.
 * @param word -  a word to check against
 * @param charToTest - the char to check if it the last character of the given word
 * @return 1 if last character matches, 0 if not
 */
int isWordEndsWithChar(char *word, char charToTest);



/**
 * Getting a word, and character to test, returns if 1 the first character of the give word, matches the charToTest. or 0 if not.
 * @param word -  a word to check against
 * @param charToTest - - the char to check if it the first character of the given word
 * @return 1 if first character matches, 0 if not
 */
int isWordStartsWithChar(char *word, char charToTest);

/**
 * Returns the last char of a given word
 * @param word
 * @return
 */
char getLastChar(char* word);

/**
 * Check if the two given chars are the same
 * @param c
 * @param toCompare
 * @return true if they are the same, false if not
 */
boolean isCharsEqual(char c, char toCompare);

/**
 * Trims leading and trailing spaces from the str
 * @param str
 * @return
 */
char *trimwhitespace(char *str);

/**
 * Returns a new string from the given string, between the from index until the to index.
 * @param string
 * @param from - index from which to start the substring
 * @param to - index to end the substring
 * @return
 */
char* substringFromTo(char* string, int from, int to);

void removeExtraSpaces(char *statementToCheck);

/** check if the given string reprents a number, if not throws an error */
void validateStringIsNumber(char *string);

/**
 * Concat s1 and s2 to a new string of both combined
 * @param s1
 * @param s2
 * @return the new combined string of s1 & s2
 */
char* concat(const char *s1, const char *s2);

#endif
