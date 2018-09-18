//Keith Skinner
//Lab 3: scanner 1

/* <program> ::= <statement> | <statement> <program>
 * <statement> ::= <assignStmt> | <repeatStmt> | <printStmt>
 * <assignStmt> ::= <id> = <expr> ;
 * <repeatStmt> ::= repeat ( <expr> ) <stmt>
 * <printStmt> ::= print <expr> ;
 * <expr> ::= <term> | <expr> <addOp> <term>
 * <term> ::= <factor> | <term> <multOp> <factor>
 * <factor> ::= <id> | <number> | - <factor> | ( <expr> )
 * <id> ::= <letter> | <letter> <id>
 * <letter> ::= a | b | c | d | e | f | g | h | i | j
 * | k | l | m | n | o | p | r | s | t
 * | u | v | w | x | y | z
 * <number> ::= <digit> | <number> <digit>
 * <digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 * <addOp> ::= + | -
 * <multOp> ::= * | / | %
 *
 * */

#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

//displays a token to stdout
void displayToken(TOKEN const * const token) {
    char const * const id = TOKEN_NAMES[token->type];
    if (token->type == NUMBER)
        printf("{<%s> %ld}", id, token->value);
    else if (isKeyword(token->type) || token->type == IDENTIFIER)
        printf("{<%s> %s}", id, token->name);
    else
        printf("{<%s>}", id);
}

//
void program(FILE * input)
{
    TOKEN * token = scanner(input);
    if (token != NULL)
        displayToken(token);

    token = scanner(input);
    while(token != NULL){
        printf(", ");
        displayToken(token);
        token = scanner(input);
    }
}

int main(int argc, char * argv[])
{
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            FILE *input = fopen(argv[i], "r");
            if (input)
                program(input);
            fclose(input);
            printf("\n");
        }
    }
    else
        program(stdin);

    return 0;
}
