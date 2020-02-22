/**
* Name: Keith Skinner
* Lab: Lab 2 Personnel Records
* Date: 09/25/2018
**/

#include "list.h"
#include <stdbool.h>


void add(LIST **head, LIST **tail, void *data)
{
    //list is empty.
    if (*tail == NULL) {
        *head = *tail = (LIST *) malloc(sizeof(LIST));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    //list is not empty
    else {
        (*tail)->next = (LIST *) malloc(sizeof(LIST));
        *tail = (*tail)->next;
        (*tail)->data = data;
        (*tail)->next = NULL;
    }
}


void clearIteratively(LIST **head, LIST **tail)
{
    //list is empty :. nothing to do.
    if (*head == NULL)
        return;

    LIST *currNode = *head;
    LIST *nextNode = NULL;
    do {
        nextNode = currNode->next;

        //free data and node
        if (currNode->data != NULL)
            free(currNode->data);
        free(currNode);

        //iterate to next node
        currNode = nextNode;
    } while (currNode != NULL);

    *head = NULL;
    *tail = NULL;
}


void clearRecursively(LIST **currNode, LIST **tail)
{
    //list empty nothing to do.
    if (*currNode == NULL)
        return;

    LIST *nextNode;
    // TODO - DONE - Complete this function
    nextNode = (*currNode)->next;

    //free node and data
    if((*currNode)->data != NULL)
        free((*currNode)->data);
    free(*currNode);

    //iterate to next node
    clearRecursively(&nextNode, tail);

    *currNode = NULL;
    *tail = NULL;
}


void delete(LIST **head, LIST **tail, void *data, bool compare(void*, void*))
{
    //Nothing to do
    if (*head == NULL)
        return;

    //Nothing to find
    if (data == NULL)
        return;

    //Head is what we're looking for.
    if (compare(data, (*head)->data)) {

        //Remove and increment head of the list
        LIST *newHead = (*head)->next;
        free((*head)->data);
        free(*head);
        *head = newHead;

        //List is now empty
        if (*head == NULL)
            *tail = NULL;
        return;
    }


    LIST *prevNode, *currNode;
    prevNode = (*head);
    currNode = (*head)->next;
    while (currNode != NULL) {
        // TODO - DONE - Complete this function
        //found node
        if (compare(data, currNode->data)) {
            //remove currNode from list
            prevNode->next = currNode->next;
            //free currNode and data
            free(currNode->data);
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}