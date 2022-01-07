#ifndef DEF_INCLUDE_H
#define DEF_INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include <string.h>
#include <fcntl.h>

#include <errno.h>

//BSThashtable
#define HASHTABLE_SIZE 26 //One for each letter in the alphabet
#define NUM_NODES 1024
#define MAX_LETTERS_IN_WORD 45 //looked up longest word in English language and it has 45 letters

//prepInput
#define BUFFER 1024 //Specified by instructor on piazza

//file_processing
#define PATH_SIZE 256
#define TEXTS_PATH "./texts/" 

//main
#define LETTERS_PER_LINE 62

//defining everything considered white space
#define NEW_LINE '\n'
#define HYPHEN '-'
#define PERIOD '.'
#define QUOTE '\"'
#define L_PARANTHESIS '('
#define R_PARANTHESIS ')'
#define OR '|'
#define COLON ':'
#define SEMICOLON ';'
#define APOSTROPHE '\''
#define L_BRACKET '['
#define R_BRACKET ']'
#define QMARK '?'
#define SLASH '/'
#define LESS '<'
#define GREATER '>'
#define PERCENT '%'
#define AMP '&'
#define COMMA ','
#define DOLLAR '$'
#define AT '@'
#define EXCLAMATION_P '!'
#define HASHTAG '#'
#define UP '^'
#define STAR '*'
#define UNDERLINE '_'
#define PLUS '+'
#define EQUAL '='
#define LCURL '{'
#define RCURL '}'
#define TILDE '~'
#define ACCENT '`'

//Defines WHITESPACE
#define IS_WHITESPACE(c) (c == ' ' || c == NEW_LINE || c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f' || '0' <= c && c <= '9' || c == HYPHEN || c == PERIOD || c == QUOTE || c == L_PARANTHESIS || c == R_PARANTHESIS || c == OR || c == COLON || c == SEMICOLON || c == APOSTROPHE || c == L_BRACKET || c == R_BRACKET || c == QMARK || c == SLASH || c == LESS || c == GREATER || c == PERCENT || c == AMP || c == COMMA || c == DOLLAR || c == AT || c == EXCLAMATION_P || c == HASHTAG || c == UP || c == STAR || c == UNDERLINE || c == PLUS || c == EQUAL || c == LCURL || c == RCURL || c == TILDE || c == ACCENT)

//Defines what is considered a letter or a number
#define IS_LETTER(x)  'A' <= x && x <= 'Z' ||  'a' <= x && x <= 'z' 

//SYSTEM ERROR CALLS
#define ERROR_ALLOCATING NULL
#define ERROR_OPENING -1
#define ERROR_READING -1
#define ERROR_WRITING -1
#define ERROR_CLOSING -1

#define STDOUT 1


#endif