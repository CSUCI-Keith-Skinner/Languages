//Keith Skinner
//Lab 3: Scanner 1

#ifndef SCANNER_1_SCANNER_H
#define SCANNER_1_SCANNER_H

#include <stdio.h>
#include <stdbool.h>

typedef enum {
    INVALID,
    NUMBER,
    IDENTIFIER,
    ASSIGNMENT,
    SEMICOLON,
    LPAREN,
    RPAREN,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    REPEAT,
    PRINT,
    END_OF_INPUT,
    NUM_OF_TOKENS
} TOKEN_TYPE;

static char const * const TOKEN_NAMES[NUM_OF_TOKENS] = {
    "invalid",
    "number",
    "identifier",
    "assignment",
    "semicolon",
    "lparen",
    "rparen",
    "add",
    "subtract",
    "multiply",
    "divide",
    "modulus",
    "keyword",
    "keyword",
    "end"
};

typedef struct token
{
    TOKEN_TYPE type;
    union {
        char * name;
        long value;
        char symbol;
    };
} TOKEN;

TOKEN * scanner(FILE *);
void ungetToken(TOKEN **);
void freeToken(TOKEN **);


bool isNameable(TOKEN_TYPE type);
bool isKeyword(TOKEN_TYPE type);

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256

#endif //SCANNER_1_SCANNER_H
