//Keith Skinner
//Lab 4: scanner 2

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "table.h"
#include "scanner.h"


// bypasses whitespace characters and returns the first non-ws up until end.
char *skipws(char **line, char const *const end)
{//assumes contiguous string.
    while (*line < end && isspace(**line))
        ++(*line);
    return *line;
}

//only called once.
//lets me have a run-time list of all valid characters
void readHeader(TRANS_TABLE *table, char *firstLine, long len)
{
    table->header = (char *) malloc(BUF_SIZE);
    table->columns = 0;
    char const *const end = firstLine + len;
    while (skipws(&firstLine, end) < end && table->columns < BUF_SIZE) {
        table->header[table->columns] = *firstLine;
        ++firstLine;
        table->columns++;
    }
}

//create a new row in the table.
int *createRow(TRANS_TABLE *trans)
{
    const size_t rowLen = sizeof(int) * (trans->columns + 1);
    trans->table[trans->rows] = (int *) malloc(rowLen);
    int *row = trans->table[trans->rows];
    ++(trans->rows);
    return row;
}

//pull the trasnsitions from the line input
void getTransitions(int columns, int *row, char *line, char *end) {
    for (int col = 0; col < (columns) && line != end; ++col) {
        line = skipws(&line, end);
        row[col] =
                (*line == 'a') ? ACCEPT :
                (*line == 'e') ? ERROR :
                (int) strtol(line, NULL, 10); //range is only #of rows in file.
    }
}

//get the resulting token type if this line is accepted.
void getTokenType(char *line, char *end) {
    skipws(&line, end); //necessary?
    //need to capture accept string.
    if (line < end) {
        char *boundary = line;
        while (!isspace(*boundary) && *boundary != EOF)
            ++boundary;
        char word[BUF_SIZE];
        memcpy(word, line, boundary - line);

    }
}

//create, fill and attach a row to the transition table
void addRow(TRANS_TABLE *trans, char *line, size_t line_len) {
    int *row = createRow(trans);
    char *end = line + line_len;
    getTransitions(trans->columns, row, line, end);
    getTokenType(line, end);
    ++trans->rows;
}


//returns the appropriately numbered column for a legal character, ERROR otherwise
int getColumn(TRANS_TABLE *trans, char c) {
    for (int i = 0; i < trans->columns; ++i)
        if (c == trans->header[i])
            return i;
    return ERROR;
}
