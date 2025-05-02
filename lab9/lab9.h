
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
unsigned int trackingNumber;
float deliveryDistance;
unsigned short weight;
} Package;
// 1.1 createArray
void * createArray(int arraySize, int elementSize);
// 1.2 arraySize
int arraySize(void *array);
// 1.4 comparePackages
int comparePackages(Package *a, Package *b);
// 1.4 findPackage (binary search using recursion)
int findPackage(Package *array, Package *query);
// helper function for findPackage()
int binarySearch(Package *array, Package *query, int low, int high);
// 1.5 destroyArray
void destroyArray(void *array);
