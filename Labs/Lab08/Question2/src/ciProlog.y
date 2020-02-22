/**
* Name: Keith Skinner
* Lab: Lab 8 Introduction to Bison
* Date: 10/30/2018
**/

/*
logexpr ::=
proposition
| assert ( proposition )
| retract ( proposition )
| ( logexpr )
| NOT logexpr
| logexpr AND logexpr
| logexpr OR logexpr

letter ::= [a-zA-Z]
proposition ::= '{letter}({letter}|\ )*'
*/

%{
#include "ciProlog.h"
%}

%union
{
   bool bval;
   char *sval;
};

%token <sval> PROPOSITION
%token ASSERT RETRACT NOT AND OR LPAREN RPAREN EOL HALT

%type <bval> logexpr

%%

program:
    logexpr EOL {
        fprintf(stderr, "yacc: program ::= logexpr EOL\n");
        printf("=> %s\n", bool2str($1));
    };

logexpr:
    PROPOSITION {
        fprintf(stderr, "yac: PROPOSITION %s\n", $1);
        $$ = eval($1);
    }|
    ASSERT LPAREN PROPOSITION RPAREN {
        fprintf(stderr, "yac: ASSERT ( %s )\n", $3);
        $$ = assert($3);
    }|
    RETRACT LPAREN PROPOSITION RPAREN {
        fprintf(stderr, "yac: RETRACT ( %s )\n", $3);
        $$ = retract($3);
    }|
    LPAREN logexpr RPAREN {
        fprintf(stderr, "yac: ( %s )\n", bool2str($2));
        $$ = $2;
    }|
    NOT logexpr {
        fprintf(stderr, "yac: NOT %s\n", bool2str($2));
        $$ = not($2);
    }|
    logexpr AND logexpr {
        fprintf(stderr, "yac: %s AND %s\n", bool2str($1), bool2str($3));
        $$ = and($1, $3);
    }|
    logexpr OR logexpr {
        fprintf(stderr, "yac: %s OR %s\n", bool2str($1), bool2str($3));
        $$ = or($1, $3);
    }|
    HALT {
        fprintf(stderr, "yacc: logexpr ::= HALT\n");
        exit(0);
    }
    /* TODO complete the definition of the grammar */
    ;

%%

