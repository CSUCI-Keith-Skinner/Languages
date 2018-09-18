<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include "table.h"
#include "scanner.h"

#define MAX_STATES CHAR_MAX

// final colon intentionally left off
#define CASE_0_9 \
	case'0': case'1': case'2': case'3': case'4': case'5': case'6': case'7': case'8': case'9'

int getLine(char * line, int size, FILE * strm) {
	int i = 0; 
	char c = 0;
	do {
		c = fgetc(strm);
		line[i] = c;
		if (line[i] == '\n' || feof(strm))
			line[i] = '\0';
		else ++i;
	} while (c != '\n' && i < size && !feof(strm));
	return i;
}

FILE * skipwsStrm(FILE * strm)
{
	char c = 0;
	do c = fgetc(strm);
	while (isspace(c) && c !='\n');
	ungetc(c, strm);
	return strm;
}

int getNext(FILE * strm) {
	int c = fgetc(strm);
	if (c == 'a')
		return ACCEPT;
	if (c == 'e')
		return ERROR;
	if (c == '\n')
		return -1;
	if ('0' <= c && c <= '9') {

		char c2 = fgetc(strm);
		if ('0' <= c2 && c2 <= '9')
			return (c - '0') * 10 + (c2 - '0');
	}
	fscanf(strm, "%d", &c);
	return c;
}

void getRow(int * line, int size, int columns, FILE * strm) 
{
	printf("    ");
	int i = 0;
	do line[i++] = getNext(skipwsStrm(strm));
	while (i < columns + 1 && line[i - 1] != -1);
	if (line[i] != -1)
		line[i++] = tokenNameToType(line + i);
	line[i-1] = '\0';
}

int getHeader(char * line, int size, FILE * strm) 
{
	int i = 0;
	do line[i++] = fgetc(skipwsStrm(strm));
	while (i < size && line[i-1] != -1);
	line[i - 1] = '\0';
	return i;
}

void displayHeader(char * header, int columns) {
	printf("%3s:", "-");
	for (size_t i = 0; i < columns; ++i)
		printf("%3c", header[i]);
	printf("\n");
}

void displayRows(int ** table, int rows, int columns) {
	for (int r = 0; r < rows; ++r) {
		printf("%3d:", r);
		for (int c = 0; c < columns; ++c) {
			printf("%3d", (unsigned int)table[r][c]);
		}
		putchar('\n');
	}
}

bool getStates(char * line, int size, int * row, int columns, char * accept)
{
	int column = 0;
	int i = 0;
	while (i < size && column < columns) {
		switch (line[i]) {
		case 'a': row[column++] = ACCEPT; break;
		case 'e': row[column++] = ERROR; break;
		CASE_0_9: {
			char * pos = line + i;
			long val = strtol(pos, &pos, 10);
			row[column++] = (int)val;
			i = pos - line;
			}
		}
	}
	if (column != columns)
		return false;
	accept = line + i;
}

char * filename = "C:\\Users\\Keith\\Desktop\\Languages\\scanner_2\\table.txt";
int main() {
    //open table file
    TRANS_TABLE table = { 0 };

	char asdf[] = "  123asdf";
	char * ptr = NULL;
	long i = strtol(asdf, &ptr, 10);

    FILE * ftable = fopen(filename, "r");
	char cLine[MAX_LINE_LENGTH] = { 0 };
	int iLine[MAX_LINE_LENGTH] = { 0 };
	int nRead = getLine(cLine, MAX_LINE_LENGTH, ftable);
	while (!feof(ftable)) {
		nRead = getLine(cLine, MAX_LINE_LENGTH, ftable);
	}
	/*
	table.columns = getHeader(cLine, MAX_LINE_LENGTH, ftable);
	table.header = (char *)malloc(table.columns);
	strcpy(table.header, cLine);

	displayHeader(table.header, table.columns);

	table.table = (int**)calloc(MAX_STATES, sizeof(int*));
	table.table[0] = (int *)calloc(table.columns + 1, sizeof(int));
	int iLine[MAX_LINE_LENGTH] = { 0 };
	getRow(iLine, MAX_LINE_LENGTH, table.columns, ftable);

	displayRows(table.table, 1, table.columns + 1);
	*/
	/*
    //create the row data
    //const size_t ALPHABET = strlen(table.header);
    table.table = (int**)malloc(MAX_STATES * sizeof(int*)); //array of arrays of ints
    for (int state=0; state<MAX_STATES; ++state) {
        int * alloc = 0;
        alloc = (int*)malloc( (ALPHABET+1) * sizeof(int*) ); //array of ints
        table.table[state] = alloc;

        //grab individual transition data
		fgets(line, MAX_LINE_LENGTH, stdin);

        for(size_t i=0; skipws2(&line, last)<last && i<ALPHABET; ++i) {
            if (*line == 'a') {
                int ** t1 = table.table;
                int * t2 = t1[state];
                t2[i] = ACCEPT;
                ++line;
            } else if (*line == 'e') {
                table.table[state][i] = ERROR;
                ++line;
            } else
                table.table[state][i] = (int)strtol(line, &line, 10);
        }

        //grab the acceptance data
        char tokenName[BUF_SIZE] = { 0 };
        sscanf(line, "%s", tokenName);
        table.table[state][ALPHABET] = tokenNameToType(tokenName);

        //check that they're all there
        printf("%3d:", state);
        for (size_t i=0; i<=ALPHABET; ++i)
            printf("%3d", table.table[state][i]);
        printf("  %s\n",tokenName);
    }

	*/
    return 0;
=======
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
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
}
