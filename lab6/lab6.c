/**
* Name:     j-d-j123
* Class:    cs2050
* Date:     3/7/2025 
* File:     lab6.c 
* Desc:     make a linkedList but use the "dummy" Node 
*               int makeList(Node **list);
*               int getSize(Node *list);
*               void * getAtIndex(Node *list, int index);
*               int insertAtTail(Node *list, void *data);
*               void * removeFromHead(Node *list);
*               void freeList(Node **list);
*/

#include "lab6.h"
#include <stdlib.h>

/**
* makes the list aka the dummy node 
*/
int makeList(Node **list) {

    if(list == NULL ) {
        return 1; 
    }

    // make the first "dummy" node 
    *list = (Node*)malloc(sizeof(Node)); 

    if(*list == NULL) {
        // if fails 
        return 1; 
    }

    if(list) {

        // 0 if successful 
        (*list)->next = NULL; 
    }

    return 0; 
}

/**
* the getSize function gets the size of the LinkedList 
*   goes through all Nodes 
*/
int getSize(Node * list) {

    if(list == NULL) {

        // empty list so return 0 
        return 0;
    }

    // start at 0 so we don't count the dummy node 
    int size = 0; 

    Node * current = list; 
    while(current != NULL && current->next != NULL) {
 
        current = current->next; 
        size++;
    }

    return size; 
}

/**
* the getAtIndex returns the Node at that index 
*/
void * getAtIndex(Node * list, int index) {

    if(list == NULL || (index < 0 || getSize(list) <= index)) {
        return NULL; 
    }

    Node * current = list->next; 

    // loop through the list and get the index head is 1
    for(int i = 0; i < index; i++) {
        current = current->next; 
    }
    return current->data; 

}

/**
* the insertAtTail function inserts a newNode at the end of the LinkedList aka (tail)
*/
int insertAtTail(Node *list, void * data) {

    // NULL tests 
    if(list == NULL || data == NULL) {
        return 1; 
    }

    // Create a new node for the data.
    Node *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = (int*)data;
        newNode->next = NULL;

        // Traverse starting from the dummy node.
        Node *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        // Append the new node.
        current->next = newNode;
        return 0; 
    }

    // free if malloc fails 
    free(newNode); 
    return 1; 
}

void * removeFromHead(Node *head) {

    if(head == NULL) {
        return NULL; 
    }

    Node * current = head->next; 

    // list is empty returning NULL 
    if(current == NULL) {
        return NULL; 
    }

    // store the data so we can return it 
    void * data = current->data; 

    // move the starting head point location 
    head->next  = current->next; 

    free(current); 

    return data; 
}

/**
* the freeList takes the Node LinkedList and frees it 
*/
void freeList(Node **list) {

    if(list == NULL) {
        return; 
    }

    Node * current = *(list);
    Node * next; 

    while(current != NULL) {
        next = current->next; 
        free(current); 
        current = next; 
    }
    *(list) = NULL; 
} // end of lab6.c 
