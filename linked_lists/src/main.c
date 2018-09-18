#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "list.h"
<<<<<<< HEAD
#include "personel.h"
=======
#include "person.h"
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79

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
<<<<<<< HEAD
=======

>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
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
<<<<<<< HEAD
=======

>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
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
<<<<<<< HEAD
bool compareName(char * name, PERSON * person)
{
    char * pName = person->name;
    return strcmp(name, pName) == 0;
=======

bool compareName(void * name, void * person)
{
    char * pName = ((PERSON*)person)->name;
    return strcmp(pName, (char *)name) == 0;
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
}

void displayCommand(LIST * head_node) {
    if (head_node == NULL) {
<<<<<<< HEAD
        printf("\nList is empty.\n\n");
=======
        printf("\nList is empty.\n");
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
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
<<<<<<< HEAD
LIST ** createCommand(LIST ** tail) {
    printf("\nCreating new person.\n");
    PERSON * person = createPerson(NULL);
    tail = addNode(tail, person);
    putchar('\n');
	return tail;
}
LIST **findCommand(LIST **head) {
=======
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
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79

    printf("\nFinding existing person.\n");
    char * buff = malloc(BUFSIZ);
    printf("Enter name: ");
    fgets(buff, BUFSIZ, stdin);
    *strchr(buff, '\n') = '\0';
    LIST ** person = findNode(head, buff, compareName);
    free(buff);
    if (person == NULL)
<<<<<<< HEAD
        printf("\nCould not find person.\n");
    else {
        printf("Person found.\n\n");
=======
        printf("Could not find person.\n");
    else {
        printf("Person found.\n");
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
        printPerson((*person)->data);
    }
    return person;
}
<<<<<<< HEAD
void updateCommand(LIST ** head) {
=======
void updateCommand(LIST *head) {
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
    LIST ** node = findCommand(head);
    if (node != NULL) {
        printf("Updating person.\n");
        createPerson((**node).data);
    }
<<<<<<< HEAD
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
=======
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
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
    printf("Good bye.\n"); 
    return 0;   
}


