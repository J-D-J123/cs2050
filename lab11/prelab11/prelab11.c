#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Person {
    char firstName[50];
    char lastName[50];
    int socialSecurity;
};

typedef struct _Person Person;

typedef int (*COMPAREFUNCTION)(void *, void *);
typedef void (*SWAPFUNCTION)(void *, void *);

// Generic Bubble Sort
void BubbleSort(void *array, int n, int elementsize, COMPAREFUNCTION compare, SWAPFUNCTION swap) {
    char *arr = (char *)array; 

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            void *elem1 = arr + j * elementsize;
            void *elem2 = arr + (j + 1) * elementsize;

            if (compare(elem1, elem2) > 0) {
                swap(elem1, elem2);
            }
        }
    }
}

// void BubbleSortRecursive(void *array, int n, int elementsize, COMPAREFUNCTION compare, SWAPFUNCTION swap) {
//     if (n == 1) {
//         return; // Base case: done sorting
//     }

//     char *arr = (char *)array;

//     // One pass to move the largest element to the end
//     for (int i = 0; i < n - 1; i++) {
//         void *elem1 = arr + i * elementsize;
//         void *elem2 = arr + (i + 1) * elementsize;

//         if (compare(elem1, elem2) > 0) {
//             swap(elem1, elem2);
//         }
//     }

//     // Recursively sort the first n-1 elements
//     BubbleSortRecursive(array, n - 1, elementsize, compare, swap);
// }



// Compare Persons by socialSecurity
int ComparePerson(void *a, void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return p1->socialSecurity - p2->socialSecurity;
}


// Swap two Persons
void SwapPerson(void *a, void *b) {
    Person temp = *(Person *)a;
    *(Person *)a = *(Person *)b;
    *(Person *)b = temp;
}

// Compare two integers
int CompareInt(void *a, void *b) {
    int int1 = *(int *)a;
    int int2 = *(int *)b;
    return int1 - int2;
}

// Swap two integers
void SwapInt(void *a, void *b) {
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

// Print an array of Persons
void PrintPersons(Person *persons, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s (%d)\n", persons[i].firstName, persons[i].lastName, persons[i].socialSecurity);
    }
}

// Print an array of integers
void PrintInts(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void) {
    Person persons[] = {
        {"Jim", "Ries", 1234},
        {"Jim", "Jones", 1111},
        {"Laura", "Ries", 2222},
        {"Joey", "Johnson", 5555},
        {"Clara", "Johnson", 6666},
    };

    printf("Before:\n");
    PrintPersons(persons, sizeof(persons) / sizeof(persons[0]));

    BubbleSort(persons, sizeof(persons) / sizeof(persons[0]), sizeof(persons[0]), ComparePerson, SwapPerson);

    printf("\nAfter:\n");
    PrintPersons(persons, sizeof(persons) / sizeof(persons[0]));

    int a[] = {99, 7, 15, 12, 1, 207, 14};

    printf("\nBefore:\n");
    PrintInts(a, sizeof(a) / sizeof(a[0]));

    BubbleSort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), CompareInt, SwapInt);

    printf("\nAfter:\n");
    PrintInts(a, sizeof(a) / sizeof(a[0]));

    return 0;
}
