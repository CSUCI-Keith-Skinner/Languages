#include "list.h"

<<<<<<< HEAD
LIST ** addNode(LIST **tail, void *data)
{
    LIST * node = (LIST*)calloc(1, sizeof(LIST));
    node->data = data;
    *tail = node;
    tail = &(node->next);
	return tail;
=======
void addNode(LIST ***tail, void *data)
{
    LIST * node = (LIST*)calloc(1, sizeof(LIST));
    node->data = data;

    **tail = node;
    *tail = &(node->next);
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
}

int isEmpty(LIST *head) {
    return head == NULL;
}

bool isLastElement(LIST **tail, LIST **n) {
    return *tail == (**n).next;
}


<<<<<<< HEAD
void *removeNode(LIST ***tail, LIST **n)
{
    void *data = NULL;
    if (n && *n) {
        if (isLastElement(*tail, n))
            *tail = n;
=======
void *removeNode(LIST **tail, LIST **n)
{
    void *data = NULL;
    if (n) {
        if (isLastElement(tail, n))
            tail = n;
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79

        LIST *temp = *n;
        data = temp->data;
        *n = temp->next;
        free(temp);
    }
    return data;
}

<<<<<<< HEAD
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
=======
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
>>>>>>> 181e6fdbcd2c7fe97a43bef927968bec50327a79
}
