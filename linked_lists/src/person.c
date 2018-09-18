#include "person.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isBetween(int a, int b, int i) {
    return a <= i && i <= b;
}

void setPersonName(PERSON * p, char * name, const int SIZE) {
    fgets(name, SIZE, stdin);
    size_t length = strlen(name)+1;
    p->name = (char *)realloc(p->name, length);
    strcpy(p->name, name);
}
void setPersonAge(PERSON *p, const char *prompt, char *input_buffer, char **buff_pos) {
    do {
        printf(prompt, "Age");
        fgets(input_buffer, BUFSIZ, stdin);
        p->age = (int) strtol(input_buffer, buff_pos, 10);
    } while(p->age <= 0);
}

void setPersonHeight(PERSON *p, const char * prompt, char * input_buffer, char ** buff_pos) {
    do {
        printf(prompt, "Height");
        fgets(input_buffer, BUFSIZ, stdin);
        p->height = strtof(input_buffer, buff_pos);
    } while (p->height <= 0.0);
}

void setPersonBirthday(PERSON *p, const char * prompt, char * input_buffer) {
    do {
        printf(prompt, "Birthday");
        fgets(input_buffer, BUFSIZ, stdin);
        sscanf(input_buffer, "%2d/%2d/%04d",
               &p->birth.month, &p->birth.day, &p->birth.year);
    } while (!isBetween(1, 12, p->birth.month) ||
             !isBetween(1, 31, p->birth.day) ||
             !isBetween(1900, 2018, p->birth.year));
}

//p must be pointing to either NULL or a valid person.
PERSON * createPerson(PERSON * p) {
    char const * const prompt = "%10s: ";
    char input_buffer[BUFSIZ] = {0};
    char * buff_pos = input_buffer;

    free(p->name);
    p->name = NULL;
    p = (PERSON *)realloc(p, sizeof(PERSON));

    setPersonName(p, input_buffer, BUFSIZ);
    setPersonAge(p, prompt, input_buffer, &buff_pos);
    setPersonHeight(p, prompt, input_buffer, &buff_pos);
    setPersonBirthday(p, prompt, input_buffer);
    return p;
}

void removePerson(PERSON * p) {
    free(p->name);
    free(p);
}
