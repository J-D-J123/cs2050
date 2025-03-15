/**
* Name:     J-D-J123
* Class:    cs2050
* Date:     3/14/2025 
* File:     lab6.c 
* Desc:     make a stacked linked List with these methods 
*               Stack * initStack(); 
*               int getSize(Stack * s); 
*               void * peekStack(Stack * s); 
*               int pushStack(Stack * s, void * data); 
*               void * popStack(Stack * s); 
*               int stackContains(Stack * s, void * data); 
*               void freeStack(Stack * s); 
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lab7.h"

// Need a struct for the data of each Node 
typedef struct _Node {
    void * data; 
    struct _Node * next; 
} Node; 

typedef struct _Stack {
    Node * top; 

    // stores the size of the list 
    // called from the getSize(Stack * s) 
    int size; 
} Stack; 

// ------------------------------------------------------------------// 
//                          CODE IS BELOW                            // 
// ------------------------------------------------------------------// 

/**
* the initStack function returns a Stack if the initalization fails, you
*   return NULL
*/
Stack * initStack() {

    Stack * theStack = (Stack *)malloc(sizeof(Stack)); 

    if(theStack) {

        theStack->top = NULL; 
        theStack->size = 0; 
        return theStack; 
    }
    return NULL; 
}

/**
* the getSize function takes a stack, and returns 
*   the number of elements on the stack
*/
int getSize(Stack * s) {

    int size = 0; 

    if(s == NULL) {

        return size; 
    }

    Node * current = s->top; 

    while(current != NULL)  {
        size++; 
        current = current->next; 
    }

    s->size = size; // confusing backend but user won't see it
    return size; 
}

/**
* the peek stack takes a stack and returns the element at top of the stack 
*   WITHOUT REMOVING IT 
*/
void * peekStack(Stack * s) {

    if(s != NULL) {

        Node * current = s->top; 

        if(current == NULL) {
            return NULL; 
        } else {

            // set next to NULL so the user cannot access it 
            return current->data; 
        }
    }
    return NULL; 
}

/**
* This pushStack function takes a stack, as well as a data item, 
*   it will push the item onto the top of the stack, 
*   then return 0 if insertion was successful or 1 if it was not 
*/
int pushStack(Stack * s, void * data) {

    if(s == NULL || data == NULL) {
        return 1; 
    }

    Node * newNode = (Node *)malloc(sizeof(Node)); 

    if(newNode) {
        newNode->next = NULL; 
        newNode->data = data; 

        // put on top 
        if(s->top) {

            newNode->next = s->top; 
            s->top        = newNode; 
            return 0; 
        } else {

            // if top next is NULL 
            s->top        = newNode; 
            return 0; 
        }
    }

    // else if random error return 1 
    return 1; 
}


/**
* This function takes a stack, and pops the data item from the top 
*   of the stack. It returns the item popped from the stack, 
*   or NULL if the stack is empty.
*/
void * popStack(Stack * s) {

    if(s == NULL) {
        return NULL; 
    }

    Node * current = s->top; 

    if(current == NULL) {
        return NULL; 
    } else {

        Node * removedNode = current; 
        void * removeNodeData = current->data; 

        free(removedNode); 

        current = current->next; 

        s->top = current; 
        return removeNodeData; 
    }

    // random error case 
    return NULL; 
}

/**
* This function takes a stack, as well as a data item. It returns 1 
*   if the given data exists on the
*   stack, or 0 if it does not.
*/
int stackContains(Stack * s, void * data) {

    if (s == NULL || data == NULL) {
        return 0; 
    }

    if(s) {

        Node * current = s->top; 

        while(current != NULL) {

            if(current->data == data) {
                return 1; 
            }
            current = current->next; 
        }
    }

    // does not exist 
    return 0; 
}

/**
* This function takes a stack, and frees all memory allocated to the stack. 
*   Remember that data which have been inserted onto the stack are 
*   not considered part of the memory allocated to the stack
*/
void freeStack(Stack * s) {

    if(s == NULL) {
        return;
    }

    Node * current = s->top; 

    while(current != NULL) {
        Node * temp = current; 
        current = current->next; 
        free(temp); 
    }

    free(s); 
} // end of lab7.c 
