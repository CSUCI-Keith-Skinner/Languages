//Keith Skinner
//Lab 4: scanner 2

#include "scanner.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//token type is special identifier
bool isKeyword(TOKEN_TYPE type) {
    return type == PRINT || type == REPEAT;
}

TOKEN_TYPE tokenNameToType(char *name) {
    for (int i = 0; i < NUM_OF_TOKENS; ++i)
        if (strcmp(name, TOKEN_NAMES[i]) == 0)
            return i;
    return 0;
}


//does the name get displayed when printed
bool isNameable(TOKEN_TYPE type) {
    return type == IDENTIFIER || type == NUMBER || isKeyword(type);
}

//sets the literal value for the token rather than the type
void setTokenValue(TOKEN *token, char *input_buffer, int length) {
    //single character token
    if (!isNameable(token->type))
        token->symbol = input_buffer[0];
        //atoi complains with clang-tidy or clangd
    else if (token->type == NUMBER)
        token->value = strtol(input_buffer, NULL, 10);
        //identifier that needs its own copy of the string
    else {
        token->name = malloc(length + 1);
        strcpy(token->name, input_buffer);
    }
}

//transitions the state machine forward until it has to stop and a token-type is returned
TOKEN_TYPE transition(TRANS_TABLE *trans, FILE *input, char input_buffer[], int *length) {
    int state = START;
    int column = ERROR;
    char c = 0;
    do {
        //grab a character and find out where it belongs
        c = (char) fgetc(input);
        column = getColumn(trans, c);

        //transition the state matchine if we're not done
        if (column != ERROR && trans->table[state][column] != ACCEPT) {
            state = trans->table[state][column];
            input_buffer[*length] = c;
            ++(*length);
        }
    } while (column != ERROR || trans->table[state][column] != ACCEPT);
    input_buffer[*length] = '\0';
    ungetc(c, input);

    //only empty input_buffers have invalid characters for reattachment down the line
    return (column == ERROR && *length == 0) ? INVALID : trans->table[state][trans->columns];
}


TOKEN *scanner(FILE *input, TRANS_TABLE *table) {

    TOKEN *token = (TOKEN *) malloc(sizeof(TOKEN));
    char input_buffer[MAX_LINE_LENGTH];
    int length = 0;
    token->type = transition(table, input, input_buffer, &length);

    //reattach the token value
    if (token->type == INVALID)
        *token = (TOKEN) {INVALID, .symbol=fgetc(input)};
    if (length != 0)
        setTokenValue(token, input_buffer, length);
    return token;
}

void freeToken(TOKEN **token) {
    if (token && *token) {
        if (isNameable((**token).type))
            free((**token).name);
        free(*token);
        *token = NULL;
    }
}
