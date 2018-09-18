// TODO : the main program should read in the data for a number of employees by first
// prompting the user for the number of employees, allocating sufficient space for the
// employees in the array, and then calling the add_employee() function to populate the
// current element of the array.
#include <stdio.h>
#include <stdlib.h>
#include "person.h"

#define EMPLOYEE_COUNT 100

int main() 
{
	PERSON * employees[EMPLOYEE_COUNT] = { NULL };
	printf("How many employees (max 100)?: ");
	char input[BUFSIZ];
	fgets(input, BUFSIZ, stdin);
	int size = 0;
	sscanf(input, "%d", &size);
	
	for (int i = 0; i < size; ++i) {
		employees[i] = malloc(sizeof(PERSON));
		add_employee(employees[i]);
	}

	display_all_employees(employees);
}
