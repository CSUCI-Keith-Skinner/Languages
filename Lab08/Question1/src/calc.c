/**
* Name: Keith Skinner
* Lab: Lab 8 Introduction to Bison
* Date: 10/30/2018
**/

#include "calc.h"

void yyerror(char *s) {
   printf("\nERROR: %s\n", s);
   // note stderr that normally defaults to stdout, but can be redirected: ./src 2> src.log
   // CLion will display stderr in a different color from stdin and stdout
}

/*
 * The function to resolve a name of a function; i.e., to translate it to an int equivalent (if possible)
 * that can be used conveniently in the src() function.
 */
int resolveFunc(char *func) {
   // all functions are exactly as they appear in math.h; use man to get details
   char *funcs[] = {"neg", "abs", "exp", "sqrt", "add", "sub", "mult", "div", "remainder", "log", "pow", "max", "min",
                    ""};

   int i = 0;
   while (funcs[i][0] != '\0') {
      if (!strcmp(funcs[i], func))
         return i;
      i++;
   }
   yyerror("invalid function"); // paranoic -- should never happen
   return -1;
}

/*
 * The function to calculate simple math operation.
 *
 * The values of op1 and op2 may be omitted for functions that take one or no parameters.
 */
double calc(char *func, double op1, double op2) {
    enum {
        NEG, ABS, EXP,
        SQRT, ADD, SUB,
        MULT, DIV, REMAINDER,
        LOG, POW, MAX, MIN
    };

    // TODO: implement the function, so it returns correct
    // values for each set of parameters
    switch(resolveFunc(func))
    {
    case  NEG: return -op1;
    case  ABS: return fabs(op1);
    case  EXP: return exp(op1);
    case SQRT: return sqrt(op1);
    case  ADD: return op1 + op2;
    case  SUB: return op1 - op2;
    case MULT: return op1 * op2;
    case  DIV: return op1 / op2;
    case  LOG: return log(op1);
    case  POW: return pow(op1, op2);
    case  MAX: return fmax(op1, op2);
    case  MIN: return fmin(op1, op2);
    case REMAINDER: return fmod(op1, op2);
    default:  return 0.0;
    }
}  
