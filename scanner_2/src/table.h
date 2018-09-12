
#ifndef SCANNER_2_TABLE_H
#define SCANNER_2_TABLE_H

#include <stdio.h>

#define MAX_STATES 64
#define START 0
#define ACCEPT 64
#define ERROR -1

typedef struct trans_table {
    int rows;
    int columns;
    int **table;
    char *header;
} TRANS_TABLE;

void readHeader(TRANS_TABLE *table, char *firstLine, long len);

void addRow(TRANS_TABLE *trans, char *line, size_t line_len);

int getColumn(TRANS_TABLE *trans, char c);

#endif //SCANNER_2_TABLE_H