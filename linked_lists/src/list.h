#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

#include <stdlib.h>
#include <stdbool.h>
<<<<<<< HEAD
#include "personel.h"
=======
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79

typedef struct list_tag
{
    struct list_tag *next;
    void *data;
} LIST;

<<<<<<< HEAD
LIST ** addNode(LIST **tail, void *data);
int isEmpty(LIST *head);
bool isLastElement(LIST **tail, LIST **n);
void *removeNode(LIST ***tail, LIST **n);
LIST **findNode(LIST **head, void *obj, bool (*compare)(void *, void *));
void deleteList(LIST ** head, void (*deleteData)(void *));
=======
void addNode(LIST ***tail, void *data);
int isEmpty(LIST *head);
bool isLastElement(LIST **tail, LIST **n);
void *removeNode(LIST **tail, LIST **n);
LIST **findNode(LIST *head, void *obj, bool (*compare)(void *, void *));
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79

#endif //LINKED_LIST_LIST_H
