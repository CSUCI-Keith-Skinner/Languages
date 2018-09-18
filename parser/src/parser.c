

#include "parser.h"

struct 

TOKEN *scanner();

AST_NODE *program()
{
    
}

AST_NODE *statement();
AST_NODE *assignStmt(TOKEN *currToken);
AST_NODE *repeatStmt(TOKEN *currToken);
AST_NODE *printStmt(TOKEN *currToken);
AST_NODE *expr(TOKEN *currToken);
AST_NODE *term(TOKEN *currToken);
AST_NODE *factor(TOKEN *currToken);
AST_NODE *id(TOKEN *currToken);
AST_NODE *number(TOKEN *currToken);
void error();