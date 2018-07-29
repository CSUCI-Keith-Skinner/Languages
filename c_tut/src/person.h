#ifndef PERSON_H
#define PERSON_H

#define NAME_LEN 41

typedef struct person_tag {
	char name[NAME_LEN];
	int age;
	float height;
	struct {
		int month;
		int day;
		int year;
	} birth;
} PERSON;

void add_employee(PERSON *);
void display_all_employees(PERSON *[]);
void display_employee(PERSON *);

#endif //PERSON_H