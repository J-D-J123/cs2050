/**
* Author:       J-D-J123
* File:         lab5.c
* Class:        cs2050 
* Date:         2/28/2025
* Desc:         creates a linkedList with basic creation methods 
*
*/

#include "lab5.h"

/**
* the function initList makes the list and returns a empty list pointer 
*/
Node * initList() {

    Node * p = malloc(sizeof(Node)); 

    if(p) {
        p->next = NULL; 

        return p; 
    }
    return (Node*)NULL; 
}

/**
* the method insertAtTail inserts a new node at the end of the list 
*   sets error to 0 on success and 1 on failure 
*/
Node * insertAtTail(Node *head, int data, int *error) {

    // printf("insert at tail\n");
    // basic NULL checking 
    if(head == NULL || error == NULL) {
        *(error) = 1; 
        // printf("returning NULL"); 
        return (Node*)NULL;
    }

    Node * p = malloc(sizeof(Node)); 

    if(p) {

        // working and no error 
        *(error) = 0; 

        p->data = data; 
        p->next = NULL;

        printf("attempting to go through array\n");

        // looping through the list with temp Node*
        Node * temp = head; 

        while(temp != NULL) {
            //printf("count=%d", count); 
            if(temp->next == NULL) {
                temp->next = p; 
                head = temp; 
                break; 

            } else {
                temp = temp->next; 
            }            
        }
    }
    return head; 
}

/**
* takes list pointer and int pointer removes the data return NULL if empty
*/
Node * removeFromHead(Node *head, int *data) {

    // NULL test cases 
    if(head == NULL || data == NULL) {
        return (Node*)NULL;
    }

    Node * temp = head;
    Node * output;

    // first store the data of the head 
    *(data) = head->data;

    // get rid of the first Node 
    output = temp->next;  

    // increase temp
    temp = temp->next; 

    // remove the Node 
    while(temp != NULL) {

        output = temp; 
        temp = temp->next; 
    }

    return output; 
}

// print from head to tail
void printList(Node *head) {

    if(head == NULL) {
        return; 
    }

    Node * current = head; 
    while(current != NULL) {

        printf("%d, ", current->data); 
        current = current->next; 
    }
    printf("\n");
}


int listContains(Node *head, int data) {

    if(head == NULL) {

        // error occurs 
        return 0; 
    }

    Node * temp = head; 

    printf("going through\n");
    while(temp != NULL) {

        if(temp->data == data) {
            // return 1 if contains integer
            return 1; 
        } else {
            temp = temp->next; 
        }
    }

    // else not found so return false
    return 0; 
}

// free LinkedList 
void freeList(Node *head) {

    // basic NULL check cases 
    if(head == NULL) {
        return; 
    }

    Node * current = head; 
    Node * next; 

    while(current != NULL) {
        next = current->next; 
        free(current); 
        current = next; 
    }

    head = NULL;
    return; 
} // end of lab5.c
