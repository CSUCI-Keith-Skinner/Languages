// TODO - DONE :  create a file calc.c that implements a simple calculator utility that performs four basic operations: + - / * on two operands. The program should prompt the user for the operation to perform in an endless loop.

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

double calc(double l, double r, double(*op)(double, double)) { return op(l, r); }
double add(double lhs, double rhs) { return lhs + rhs; }
double sub(double lhs, double rhs) { return lhs - rhs; }
double mul(double lhs, double rhs) { return lhs * rhs; }
double divide(double lhs, double rhs) { return lhs / rhs; }

int main() {
	char buffer[BUFFER_SIZE];
	double lhs, rhs;
	char op;
	while (1) {
		printf("\ncalc>");
		fgets(buffer, BUFFER_SIZE, stdin);
		int found = sscanf(buffer, "%lf %[+-/*] %lf", &lhs, &op, &rhs);
		if (found == 3) {
			switch (op) {
			case '+': printf("%lf", calc(lhs, rhs, add)); break;
			case '-': printf("%lf", calc(lhs, rhs, sub)); break;
			case '*': printf("%lf", calc(lhs, rhs, mul)); break;
			case '/': printf("%lf", calc(lhs, rhs, divide)); break;
			default: printf("Unrecognized operator %c.", op);
			}
		}
		else
			printf("Could not find <number> <operator> <number>.");
	}
	return 0;
}