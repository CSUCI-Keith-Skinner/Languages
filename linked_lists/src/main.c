#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "list.h"
#include "person.h"

#define PROMPT_CMD "Enter a command (Create, Find, Update, Delete, Display, Stop)\n: "

typedef enum {
    UNKNOWN = -1,
    CREATE = 0,
    FIND,
    UPDATE,
    DELETE,
    DISPLAY,
    STOP,
    COMMAND_COUNT
} COMMAND;

char * COMMAND_STR[COMMAND_COUNT] = {
    "create",
    "find",
    "update",
    "delete",
    "display",
    "stop"
};

COMMAND getCommand(char *input, size_t size) {
    for (size_t i=0; i<size; ++i)
        input[i] = (char)tolower(input[i]);
    for (int i=0; i<COMMAND_COUNT; ++i)
        if (strstr(input, COMMAND_STR[i]) != NULL)
            return i;
    return UNKNOWN;
}

void printPerson(PERSON * p) {
    char * display = 
        "%10s: %s\n"
        "%10s: %i\n"
        "%10s: %.1f\n"
        "%10s: %02i/%02i/%4i\n\n";
    printf(display,
            "Name", p->name,
            "Age", p->age,
            "Height", p->height,
            "Birthday", p->birth.month, p->birth.day, p->birth.year);
}

bool compareName(void * name, void * person)
{
    char * pName = ((PERSON*)person)->name;
    return strcmp(pName, (char *)name) == 0;
}

void displayCommand(LIST * head_node) {
    if (head_node == NULL) {
        printf("\nList is empty.\n");
        return;
    } else {
        printf("\nDisplaying all people.\n\n");
    }
    while (head_node != NULL) {
        printPerson(head_node->data);
        head_node = head_node->next;
    }
    putc('\n', stdout);
}
void createCommand(LIST ** tail) {
    printf("\nCreating new person.\n");
    PERSON * person = createPerson(NULL);
    addNode(&tail, person);
    putchar('\n');
}

char * getEndOfInput(char * str, int size) {
    char * end = size;
    for (int i =size-1; i<=0; --i)
        if (!isspace(str[i]))
            end = str+i;
    return end;

}

LIST **findCommand(LIST *head) {

    printf("\nFinding existing person.\n");
    char * buff = malloc(BUFSIZ);
    printf("Enter name: ");
    fgets(buff, BUFSIZ, stdin);
    *strchr(buff, '\n') = '\0';
    LIST ** person = findNode(head, buff, compareName);
    free(buff);
    if (person == NULL)
        printf("Could not find person.\n");
    else {
        printf("Person found.\n");
        printPerson((*person)->data);
    }
    return person;
}
void updateCommand(LIST *head) {
    LIST ** node = findCommand(head);
    if (node != NULL) {
        printf("Updating person.\n");
        createPerson((**node).data);
    }
}



int main() {
    LIST * head_node = NULL;
    LIST ** head = &head_node;
    LIST ** tail = &head_node;
    char * input;
    size_t input_size;

    bool stop = false;
    do {
        putchar("\02713");
        printf(PROMPT_CMD);
        getline(&input, &input_size, stdin);
        switch(getCommand(input, input_size)) {
            case  CREATE: createCommand(tail); break;
            case    FIND:
                findCommand(head); break;
            case  UPDATE: printf("\n\nUpdate.\n\n"); break;
            case  DELETE: printf("\n\nDelete.\n\n"); break;
            case DISPLAY: displayCommand(head_node); break;
            case    STOP: stop = true; break;
            default:
                printf("Command: \"%s\"\n", input);
                printf("Could not be displayed.\n");
        }
    } while (!stop);

    free(input);
    printf("Good bye.\n"); 
    return 0;   
}


