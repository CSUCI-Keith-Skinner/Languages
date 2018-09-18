#include "list.h"

LIST ** addNode(LIST **tail, void *data)
{
    LIST * node = (LIST*)calloc(1, sizeof(LIST));
    node->data = data;
    *tail = node;
    tail = &(node->next);
	return tail;
}

int isEmpty(LIST *head) {
    return head == NULL;
}

bool isLastElement(LIST **tail, LIST **n) {
    return *tail == (**n).next;
}


void *removeNode(LIST ***tail, LIST **n)
{
    void *data = NULL;
    if (n && *n) {
        if (isLastElement(*tail, n))
            *tail = n;

        LIST *temp = *n;
        data = temp->data;
        *n = temp->next;
        free(temp);
    }
    return data;
}

LIST ** findNode(LIST **head, void *obj, bool (*compare)(void *, void *))
{
	char * cobj = (char *)obj;

	LIST **iter = head;
	bool found = false;
    if (!isEmpty(*head)) {
        while (!found && *iter != NULL) {

			PERSON * data = (**iter).data;

			if (compare(obj, (**iter).data))
				found = true;
            else iter = &((**iter).next);
        }
    }
	return (found) ? iter : NULL;
}

void deleteList(LIST ** head, void(*deleteData)(void *))
{
	while (!isEmpty(*head)) {
		LIST *temp = *head;
		*head = temp->next;
		deleteData(temp->data);
		free(temp);
	}
	*head = NULL;
}
