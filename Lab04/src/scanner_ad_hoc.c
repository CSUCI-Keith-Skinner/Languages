/**
* Name: Keith Skinner
* Lab: Lab 4 Nested Cases Scanner
* Date: 10/02/2018
**/

#include "scanner.h"

#define CASE_A_TO_Z \
    case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j': \
    case 'k':case 'l':case 'm':case 'n':case 'o':case 'p':case 'q':case 'r':case 's':case 't': \
    case 'u':case 'v':case 'w':case 'x':case 'y':case 'z'
#define CASE_0_TO_9 \
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9'
#define CASE_SPACE \
    case ' ': case '\t': case '\n': case '\r':


TOKEN *ungottenToken = NULL; // used by parser

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
    if (token == NULL)
        return;

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
bool isKeyword(TOKEN *token, char *str)
{
    if (strcmp(str, "repeat") == 0)
        token->type = REPEAT_TOKEN;
    else if (strcmp(str, "print") == 0)
        token->type = PRINT_TOKEN;
    else
        return false;

    return true;
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
    TOKEN *token = (TOKEN *) calloc(1, sizeof(TOKEN));

    // analyze the input character by character figuring out what kind of token they constitute
    char c;
    int i;
    while ((token->type == INVALID_TOKEN) && ((c = getchar()) != EOF))
    {
        switch (c)
        {
            case ' ': // skip whitespace
            case '\t':
            case '\n':
                break;
            case 'a'...'z': // c is a letter
                i = 0;
                do
                {
                    tempString[i++] = c;
                    c = getchar();
                } while (c >= 'a' && c <= 'z');
                tempString[i] = '\0';
                ungetc(c, stdin); // the last character read is not a letter, so return it to the input stream
                if (!isKeyword(token, tempString))
                {
                    token->type = IDENT_TOKEN;
                    token->strVal = (char *) malloc(strlen(tempString) + 1);
                    strcpy(token->strVal, tempString);
                }
                return token;
            case '0'...'9': // if c is a number
                i = 0;
                do
                {
                    tempString[i++] = c;
                    c = getchar();
                } while (c >= '0' && c <= '9');
                tempString[i] = '\0';
                ungetc(c, stdin);
                token->type = NUMBER_TOKEN;
                // this scanner saves each token as a string and
                // assumes that the parser will interpret it as needed
                token->strVal = (char *) malloc(strlen(tempString) + 1);
                strcpy(token->strVal, tempString);
                return token;
            default:
                // save the single character so the parser may distinguish operators if needed
                token->strVal = malloc(sizeof(char) + 1);
                token->strVal[0] = c;
                token->strVal[1] = '\0';
                switch (c)
                {
                    case '=':
                        token->type = ASSIGNMENT_TOKEN;
                        break;
                    case ';':
                        token->type = SEMICOLON_TOKEN;
                        break;
                    case '(':
                        token->type = LPAREN_TOKEN;
                        break;
                    case ')':
                        token->type = RPAREN_TOKEN;
                        break;
                    case '+':
                        token->type = PLUS_TOKEN;
                        break;
                    case '-':
                        token->type = MINUS_TOKEN;
                        break;
                    case '*':
                        token->type = MULT_TOKEN;
                        break;
                    case '/':
                        token->type = DIV_TOKEN;
                        break;
                    case '%':
                        token->type = MOD_TOKEN;
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

