//Keith Skinner
//Lab 4: scanner 2

#ifndef SCANNER_2_SCANNER_H
#define SCANNER_2_SCANNER_H

#include <stdio.h>
#include <stdbool.h>
#include "table.h" //may want to do something about table.h -><- scanner.h


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


static char const *const TOKEN_NAMES[NUM_OF_TOKENS] =
        {
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

typedef struct token_tag {
    TOKEN_TYPE type;
    union {
        char *name;
        long value;
        char symbol;
    };
} TOKEN;

bool isKeyword(TOKEN_TYPE type);

bool isNameable(TOKEN_TYPE type);

TOKEN *scanner(FILE *, TRANS_TABLE *);

void freeToken(TOKEN **);

TOKEN_TYPE tokenNameToType(char *);

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256

#endif //SCANNER_2_SCANNER_H