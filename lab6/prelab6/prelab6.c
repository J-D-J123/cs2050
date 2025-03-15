// LinkedList* initializeLinkedList(int*);
// LinkedList* insertAtHead(int, LinkedList*, int*);
// int getAtIndex(int, LinkedList*);
// int getLinkedListLength(LinkedList*);
// LinkedList * freeLinkedList(LinkedList*);

#include "prelab6.h" 
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


// initalizes the linkedList with the integer object 
// returns the head of the list 
LinkedList * initializeLinkedList(int * obj) {

    if(obj == NULL) {return (LinkedList*)NULL;}

    LinkedList * list = malloc(sizeof(LinkedList)); 

    if(list) {
        list->next   = NULL; 

        return list; 
    }

    return (LinkedList*)NULL; 
}

// void printArrayList(LinkedList * list) {

//     if(list != NULL) {

//         LinkedList * temp = list; 
        
//         while(temp != NULL) {
//             printf("%d ", temp->object); 
//             temp = temp->next; 
//         }
//         printf("\n");
//     }
// }

LinkedList * freeLinkedList(LinkedList* list) {

    if(list != NULL) {

        LinkedList * current = list; 
        LinkedList * next; 


        while(current!=NULL) {
            next = current->next; 
            free(current); 
            current = next; 
        }
        current = NULL; 
        return current;  
    }
    return (LinkedList*)NULL; 
}

int getLinkedListLength(LinkedList* list) {

    int count = 0; 

    if(list != NULL) {

        LinkedList * current = list; 

        while(current != NULL) {

            current = current->next; 
            count++; 
        }
        return count; 
    }

    return count; 
}

// LinkedList* insertAtHead(int obj, LinkedList* list, int* error) {

//     if(list == NULL || error == NULL || obj (int*)NULL) {

//         return (LinkedList*)NULL; 
//     }

//     LinkedList 
// }

int main() {

    int num     = 5; 
    int * obj   = &num;  

    LinkedList * list = initializeLinkedList(obj); 


    printArrayList(list); 

    printf("Length: %d\n", getLinkedListLength(list)); 

    freeLinkedList(list); 


    //----------------------------------------------//
    // NULL Test Values // 
    LinkedList * list2 = initializeLinkedList(NULL); 
    printArrayList(list2); 
    freeLinkedList(list2); 

    return 0; 
}
