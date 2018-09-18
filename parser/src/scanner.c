//
//  scanner_ad_hoc.c
//
//  Created by Bieszczad, A.J. on 2/21/13.
//  Copyright (c) 2013 CSUCI. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

//these macros allow for clean interpretation of the scanner switch
//statement grouping cases into their respective categories without relying
//on the gcc language extension
//Intentionally missing ':' at the end for more intuitive usage for all
#define CASE_A_Z \
    case'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h': \
    case'i':case'j':case'k':case'l':case'm':case'n':case'o':case'p': \
    case'q':case'r':case's':case't':case'u':case'v':case'w':case'x': \
    case'y':case'z'

#define CASE_0_9 \
    case '0': case '1': case '2': case '3': case '4': \
    case '5': case '6': case '7': case '8': case '9'

#define CASE_SPACE \
    case' ':case'\t':case'\n':case'\v':case'\f':case'\r'

TOKEN *ungottenToken = NULL;

//
// return token to the input, so it can be analyzed again
//
void ungetToken(TOKEN **token)
{
    ungottenToken = *token;
    *token = NULL;
}

//
// clean up the token structure
//
void freeToken(TOKEN **token)
{
    if (*token == NULL)
        return;

    if ((*token)->strVal != NULL)
        free((*token)->strVal);

    free(*token);

    *token = NULL;
}

//
// check if a collected sequence of characters is a keyword
//
int isKeyword(TOKEN *token, char *str)
{
    if( strcmp( str, "repeat" ) == 0 )
        token->type = REPEAT;
    else if( strcmp( str, "print" ) == 0 )
        token->type = PRINT;
    else
        return 0;

    return 1;
}



//
// scan input for a token using the ad hoc method
//
TOKEN *scannerAdHoc()
{
    // reuse any token returned to the input
    if (ungottenToken != NULL)
    {
        TOKEN *tok = ungottenToken;
        ungottenToken = NULL;
        return tok;
    }

    // temporary buffer for collecting characters
    char tempString[BUF_SIZE];

    // acquire space for the new token
    TOKEN *token = (TOKEN*) malloc(sizeof(TOKEN));
    token->type = INVALID_TOKEN; // assume that the toekn is invalid to start with
    token->strVal = NULL;

    // analyze the input character by character figuring out what kind of token they constitute
    char c;
    int i;
    while ((token->type == INVALID_TOKEN) && ((c = (char)getchar()) != EOF ))
    {
        switch (c) {
            CASE_SPACE:
                break;
            CASE_A_Z:
                i = 0;
                do {
                    tempString[i++] = c;
                    c = (char)getchar();
                } while( c >= 'a' && c <= 'z');
                tempString[i] = '\0';
                ungetc(c, stdin); // the last character read is not a letter, so return it to the input stream
                if (!isKeyword(token, tempString))
                {
                    token->type = IDENTTOKEN;
                    token->strVal = (char*)malloc(strlen(tempString) + 1);
                    strcpy(token->strVal, tempString);
                }
                return token;
            CASE_0_9:
                token->type = NUMBERTOKEN;
                i = 0;
                do {
                    tempString[i++] = c;
                    c = (char)getchar();
                } while( c >= '0' && c <= '9');
                tempString[i] = '\0';
                ungetc(c, stdin);

                // this scanner saves each token as a string and
                // assumes that the parser will interpret it as needed
                token->strVal = (char *)malloc(strlen(tempString) + 1);
                strcpy(token->strVal, tempString);
                return token;
            default:
                // save the single character so the parser may distinguish operators if needed
                token->strVal = malloc(sizeof(char));
                token->strVal[0] = c;
                switch(c) {
                    case '=':
                        token->type = ASSIGNMENT;
                        break;
                    case ';':
                        token->type = SEMICOLON;
                        break;
                    case '(':
                        token->type = LPAREN;
                        break;
                    case ')':
                        token->type = RPAREN;
                        break;
                    case '+':
                        token->type = PLUS;
                        break;
                    case '-':
                        token->type = MINUS;
                        break;
                    case '*':
                        token->type = MULT;
                        break;
                    case '/':
                        token->type = DIV;
                        break;
                    case '%':
                        token->type = MOD;
                        break;
                    default: //invalid character but we'll just skip over it.
                        break;
                }
                return token;
        }
    }
    if (c == EOF)
    {
        free(token);
        return NULL;
    }
    return token;
}