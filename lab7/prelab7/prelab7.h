#ifndef PRELAB7_H
#define PRELAB7_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    void* age; 
    struct Person *next; 
} Person; 

typedef struct _Queue{
    Person *front;
    Person *tail; 
    int size;
} Queue;

/* This function returns the error code from the most
recently executed queue operation. 0 implies success,
1 implies out-of-memory error. Some functions may
document additional error conditions. NOTE: All
queue functions assign an error code. */
int getQueueErrorCode(Queue *); 

/* This function returns an initialized Queue variable.
Every queue variable must be initialized before
applying subsequent queue functions. */
Queue * queueInit(); 

/* This function enqueues an object into the queue.
For convenience, error code is returned directly
(and also can be obtained via getQueueErrorCode) */
int enqueue(void *, Queue *); 

/* This function performs dequeue and returns
object at front of queue. NULL is returned
if queue is empty and error code is set to 2.
NOTE: User should check error code if null
objects are permitted in the queue. */
void * dequeue(Queue *); 

/* This function returns the number of objects
in the queue. */
int getQueueSize(Queue *); 

/* This function uninitializes a queue and frees all
memory associated with it. NOTE: value of Queue
variable is undefined after this function is
applied, i.e., it should not be used unless
initialized again using queueInit. */
void freeQueue(Queue *); 

#endif // PRELAB7_H
