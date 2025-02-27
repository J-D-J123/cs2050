//*************************************************************
// Author:      j-d-j123
// Date:        2/27/2024
// File:        prelab5.c
// Desc:        LinkedList data structure in C 
//                 has structure and method declarations all in 
//                 this file prelab5.c
//*************************************************************

#include <stdio.h>
#include <stdlib.h>

// Define ANSI color codes
#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct linkedListStruct {
        int object;
        struct linkedListStruct* next;
    } LinkedList;
    
/**
 * This function returns an empty LinkedList object, i.e., this must be called before operations
 *  are performed on the list. The parameter is a reference to an error code. 0 signifies the
 *  operation was performed correctly, 1 means there was insufficient memory available to
 *  initialize the linked list.
 */
LinkedList* initializeLinkedList(int *); 

/**
 * This function inserts the int object of the first parameter at the head of the linked list. The
 *  last parameter is an error code (0 implies success, 1 implies insufficient memory). Returns
 *  pointer to updated list if there is no error; otherwise returns the given list without change.
 */
LinkedList* insertAtHead(int, LinkedList*, int*); 


LinkedList* freeLinkedList(LinkedList*); 
int getAtIndex(int, LinkedList*); 
int getLinkedListLength(LinkedList*); 

LinkedList* initializeLinkedList(int *errorCode) {

    // check for NULL input 
    if(errorCode == NULL) {

        // failed so no error code but just return instead
        return (LinkedList*)NULL;
    }

    // allocate memory for linkedList
    LinkedList* list = malloc(sizeof(LinkedList)); 
    if(list) {
        // 1 on correctly 
        *(errorCode) = 0; 
        list->next = NULL;
        list->object = 0;

        return list; 

    } else {

        // failed again 
        *(errorCode) = 1; 
        return (LinkedList*)NULL; 
    }

}

/**
 * first @param obj is the object 
 * second @param list is the LinkedList
 * third @param error is the error code 
 */
LinkedList* insertAtHead(int obj, LinkedList* list, int* error) {

    // NULL test cases 
    if(list == NULL) {
        *(error) = 1; 
        return NULL; 
    }

    // allocate memory for new node
    LinkedList * newNode = malloc(sizeof(LinkedList)); 

    if(newNode) {

        // 0 on correctly
        *(error) = 0;

        // store object in head 
        newNode->object = obj; 
        newNode->next   = list; 

        // return new list
        return newNode;
    } else {
        // failed again 
        *(error) = 1; 
        return NULL; 
    }
}

int getLinkedListLength(LinkedList* list) {

    // NULL checker 
    if(list == NULL) {
        return 0; 
    }

    // count the number of elements in the list
    int count = 0;
    while(list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}
/**
 * This function frees the memory allocated for the linked list. It returns NULL to signify that
 *  the list has been freed. 
 */
LinkedList* freeLinkedList(LinkedList* list) {

    if(list == NULL) {
        return (LinkedList*)NULL;
    }

    LinkedList* current = list; 
    LinkedList* next; 

    while(current != NULL) {
        next = current->next; 
        free(current); 
        current = next; 
    }

    return NULL; 
}

int getAtIndex(int target, LinkedList* list) {

    if(list == NULL) {
        return 0; 
    }

    // loop through the list and get the index head is 1
    for(int i = 0; list != NULL; i++) {
        if(i == target-1) {
            return list->object; 
        } else {
            list = list->next; 
        }
    }
    return 0; 
    
}

int main() {

    int makeError = 0; 

    LinkedList *list = initializeLinkedList(&makeError); 
    list = insertAtHead(1, list, &makeError);
    list = insertAtHead(2, list, &makeError);
    list = insertAtHead(3, list, &makeError);
    list = insertAtHead(4, list, &makeError);
    list = insertAtHead(5, list, &makeError);
    list = insertAtHead(6, list, &makeError);
    list = insertAtHead(7, list, &makeError);

    // initializeLinkedList(NULL); 

    // if(makeError == 1) {
    //     printf(RED "failed initializeLinkedList\n" RESET);
    // } else {
    //     printf(GREEN "passed initializeLinkedList\n" RESET);
    // }

    // test insertAtHead
    // int insertError = 0;

    // list = insertAtHead(1, list, &insertError);
    // if(insertError == 0) {
    //     printf(GREEN "passed InsertAtHead\n" RESET);
    // } else {
    //     printf(RED "failed InsertAtHead\n" RESET);
    // }

    // test getsize
    // int size = getLinkedListLength(list);
    // printf("size" " = %d\n", size);

    // for(int i = 0; i < size; i++) {

    //     if(list == NULL) {
    //         printf(RED "failed to get list\n" RESET);
    //         break;
    //     } else {

    //         printf("   %d. list[%d] = %d\n", i+1, i, list->object);
    //         list = list->next;
    //     }
    // }

    // print out the list
    LinkedList* temp = list; // Store the head pointer

    printf("size = %d\n", getLinkedListLength(temp));
    
    for(int i = 0; temp != NULL; i++) {
        printf("   %d. list[%d] = %d\n", i+1, i, temp->object);
        temp = temp->next;
    }

    // test get at index
    int index = 3; // Example index to get
    int valueAtIndex = getAtIndex(index, list);
    if(valueAtIndex != 0) {
        printf("Value at index %d: %d\n", index, valueAtIndex);
    } else {
        printf(RED "failed getAtIndex\n" RESET);
    }
    

    // test freeLinkedList
    list = freeLinkedList(list);
    if(list == NULL) {
        printf(GREEN "passed freeLinkedList\n" RESET);
    } else {
        printf(RED "failed freeLinkedList\n" RESET);
    }



}

