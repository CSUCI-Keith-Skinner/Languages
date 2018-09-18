#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include "personel.h"

typedef struct list_tag
{
    struct list_tag *next;
    void *data;
} LIST;

LIST ** addNode(LIST **tail, void *data);
int isEmpty(LIST *head);
bool isLastElement(LIST **tail, LIST **n);
void *removeNode(LIST ***tail, LIST **n);
LIST **findNode(LIST **head, void *obj, bool (*compare)(void *, void *));
void deleteList(LIST ** head, void (*deleteData)(void *));

#endif //LINKED_LIST_LIST_H
