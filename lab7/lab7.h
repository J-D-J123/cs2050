#ifndef _LAB7_H
#define _LAB7_H
typedef struct _Stack Stack;
// O(1)
Stack * initStack();
// O(1)
int getSize(Stack * s);
// O(1)
void * peekStack(Stack * s);
// O(1)
int pushStack(Stack * s, void *data);
// O(1)
void * popStack(Stack * s);
// O(n)
int stackContains(Stack * s, void *data);
// O(n)
void freeStack(Stack * s);
#endif
