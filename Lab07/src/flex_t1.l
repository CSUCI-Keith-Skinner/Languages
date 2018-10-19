/**
* Name: Keith Skinner
* Lab: Lab 7 Introduction to flex
* Date: 10/23/2018
**/

/* NOTE: % must be in the first column (no indentation) */

%option noyywrap
%option nounput
%option noinput

digit  [0-9]
letter [a-z]

%{
   #include "flex_t1.h"
%}

%%

"if"                            {return IF_TOKEN;}
"then"                          {return THEN_TOKEN;}
"while"                         {return WHILE_TOKEN;}
"do"                            {return DO_TOKEN;}
"print"                         {return PRINT_TOKEN;}

";"                             {return SEMICOLON_TOKEN;}
"="                             {return EQUAL_TOKEN;}
"("                             {return LPAREN_TOKEN;}
")"                             {return RPAREN_TOKEN;}
"+"                             {return ADD_TOKEN;}
"-"                             {return SUBTRACT_TOKEN;}
"*"                             {return MULTIPLY_TOKEN;}
"/"                             {return DIVIDE_TOKEN;}
"%"                             {return MODULUS_TOKEN;}

{letter}({letter}|{digit}|_)*   {return ID_TOKEN;}
{digit}[.]?{digit}*            {return NUMBER_TOKEN;}

%%

void yyerror(char *s) {/* dummy */}
