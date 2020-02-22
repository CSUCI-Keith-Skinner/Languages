/**
* Name: Keith Skinner
* Lab: Lab 2 Personnel Records
* Date: 09/25/2018
**/

#include "person.h"

LIST *head = NULL, *tail = NULL;

#define PROMPT_FORMAT   "%9s: "

#define NAME_PROMPT     "Name"
#define NAME_FORMAT     "%s"
#define AGE_PROMPT      "Age"
#define AGE_FORMAT      "%d"
#define HEIGHT_PROMPT   "Height"
#define HEIGHT_FORMAT   "%f"
#define HEIGHT_DISPLAY  "%.1f"
#define BDAY_PROMPT     "Birthday"
#define BDAY_FORMAT      "%d/%d/%d"

void inputPersonalData(PERSON *person)
{
    // TODO - DONE - Implement the function
    printf(PROMPT_FORMAT, NAME_PROMPT);
    scanf(NAME_FORMAT, person->name);
    printf(PROMPT_FORMAT, AGE_PROMPT);
    scanf(AGE_FORMAT, &(person->age));
    printf(PROMPT_FORMAT, HEIGHT_PROMPT);
    scanf(HEIGHT_FORMAT, &(person->height));
    printf(PROMPT_FORMAT, BDAY_PROMPT);
    scanf(BDAY_FORMAT, &(person->bday.month),
            &(person->bday.day), &(person->bday.year));
}

void addPersonalDataToDatabase(PERSON *person)
{
    // TODO - DONE - Implement the function
    add(&head, &tail, (void*)person);
    printf("\n");
}

void displayDatabase()
{
    // TODO - DONE - Implement the function
    printf("\nDISPLAYING DATABASE\n");
    LIST * node = head;

    //nothing to display
    if (head == NULL) {
        printf("\n  The database is empty.\n");
        return;
    }

    //print database
    while (node != NULL) {
        displayPerson(node->data);
        node = node->next;
    }
    printf("\n");
}

void displayPerson(PERSON *person)
{
    // TODO - DONE - Implement the function
    printf("\n");
    printf(PROMPT_FORMAT, NAME_PROMPT);
    printf(NAME_FORMAT "\n", person->name);
    printf(PROMPT_FORMAT, AGE_PROMPT);
    printf(AGE_FORMAT "\n", person->age);
    printf(PROMPT_FORMAT, HEIGHT_PROMPT);
    printf(HEIGHT_DISPLAY "\n", person->height);
    printf(PROMPT_FORMAT, BDAY_PROMPT);
    printf(BDAY_FORMAT  "\n", person->bday.month,
            person->bday.day, person->bday.year);
}

PERSON *findPersonInDatabase(char *name)
{
    // TODO - DONE -Implement the function
    LIST * node = head;
    while (node != NULL) {
        if (node->data != NULL && strcmp(name, ( (PERSON*)node->data )->name ) == 0)
                return (PERSON*)(node->data);
        node = node->next;
    }

    return NULL; // if not found
}

bool comparePeople(char * name, PERSON * data)
{
    return 0 == strcmp(name, data->name );
}

void removePersonFromDatabase(char *name)
{
    // TODO - DONE - Implement the function
    delete(&head, &tail, name, (bool(*)(void*,void*))comparePeople);
}

void clearDatabase()
{
    // TODO - DONE - Implement the function
    clearRecursively(&head, &tail);
}
