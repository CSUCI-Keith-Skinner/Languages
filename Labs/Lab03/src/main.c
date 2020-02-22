/**
* Name: Keith Skinner
* Lab: Lab 2 Personnel Records
* Date: 09/25/2018
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

#define DEF_NUM 1

int main(void)
{
    PERSON *person;

    int num;
    puts("Enter the initial number of records:");
    if (scanf("%d", &num) < 1)
        num = DEF_NUM;

    while (num-- > 0)
    {
        person = (PERSON *) malloc(sizeof(PERSON));
        inputPersonalData(person);
        addPersonalDataToDatabase(person);
    }

    displayDatabase();

    puts("\n--> Searching database for Maya");
    PERSON *maya = findPersonInDatabase("Maya");
    if (maya == NULL)
        puts("Maya not found");
    else
    {
        displayPerson(maya);
        puts("\n--> Removing Maya from database");
        removePersonFromDatabase("Maya");
    }
    displayDatabase();

    puts("\n--> Adding new record to database");
    person = (PERSON *) malloc(sizeof(PERSON));
    inputPersonalData(person);
    addPersonalDataToDatabase(person);

    displayDatabase();

    puts("\n--> Clearing database");
    clearDatabase();

    displayDatabase();
}

