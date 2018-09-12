//Keith Skinner
//Lab 4: scanner 2

/* <program> ::= <statement> | <statement> <program>
 * <statement> ::= <assignStmt> | <repeatStmt> | <printStmt>
 * <assignStmt> ::= <id> = <expr> ;
 * <repeatStmt> ::= repeat ( <expr> ) <stmt>
 * <printStmt> ::= print <expr> ;
 * <expr> ::= <term> | <term> <addOp> <expr>
 * <term> ::= <factor> | <factor> <multOp> <term>
 * <factor> ::= <id> | <number> | - <factor> | ( <expr> )
 * <id> ::= <letter> | <letter> <id>
 * <letter> ::= a | b | c | d | e | f | g | h | i | j
 * | k | l | m | n | o | p | r | s | t
 * | u | v | w | x | y | z
 * <number> ::= <digit> | <number> <digit>
 * <digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 * <addOp> ::= + | -
 * <multOp> ::= * | / | %
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

#define MAX_ROWS 64

//displays a token to stdout
void displayToken(TOKEN const *const token) {
    char const *const id = TOKEN_NAMES[token->type];
    if (token->type == NUMBER)
        printf("{<%s> %ld}", id, token->value);
    else if (isKeyword(token->type) || token->type == IDENTIFIER)
        printf("{<%s> %s}", id, token->name);
    else
        printf("{<%s>}", id);
}

//pulls tokens out of input
void scan(FILE *input, TRANS_TABLE *table) {
    //If only 1 token, then no semicolon.
    TOKEN *token = scanner(input, table);
    if (token != NULL)
        displayToken(token);
    freeToken(&token);

    //More than one token
    token = scanner(input, table);
    while (token != NULL) {
        printf(", ");
        displayToken(token);
        freeToken(&token);
        token = scanner(input, table);
    }
    freeToken(&token);
}


//initiates a new transition table
TRANS_TABLE *table_init(FILE *table_file) {
    TRANS_TABLE *trans = (TRANS_TABLE *) malloc(sizeof(TRANS_TABLE));
    char *line = (char *) malloc(MAX_LINE_LENGTH);
    size_t line_len = 0;

    //set up header info.
    long iread = getline(&line, &line_len, table_file);
    readHeader(trans, line, iread);

    //fill in rest of table.
    trans->table = (int **) malloc(MAX_ROWS * sizeof(int *));
    iread = getline(&line, &line_len, table_file);
    while (iread != -1) {
        addRow(trans, line, iread);
        iread = getline(&line, &line_len, table_file);
    }

    free(line);
    return trans;
}

int main(int argc, char *argv[]) {
    if (argc >= 1) {
        //Transition Table File
        FILE *table_file = fopen(argv[1], "r");
        if (!table_file) {
            fprintf(stderr, "Could not open table file: %s\n", argv[1]);
            exit(-1);
        }
        TRANS_TABLE *table = table_init(table_file);
        fclose(table_file);

        //Input Files
        for (int i = 2; i < argc; ++i) {
            FILE *input_file = fopen(argv[i], "r");
            if (input_file)
                scan(input_file, table);
            fclose(input_file);
            printf("\n");
        }

        //Stdin
        scan(stdin, table);
    } else {
        printf("Input Error\n"
               "\tFirst argument must be transition table file;\n"
               "\tAdditional arguments are file paths to be scanned;\n");
        exit(-2);
    }
    exit(EXIT_SUCCESS);
}
