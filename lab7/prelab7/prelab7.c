#include "prelab7.h"

Queue * queueInit() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) {
        return NULL;
    }
    q->front = q->tail = NULL;
    q->size = 0;
    return q;
}

int enqueue(void *age, Queue *q) {
    if (!q || !age) {
        return 1;
    }
    
    Person *newPerson = (Person *)malloc(sizeof(Person));
    if (!newPerson) {
        return 1;
    }
    
    newPerson->age = age;
    newPerson->next = NULL;
    
    if (q->tail) {
        q->tail->next = newPerson;
    } else {
        q->front = newPerson;
    }
    q->tail = newPerson;
    q->size++;
    return 0;
}

void * dequeue(Queue *q) {
    if (!q || !q->front) {
        return NULL;
    }
    
    Person *removedPerson = q->front;
    void *age = removedPerson->age;
    q->front = removedPerson->next;
    if (!q->front) {
        q->tail = NULL;
    }
    
    free(removedPerson);
    q->size--;
    return age;
}

int getQueueSize(Queue *q) {
    return q ? q->size : 0;
}

void freeQueue(Queue *q) {
    if (!q) return;
    
    Person *current = q->front;
    while (current) {
        Person *next = current->next;
        free(current);
        current = next;
    }
    
    free(q);
} // end of prelab7.c
