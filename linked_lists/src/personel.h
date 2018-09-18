#ifndef LINKED_LIST_PERSON_H
#define LINKED_LIST_PERSON_H

typedef struct
{
    char * name;
    int age;
    float height;
    struct {
        int month;
        int day;
        int year;
    } birth;
} PERSON;

PERSON * createPerson(PERSON * p);
void removePerson(PERSON *);



#endif //LINKED_LIST_PERSON_H
