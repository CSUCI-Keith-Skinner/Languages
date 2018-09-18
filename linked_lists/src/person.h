#ifndef LINKED_LIST_PERSON_H
#define LINKED_LIST_PERSON_H

typedef struct person_tag 
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

void create_person_name(PERSON * p, char * name);
void remove_person(PERSON *);



#endif //LINKED_LIST_PERSON_H