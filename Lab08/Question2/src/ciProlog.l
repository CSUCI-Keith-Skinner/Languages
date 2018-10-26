/**
* Name: Keith Skinner
* Lab: Lab 8 Introduction to Bison
* Date: 10/30/2018
**/

%option noyywrap
%option caseless
%option noinput
%option nounput

%{
    #include "ciProlog.h"
%}

l [a-zA-Z]
prop '{l}({l}|\ )*'

%%

"TODO"      { /* add the necessary definitions and action routines */}

"halt"      {   fprintf(stderr, "lex: HALT\n");
                return HALT;
            }
"assert"    {   fprintf(stderr, "lex: ASSERT\n");
                return ASSERT;
            }
"retract"   {   fprintf(stderr, "lex: RETRACT\n");
                return RETRACT;
            }
"NOT"       {   fprintf(stderr, "lex: NOT\n");
                return NOT;
            }
"AND"       {   fprintf(stderr, "lex: AND\n");
                return AND;
            }
"OR"        {   fprintf(stderr, "lex: OR\n");
                return OR;
            }
"("         {   fprintf(stderr, "lex: LPAREN\n");
                return LPAREN;
            }
")"         {   fprintf(stderr, "lex: RPAREN\n");
                return RPAREN;
            }
{prop}      {   yylval.sval = (char *) malloc(strlen(yytext) * sizeof(char)+1);
                strcpy(yylval.sval, yytext);
                fprintf(stderr, "lex: PROPOSITION sval = %s\n", yylval.sval);
                return PROPOSITION;
            }
"\n"        {   fprintf(stderr, "lex: EOL\n");
                YY_FLUSH_BUFFER;
                return EOL;
            }

[[:space:]] ; /* do nothing - skip whitespace */

.           { printf("ERROR: invalid character: >>%s<<\n", yytext); }

%%

/*
 * DO NOT CHANGE THE FOLLOWING CODE CRITICAL FOR REPL!
 */
int main(void)
{
    // except for this line that can be uncommented to throw away debug printouts
    freopen("/dev/null", "w", stderr);

    initKnowledgeBase();

    char *s_expr_str = NULL;
    size_t s_expr_str_len = 0;
    YY_BUFFER_STATE buffer;
    while (true)
    {
        printf("\n?- ");
        getline(&s_expr_str, &s_expr_str_len, stdin);
        printf("%s", s_expr_str);
        s_expr_str_len = strlen(s_expr_str);
        s_expr_str[s_expr_str_len++] = '\0';
        s_expr_str[s_expr_str_len++] = '\0';
        buffer = yy_scan_buffer(s_expr_str, s_expr_str_len);
        yyparse();
        yy_delete_buffer(buffer);
    }
}