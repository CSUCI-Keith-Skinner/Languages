/**
* Name: Keith Skinner
* Lab: Lab 7 Introduction to flex
* Date: 10/23/2018
**/

#include "flex_t1.h"

int main(void) {

    TOKEN tok;

    char *token[] = {
            "if", "then", "while", "do", "print",
            ";", "=", "(", ")", "+", "-", "*", "/", "%"
    };

    char *type[] = {
            "keyword", "keyword", "keyword", "keyword", "keyword",
            "semicolon", "assignment", "lparen", "rparen",
            "plus", "minus", "multiply", "divide", "modulus"
    };

    while ((tok = yylex()) != 0) {
        if (tok == ID_TOKEN)
            printf("{<identifier> \"%s\"}", yytext);
        else if (tok == NUMBER_TOKEN)
            printf("{<number> \"%s\"}", yytext);
        else
            printf("{<%s> \"%s\"}", type[tok - IF_TOKEN], token[tok - IF_TOKEN]);
    }
}