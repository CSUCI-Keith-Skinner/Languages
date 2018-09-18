#include "person.h"
#include <stdio.h>
#include <string.h>

void add_employee(PERSON * person) {
	char * input[BUFSIZ];
	char * format = "%10s: ";
	printf(format, "NAME");
	fgets(person->name, BUFSIZ, stdin);
	printf(format, "AGE");
	fgets(input, BUFSIZ, stdin);
	sscanf(input, "%d", &(person->age));
	printf(format, "HEIGHT");
	fgets(input, BUFSIZ, stdin);
	sscanf(input, "%f", &(person->height));
	printf(format, "BIRTHDAY");
	fgets(input, BUFSIZ, stdin);
	sscanf(input, "%2d/%2d/%4d",
		&(person->birth.month),
		&(person->birth.day),
		&(person->birth.year)
	);
}
void display_all_employees(PERSON * employees[]) {
	printf("\nDisplaying all employees\n\n");
	int i = 0;
	while (employees[i] != NULL)
		display_employee(employees[i++]);
}
void display_employee(PERSON * person) {
	printf("    NAME: %s\n", person->name);
	printf("     AGE: %d\n", person->age);
	printf("  HEIGHT: %.2f\n", person->height);
	printf("BIRTHDAY: %d/%d/%d\n\n",
		person->birth.month,
		person->birth.day,
		person->birth.year
	);
}