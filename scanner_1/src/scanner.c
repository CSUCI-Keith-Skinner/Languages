//Keith Skinner
//Lab 3: Scanner 1

#include "scanner.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//these macros allow for clean interpretation of the scanner switch
//statement grouping cases into their respective categories without relying
//on the gcc language extension
//Intentionally missing ':' at the end for more intuitive usage for all
#define FROM_A_TO_Z                                                     \
    case'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h':    \
    case'i':case'j':case'k':case'l':case'm':case'n':case'o':case'p':    \
    case'q':case'r':case's':case't':case'u':case'v':case'w':case'x':    \
    case'y':case'z'

#define FROM_0_TO_9                             \
    case'0':case'1':case'2':case'3':case'4':    \
    case'5':case'6':case'7':case'8':case'9'

#define IS_SPACE                                            \
    case' ':case'\t':case'\n':case'\v':case'\f':case'\r'


TOKEN * ungottenToken = NULL;

//
// return token to the input, so it can be analyzed again
//
void ungetToken(TOKEN **token)
{
    ungottenToken = *token;
    *token = NULL;
}

bool isKeyword(TOKEN_TYPE type)
{
    return type == PRINT || type == REPEAT;
}

bool isNameable(TOKEN_TYPE type)
{
    return type == IDENTIFIER || type == NUMBER || isKeyword(type);
}

//
// clean up the token structure
//
void freeToken(TOKEN **token)
{
    if (*token == NULL)
        return;

    if ((**token).name != NULL && isNameable((**token).type))
        free(*token);

    *token = NULL;
}

TOKEN * newToken()
{
    TOKEN * token = (TOKEN *)malloc(sizeof(TOKEN));
    token->type = INVALID;
    token->name = NULL;
    return token;
}


void fillInputBuffer(char c, char input_buffer[], FILE * input, char low, char high)
{
    int i=0;
    do {
        input_buffer[i] = c;
        c = (char)fgetc(input);
        ++i;
    } while(low <= c && c <= high);
    input_buffer[i] = '\0';
    ungetc(c, input);
}

void makeIdentifier(char c, char input_buffer[], FILE * input)
{
    fillInputBuffer(c, input_buffer, input, 'a', 'z');
}

void makeNumber(char c, char input_buffer[], FILE * input)
{
    fillInputBuffer(c, input_buffer, input, '0', '9');
}


void setIdentifier(TOKEN * token, char * input_buffer)
{
    if (strcmp("repeat", input_buffer) == 0)
        token->type = REPEAT;
    else if (strcmp("print", input_buffer) == 0)
        token->type = PRINT;
    else
        token->type = IDENTIFIER;

    token->name = (char *)malloc(sizeof(strlen(input_buffer)+1));
    strcpy(token->name, input_buffer);
}

void setNumber(TOKEN * token, char * input_buffer)
{
    token->type = NUMBER;
    token->value = strtol(input_buffer, NULL, 10);
}

void singleCharToken(TOKEN * token, char c)
{
    token->symbol = c;
    switch (c) {
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
        default: ;//do nothing.
    }
}

TOKEN * scanner(FILE * input)
{
    if (ungottenToken != NULL) {
        TOKEN * token = ungottenToken;
        ungottenToken = NULL;
        return token;
    }

    TOKEN * token = newToken();
    char input_buffer[MAX_LINE_LENGTH];

    char c;
    do {
        c = (char)fgetc(input);
        switch(c) {
            case EOF:
                break;
            IS_SPACE:
                break;
            FROM_A_TO_Z:
                makeIdentifier(c, input_buffer, input);
                setIdentifier(token, input_buffer);
                break;
            FROM_0_TO_9:
                makeNumber(c, input_buffer, input);
                setNumber(token, input_buffer);
                break;
            default:
                singleCharToken(token, c);
        }
    } while (token->type == INVALID && c != EOF);

    if(c == EOF) {
        free(token);
        token = NULL;
    }

    return token;
}




