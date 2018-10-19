/**
* Name: Keith Skinner
* Lab: Lab 2 Personnel Records
* Date: 09/25/2018
**/

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list
{
    void *data;
    struct list *next;
} LIST;

//Add a new node to the end of the list.
//  the node's data is data.
void add(LIST **head, LIST **tail, void *data);

//Clear the contents of the list and remove all the nodes.
//  uses an iterative algorithm
void clearIteratively(LIST **head, LIST **tail);

//Clear the contents of the list and remove all the nodes.
//  uses a recursive algorithm
void clearRecursively(LIST **head, LIST **tail);

//finds and deletes a specific data in the database
//  compare is a function that takes data as first argument and some LIST.data as second argument
void delete(LIST **head, LIST **tail, void *data, bool compare(void*, void*));

#endif /* LIST_H_ */
