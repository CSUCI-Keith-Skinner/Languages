#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct list_tag
{
    struct list_tag *next;
    void *data;
} LIST;

void addNode(LIST ***tail, void *data);
int isEmpty(LIST *head);
bool isLastElement(LIST **tail, LIST **n);
void *removeNode(LIST **tail, LIST **n);
LIST **findNode(LIST *head, void *obj, bool (*compare)(void *, void *));

#endif //LINKED_LIST_LIST_H
