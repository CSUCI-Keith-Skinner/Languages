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
    case ' ': case '\t': case '\n': case '\r'

TOKEN * ungottenToken = NULL; // used by parser

TOKEN *scanner();
TOKEN *scannerAdHoc()
{
    return scanner();
}

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
TOKEN * changeKeyword(TOKEN *token)
{
    if (strcmp(token->strVal, "repeat") == 0)
        token->type = REPEAT_TOKEN;
    else if (strcmp(token->strVal, "print") == 0)
        token->type = PRINT_TOKEN;
    return token;
}

TOKEN * createStringToken(TOKEN * token, char inputStr[], size_t inputSize, int input)
{
    token->strVal = calloc(inputSize+1, sizeof(char));
    strcpy(token->strVal, inputStr);
    ungetc(input, stdin);
    return token;
}

TOKEN * createCharToken(TOKEN * token, int input, char c)
{
    ungetc(input, stdin);
    token->strVal = calloc(2, sizeof(char));
    token->strVal[0] = c;
    return token;
}



TOKEN *scanner()
{

    // reuse any token returned to the input
    if (ungottenToken != NULL)
    {
        TOKEN *tok = ungottenToken;
        ungottenToken = NULL;
        return tok;
    }



    // acquire space for the new token
    TOKEN *token = (TOKEN *) calloc(1, sizeof(TOKEN));

    // temporary buffer for collecting characters
    char inputStr[MAX_LINE_LENGTH] = { 0 };
    size_t inputSize = 0;

    int input = 0;
    while (true)
    {
        input = fgetc(stdin);
        switch (token->type) {
            case INVALID_TOKEN:
                switch (input) {
                    CASE_SPACE:
                        break; //skip spaces
                    CASE_0_TO_9:
                        inputStr[inputSize++] = (char)input;
                        token->type = NUMBER_TOKEN;
                        break;
                    CASE_A_TO_Z:
                        inputStr[inputSize++] = (char)input;
                        token->type = IDENT_TOKEN;
                        break;
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
                    case EOF:
                        return NULL;
                    default: //invalid input.
                        token->strVal = calloc(2, sizeof(char));
                        token->strVal[0] = (char)input;
                        return token;
                }
                break;

            case NUMBER_TOKEN:
                switch (input) {
                    CASE_0_TO_9:
                        inputStr[inputSize++] = (char)input;
                        break;

                    CASE_SPACE:
                    CASE_A_TO_Z:
                    case '=':
                    case ';':
                    case '(':
                    case ')':
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                    case EOF:
                    default :
                        createStringToken(token, inputStr, inputSize, input);
                        return token;
                }
                break;

            case IDENT_TOKEN:
                switch (input) {
                    CASE_A_TO_Z:
                        inputStr[inputSize++] = (char)input;
                        break;

                    CASE_0_TO_9:
                    case '=':
                    case ';':
                    case '(':
                    case ')':
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                    case EOF:
                    default :
                        createStringToken(token, inputStr, inputSize, input);
                        changeKeyword(token);
                        return token;
                }
                break;

            case ASSIGNMENT_TOKEN:
                return createCharToken(token, input, '=');
            case SEMICOLON_TOKEN:
                return createCharToken(token, input, ';');
            case LPAREN_TOKEN:
                return createCharToken(token, input, '(');
            case RPAREN_TOKEN:
                return createCharToken(token, input, ')');
            case PLUS_TOKEN:
                return createCharToken(token, input, '+');
            case MINUS_TOKEN:
                return createCharToken(token, input, '-');
            case MULT_TOKEN:
                return createCharToken(token, input, '*');
            case DIV_TOKEN:
                return createCharToken(token, input, '/');
            case MOD_TOKEN:
                return createCharToken(token, input, '%');
            case END_OF_INPUT_TOKEN:
                return NULL;
            default:
                return token;
        }
    }
}