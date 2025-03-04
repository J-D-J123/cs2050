#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node {
int data;
Node *next;
};
Node * initList();
Node * insertAtTail(Node *head, int data, int *error);
Node * removeFromHead(Node *head, int *data);
void printList(Node *head);
int listContains(Node *head, int data);
void freeList(Node *head);
