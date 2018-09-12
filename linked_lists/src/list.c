#include "list.h"

void addNode(LIST ***tail, void *data)
{
    LIST * node = (LIST*)calloc(1, sizeof(LIST));
    node->data = data;

    **tail = node;
    *tail = &(node->next);
}

int isEmpty(LIST *head) {
    return head == NULL;
}

bool isLastElement(LIST **tail, LIST **n) {
    return *tail == (**n).next;
}


void *removeNode(LIST **tail, LIST **n)
{
    void *data = NULL;
    if (n) {
        if (isLastElement(tail, n))
            tail = n;

        LIST *temp = *n;
        data = temp->data;
        *n = temp->next;
        free(temp);
    }
    return data;
}

LIST **findNode(LIST *head, void *obj, bool (*compare)(void *, void *))
{
    LIST ** found = NULL;
    if (!isEmpty(head)) {
        LIST ** iter = &head;
        while (found == NULL && *iter != NULL) {
            if (compare(obj, (**iter).data))
                found = iter;
            iter = &((**iter).next);
        }
    }
    return found;
}
