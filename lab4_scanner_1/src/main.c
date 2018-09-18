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



void program(FILE *pFILE);

int main(int argc, char * argv[]) {
    for (int i=1;i<argc; ++i) {
        FILE * input = fopen(argv[i], "r");
        if (input)
            program(input);
        fclose(input);
    }
    program(stdin);

    return 0;
}

void program(FILE * input) {
    char c = 0;
    do
    {
        c = fgetc(input);
        if ()

    } while (c != EOF);
}
