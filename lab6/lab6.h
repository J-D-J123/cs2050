#ifndef _LAB6_H
#define _LAB6_H
// Types
struct _Node {
struct _Node *next;
void *data;
};
typedef struct _Node Node;
int makeList(Node **list);
int getSize(Node *list);
void * getAtIndex(Node *list, int index);
int insertAtTail(Node *list, void *data);
void * removeFromHead(Node *list);
void freeList(Node **list);
#endif
