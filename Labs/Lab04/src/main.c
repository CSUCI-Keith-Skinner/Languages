/**
* Name: Keith Skinner
* Lab: Lab 4 Nested Cases Scanner
* Date: 10/02/2018
**/

//
//  main.c (driver for a scanner test)
//
//  Created by Bieszczad, A.J. on 9/20/17.
//  Copyright (c) 2017 CSUCI. All rights reserved.
//
//  ASSUMES: Lecture 1, 2, 3, 4

#include "scanner.h"

int main(void)
{
    TOKEN *token = NULL;
    char *token2str[] = {"INVALID", "NUMBER", "IDENT", "ASSIGNMENT", "SEMICOLON", "LPAREN", "RPAREN", "PLUS", "MINUS",
                         "MULT", "DIV", "MOD", "REPEAT", "PRINT", "END_OF_INPUT"};
    printf("\n");
    while ((token = scannerAdHoc()) != NULL)
    {
        printf("{%s, %s}\n", token2str[token->type], (token->strVal != NULL) ? token->strVal : "");
        freeToken(&token);
        fflush(stdout);
    }
    printf("\n");

    return 0;
}