#include "person.h"

#include <stdlib.h>
#include <string.h>

void create_person_name(PERSON * p, char * name) {
    if (p->name != NULL)
        free(p->name);
    const int length = strlen(name)+1;
    p->name = (char *)malloc(length);
    strcpy_s(p->name, length, name);
}

void remove_person(PERSON * p) {
    free(p->name);
    free(p);
}