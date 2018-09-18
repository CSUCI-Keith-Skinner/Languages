#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "list.h"
#include "personel.h"

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
bool compareName(char * name, PERSON * person)
{
    char * pName = person->name;
    return strcmp(name, pName) == 0;
}

void displayCommand(LIST * head_node) {
    if (head_node == NULL) {
        printf("\nList is empty.\n\n");
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
LIST ** createCommand(LIST ** tail) {
    printf("\nCreating new person.\n");
    PERSON * person = createPerson(NULL);
    tail = addNode(tail, person);
    putchar('\n');
	return tail;
}
LIST **findCommand(LIST **head) {

    printf("\nFinding existing person.\n");
    char * buff = malloc(BUFSIZ);
    printf("Enter name: ");
    fgets(buff, BUFSIZ, stdin);
    *strchr(buff, '\n') = '\0';
    LIST ** person = findNode(head, buff, compareName);
    free(buff);
    if (person == NULL)
        printf("\nCould not find person.\n");
    else {
        printf("Person found.\n\n");
        printPerson((*person)->data);
    }
    return person;
}
void updateCommand(LIST ** head) {
    LIST ** node = findCommand(head);
    if (node != NULL) {
        printf("Updating person.\n");
        createPerson((**node).data);
    }
	putchar('\n');
}
void deleteCommand(LIST ** head, LIST *** tail) {
	LIST ** node = findCommand(head);
	if (node != NULL) {
		printf("Deleting person.\n");
		PERSON *person = removeNode(tail, node);
		removePerson(person);
	}
	putchar('\n');
}


int main() {
    LIST * head_node = NULL;
    LIST ** tail = &head_node;
	char input[BUFSIZ] = { 0 };
	int input_size = BUFSIZ;

    bool stop = false;
    do {
        printf(PROMPT_CMD);
        fgets(input, input_size, stdin);
		*strchr(input, '\n') = '\0'; //so annoying that there's no cstd for this.
        switch(getCommand(input, input_size)) {
            case  CREATE: tail = createCommand(tail); break;
            case    FIND: findCommand(&head_node); break;
			case  UPDATE: updateCommand(&head_node); break;
            case DISPLAY: displayCommand(head_node); break;
			case  DELETE: deleteCommand(&head_node, &tail); break;
            case    STOP: stop = true; break;
            default:
                printf("Command: \"%s\n\" is invalid.\n\n", input);
        }
    } while (!stop);

	deleteList(&head_node, removePerson); //clean up linked list
    printf("Good bye.\n"); 
    return 0;   
}


