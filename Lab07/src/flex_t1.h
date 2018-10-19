/**
* Name: Keith Skinner
* Lab: Lab 7 Introduction to flex
* Date: 10/23/2018
**/

#ifndef __flex_t1_h_
#define __flex_t1_h_

#include <stdio.h>

typedef enum {
    IF_TOKEN = 258, // since Bison will start token at that number
    THEN_TOKEN,
    WHILE_TOKEN,
    DO_TOKEN,
    PRINT_TOKEN,
    SEMICOLON_TOKEN,
    EQUAL_TOKEN,
    LPAREN_TOKEN,
    RPAREN_TOKEN,
    ADD_TOKEN,
    SUBTRACT_TOKEN,
    MULTIPLY_TOKEN,
    DIVIDE_TOKEN,
    MODULUS_TOKEN,
    ID_TOKEN,
    NUMBER_TOKEN
} TOKEN;

int yylex(void);
extern char * yytext;

void yyerror(char *s);

#endif
