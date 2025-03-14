#include "prelab7.h"
#include <stdio.h>
#include <stdlib.h>
#include "prelab7.c"

void printQueueState(Queue *q) {
    printf("Current queue size: %d\n", getQueueSize(q));
}

void testQueue() {
    Queue *q = queueInit();
    if (!q) {
        printf("Queue initialization failed!\n");
        return;
    }
    printf("Queue initialized successfully.\n");

    // Test random enqueue operations with integers
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    enqueue(&a, q);
    enqueue(&b, q);
    enqueue(&c, q);
    printf("\nEnqueued values: %d, %d, %d\n", a, b, c);
    printQueueState(q);

    // Test dequeuing and checking results
    int *val = (int *)dequeue(q);
    if (val) {
        printf("Dequeued value: %d\n", *val);
    }
    printQueueState(q);

    enqueue(&d, q);
    enqueue(&e, q);
    printf("\nEnqueued values: %d, %d\n", d, e);
    printQueueState(q);

    // Test dequeuing all elements
    val = (int *)dequeue(q);
    if (val) {
        printf("Dequeued value: %d\n", *val);
    }
    printQueueState(q);

    val = (int *)dequeue(q);
    if (val) {
        printf("Dequeued value: %d\n", *val);
    }
    printQueueState(q);

    val = (int *)dequeue(q);
    if (val) {
        printf("Dequeued value: %d\n", *val);
    }
    printQueueState(q);

    val = (int *)dequeue(q);
    if (val) {
        printf("Dequeued value: %d\n", *val);
    } else {
        printf("Dequeue failed! Queue is empty.\n");
    }

    // Test edge cases with an empty queue
    val = (int *)dequeue(q);
    if (val) {
        printf("Dequeued value: %d\n", *val);
    } else {
        printf("Dequeue failed! Queue is empty.\n");
    }

    freeQueue(q);
    printf("Queue freed successfully.\n");
}

void testRandomCases(int numTests) {
    srand(time(NULL)); // Seed for randomization
    for (int i = 0; i < numTests; i++) {
        printf("\n--- Test Case %d ---\n", i + 1);
        testQueue();
    }
}

int main() {
    // Run a series of random tests
    testRandomCases(5); // Test with 5 random cases

    return 0;
} // end of tester.c 
